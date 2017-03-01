#ifndef ECU_H
#define ECU_H

#include "Variant.h"
#include "types.h"
#include "IEcuProtocol.h"
#include "IEcuLink.h"

typedef struct 
{
	IEcuProtocol* protocol;
	IEcuLink* link;
} ECU; 

void EcuInit();
int EcuRequestPID(byte pid);
int EcuReadPID(byte pid);

void EcuLoop();

#endif


