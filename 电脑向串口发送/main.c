#include <REGX52.H>
#include  "UART.h"
//#include "Delay.h"


void main()
{	
	UartInit();		//��ʼ��
	
	while(1)
		{	
			
		}
}

void UART_Routine() interrupt 4 //���Է��͸�����
{
	if(RI==1)
	{
		P2=SBUF;
		RI=0;
	}

}