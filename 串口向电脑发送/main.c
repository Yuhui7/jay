#include <REGX52.H>
#include  "UART.h"
#include "Delay.h"

unsigned char a;

void main()
{	
	UartInit();		//≥ı ºªØ
//	UART_SendByte(0xFE);
	while(1)
		{	
			Delay(500);
			UART_SendByte(a++);
			Delay(500);
		}
}