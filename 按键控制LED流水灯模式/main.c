#include <REGX52.H>
#include "Timer0.h"
#include "Key.h"
#include "INTRINS.H"


unsigned char KeyNum,count=0;

void main()
{	
	P2=0xFE;
	Timer0Init();
	while(1)
		{
			KeyNum=Key();
			if(KeyNum)
			{	
				count++;
				if(count>=2)count=0;
			}
		}
}
void Timer0_Routine() interrupt 1 
{
	static unsigned int T0Count;
	TL0 = 0x18;		//低位初值
	TH0 = 0xFC;		//高位初值
	T0Count++;		//1毫秒加一次
	if(T0Count>=500)
	{
		T0Count=0;
		if(count==0)
			P2=_crol_(P2,1);
		if(count==1)
			P2=_cror_(P2,1);
	}
}