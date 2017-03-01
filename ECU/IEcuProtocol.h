#ifndef IECUPROTOCOL_H
#define IECUPROTOCOL_H

#include "EcuPacket.h"
#include "EcuValue.h"

typedef struct
{
	EcuPacket (*BuildRequest)(unsigned char pid);
	EcuValue (*Process)();
} IEcuProtocol;

#endif