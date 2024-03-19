#include <REGX52.H>
#include  "LCD1602.h"
#include "Timer0.h"

unsigned char s,m,h;

void main()
{	
	LCD_Init();
	Timer0Init();
	while(1)
		{	
			LCD_ShowString(1,1,"CLOCK");
			LCD_ShowString(1,14,"Jay");
			LCD_ShowChar(2,3,':');
			LCD_ShowChar(2,6,':');
			LCD_ShowNum(2,1,h,2);
			LCD_ShowNum(2,4,m,2);
			LCD_ShowNum(2,7,s,2);
		}
}

void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count;
	TL0 = 0x18;		//低位初值
	TH0 = 0xFC;		//高位初值
	T0Count++;
	if(T0Count>=1000)
	{
		T0Count=0;
		s++;
		if(s==60){m++;s=0;}
		if(m==60){h++;m=0;}
		if(h==24)h=0;
	}
}