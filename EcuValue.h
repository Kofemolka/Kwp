#ifndef ECUVALUE_H
#define ECUVALUE_H

#include "types.h"

typedef struct
{
	byte service;
	byte pid;
	int value;		
	byte isValid;
} EcuValue;

#endif

