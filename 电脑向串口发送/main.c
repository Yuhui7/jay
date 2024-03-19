#include <REGX52.H>
#include  "UART.h"
//#include "Delay.h"


void main()
{	
	UartInit();		//初始化
	
	while(1)
		{	
			
		}
}

void UART_Routine() interrupt 4 //电脑发送给串口
{
	if(RI==1)
	{
		P2=SBUF;
		RI=0;
	}

}