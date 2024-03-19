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
