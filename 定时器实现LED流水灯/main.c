#include <REGX52.H>
#include "Timer0.h"
#include "INTRINS.H"

void main()
{	
	P2=0xFE;
	Timer0Init();
	while(1)
		{

		}
}
void Timer0_Routine() interrupt 1 
{
	static unsigned int T0Count;
	TL0 = 0x18;		//��λ��ֵ
	TH0 = 0xFC;		//��λ��ֵ
	T0Count++;		//1�����һ��
	if(T0Count>=500)
	{
		T0Count=0;
		P2=_crol_(P2,1);
	}
}