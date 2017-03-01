#include "ECU.h"
#include "Buffer.h"

extern ECU ecu;

Buffer buffer;

int storage[256];

void store(EcuValue ecuValue)
{
	storage[ecuValue.pid] = ecuValue.value;
}

void EcuInit()
{
	buffer.len = 0;
}

int EcuRequestPID(byte pid)
{
	EcuPacket packet = ecu.protocol->BuildRequest(pid);

	for (int i = 0; i < sizeof(packet); i++)
	{
		ecu.link->Send(((byte*)&packet)[i]);
	}
	
	return 0;
}

int EcuReadPID(byte pid)
{
	return storage[pid];	
}

void EcuLoop()
{
	byte cr;
	
	while(ecu.link->Read(&cr) == 0)
	{		    
		if (buffer.len < BuffSize)
		{
			buffer.data[buffer.len++] = cr;
		}
	}
	
	EcuValue ecuValue = ecu.protocol->Process();
	if (ecuValue.isValid)
	{
		store(ecuValue);		
	}
}
