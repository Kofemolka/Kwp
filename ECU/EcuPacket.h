#ifndef ECUPACKET_H
#define ECUPACKET_H

#include "types.h"

typedef struct
{
	byte format;
	byte dst;
	byte src;
	byte len;
	byte service;
	byte pid;
	byte crc;		
} EcuPacket;

#endif
