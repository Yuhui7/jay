#include <REGX52.H>

void Delay(unsigned int xms)
{
	unsigned char i, j;
	while(xms--)
	{
		i = 2;
	j = 239;
	do
	{
		while (--j);
	} while (--i);
	}
	
}

void main()
{	
	unsigned char LED=0;//LED=0000 0000
	while(1)
	{
		if(P3_1==0)
		{
			Delay(20);
			while(P3_1==0);
			Delay(20);
			
			LED++;//LED=0000 0001
			P2=~LED;//P2=1111 1110
		}
	}
}