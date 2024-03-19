#include <REGX52.H>

void UartInit(void)		//4800bps@11.0592MHz ´®¿Ú³õÊ¼»¯
{
	PCON &= 0x7F;	
	SCON = 0x50;	

	TMOD &= 0x0F;		
	TMOD |= 0x20;	
	TL1 = 0xFA;		
	TH1 = 0xFA;		
	ET1 = 0;		
	TR1 = 1;		
}




void UART_SendByte(unsigned char Byte)//·¢ËÍ×Ö·û
{
	SBUF=Byte;	//SUBF´®¿Ú»º´æ¼Ä´æÆ÷
	while(TI==0);
	TI=0;
}