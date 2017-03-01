#include <stdlib.h>
#include "types.h"
#include "Kwp2000Proto.h"
#include "Buffer.h"

extern Buffer buffer;

struct Kwp2000Settings
{
	byte dstAddr;
	byte srcAddr;
} _kwp2000;

static byte calcCrc(byte* msg, unsigned int len)
{	
	byte crc = 0;
	for (int i = 0; i < len; i++)
		crc += msg[i];

	return crc;
}

static int parse(byte pid, byte data[], int len)
{
	switch (pid)
	{
	case 1:
		if (len == 2)
		{
			return data[0] * 100 + data[1]; //example
		}
	default:
		return 0;
	}
}


EcuPacket Kwp2000BuildRequest(unsigned char pid)
{
	EcuPacket packet;
	
	packet.format = 0x80;
	packet.dst = _kwp2000.dstAddr;
	packet.src = _kwp2000.srcAddr;
	packet.len = 2;

	packet.service = 0x21;
	packet.pid = pid;	

	packet.crc = calcCrc((byte*)&packet, 6) ;

	return packet;	
}

EcuValue Process()
{
	EcuValue ecuValue;
	ecuValue.isValid = 0;
	
	const int minBufLen = 8;
	if (buffer.len < minBufLen)
		ecuValue;
	
	int expLen = 5 + buffer.data[3];
	if (buffer.len < expLen)
		ecuValue;
	
	if (buffer.data[2] == _kwp2000.srcAddr)
	{
		ecuValue.service = buffer.data[4];
		ecuValue.pid = buffer.data[5];
		ecuValue.value = parse(ecuValue.pid, buffer.data + 6, buffer.data[3] - 2);
		ecuValue.isValid = 1;
	}
	
	return ecuValue;
}

IEcuProtocol* Kwp2000Proto(byte dstAddr, byte srcAddr)
{
	IEcuProtocol* proto = malloc(sizeof(IEcuProtocol));
	proto->BuildRequest = &Kwp2000BuildRequest;
	proto->Process = &Process;

	_kwp2000.dstAddr = dstAddr;
	_kwp2000.srcAddr = srcAddr;
	
	return proto;
}