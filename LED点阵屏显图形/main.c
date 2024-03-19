#include <REGX52.H>
#include "Delay.h"

sbit RCK=P3^5;	//RCLK 锁存
sbit SCK=P3^6;	//SRCLK 上升沿
sbit SER=P3^4;	//SER

void Column(unsigned char Byte)	//位移寄存器控制列
{
	unsigned char i;
	for(i=0;i<8;i++)
		{
			SER=Byte&(0x80>>i);  //分个输送
			SCK=1;
			SCK=0;
		}
		RCK=1;  //输送8位数据 
		RCK=0;
}

void LED_Dianzhenping(unsigned char row,column)
{
	P0=~(0x80>>row);
	Column(column);  //段选
	Delay(1);
	P0=0xFF;  //位选清零
	
}


void main()
{	
	SCK=0;
	RCK=0;
	while(1)
		{
			LED_Dianzhenping(0,0x60);
			LED_Dianzhenping(1,0x90);
			LED_Dianzhenping(2,0x88);
			LED_Dianzhenping(3,0x44);
			LED_Dianzhenping(4,0x88);
			LED_Dianzhenping(5,0x90);
			LED_Dianzhenping(6,0x60);
			LED_Dianzhenping(7,0x60);
		}
}