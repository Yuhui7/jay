#include <REGX52.H>

void Timer0_Init(void)	//1毫秒	
{	
	TMOD &= 0xF0;	//定时器模式 低位清零 高位不变	
	TMOD |= 0x01;	//低位置1 高位不变	
	TL0 = 0x18;		//低位初值
	TH0 = 0xFC;		//高位初值
	TF0 = 0;		//清除TF0标志
	TR0 = 1;	//定时器0开始计时
	ET0=1;
	EA=1;
	PT0=0;
}

/*定时器中断函数模板
void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count;
	TL0 = 0x18;		//低位初值
	TH0 = 0xFC;		//高位初值
	T0Count++;
	if(T0Count>=1000)
	{
		T0Count=0;
	}
}
*/