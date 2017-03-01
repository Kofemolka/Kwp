#ifndef IECULINK_H
#define IECULINK_H

typedef struct
{
	int (*Send)(unsigned char byte);
	int (*Read)(unsigned char* byte);
} IEcuLink;

#endif