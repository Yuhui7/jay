#include <REGX52.H>
#include "Delay.h"

sbit RCK=P3^5;	//RCLK ����
sbit SCK=P3^6;	//SRCLK ������
sbit SER=P3^4;	//SER

void Column(unsigned char Byte)	//λ�ƼĴ���������
{
	unsigned char i;
	for(i=0;i<8;i++)
		{
			SER=Byte&(0x80>>i);  //�ָ�����
			SCK=1;
			SCK=0;
		}
		RCK=1;  //����8λ���� 
		RCK=0;
}

void LED_Dianzhenping(unsigned char row,column)
{
	P0=~(0x80>>row);
	Column(column);  //��ѡ
	Delay(1);
	P0=0xFF;  //λѡ����
	
}
