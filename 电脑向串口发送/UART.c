#include <REGX52.H>

void UartInit(void)		//4800bps@11.0592MHz ���ڳ�ʼ��
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




void UART_SendByte(unsigned char Byte)//���ڷ����ַ�������
{
	SBUF=Byte;	//SUBF���ڻ���Ĵ���
	while(TI==0);
	TI=0;
}

/*���ں����ж�ģ��
void UART_Routine() interrupt 4 //���Է��͸�����
{
	if(RI==1)
	{

		RI=0;
	}

}
*/