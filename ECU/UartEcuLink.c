#include <stdlib.h>
#include "app_uart.h"
#include "types.h"
#include "UartEcuLink.h"

static int Send(byte byte)
{
	return app_uart_put(byte);
}

static int Read(byte* byte)
{	
	return app_uart_get(byte);
}

IEcuLink* UartEcuLink()
{
	IEcuLink* link = malloc(sizeof(IEcuLink));
	link->Send = &Send;
	link->Read = &Read;
	
	return link;
}

