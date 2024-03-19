#include <REGX52.H>

void UartInit(void)		//4800bps@11.0592MHz 串口初始化
{
	PCON &= 0x7F;	
	SCON = 0x50;	

	TMOD &= 0x0F;		
	TMOD |= 0x20;	
	TL1 = 0xFA;		
	TH1 = 0xFA;		
	ET1 = 0;		
	TR1 = 1;		
	EA=1;
	ES=1;
}




void UART_SendByte(unsigned char Byte)//串口发送字符给电脑
{
	SBUF=Byte;	//SUBF串口缓存寄存器
	while(TI==0);
	TI=0;
}

/*串口函数中断模板
void UART_Routine() interrupt 4 //电脑发送给串口
{
	if(RI==1)
	{

		RI=0;
	}

}
*/