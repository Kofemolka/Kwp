#ifndef BUFFER_H
#define BUFFER_H

#include "types.h"

#define BuffSize 20

typedef struct
{
	byte data[BuffSize];
	int len;
} Buffer;

#endif
