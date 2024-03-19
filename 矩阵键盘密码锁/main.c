#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include "MatrixKey.h"

unsigned char KeyNum;
unsigned int Password,count;

void main()
{	
	LCD_Init();
	LCD_ShowString(1,1,"PASSWORD");
	LCD_ShowString(2,14,"Jay");
	while(1)
	{
		KeyNum=MatrixKey();
		if(KeyNum)  //如果按键按下
			{
				if(KeyNum<=10)
					{	
						if(count<4)
						{
							Password*=10;
							Password+=KeyNum%10;
							count++;
						}				
					}		
					LCD_ShowNum(2,1,Password,4);
				if(KeyNum==11)
					if(Password==2345)
						{
							LCD_ShowString(1,14,"OK ");
							count=0;
							Password=0;
							LCD_ShowNum(2,1,Password,4);
							Delay(2000);
							LCD_ShowString(1,14,"   ");
						}
					else
						{
							LCD_ShowString(1,14,"ERR");
							count=0;
							Password=0;
							LCD_ShowNum(2,1,Password,4);
							Delay(2000);
							LCD_ShowString(1,14,"   ");							
						}
				 if(KeyNum==12)
					{
						count=0;
						Password=0;
						LCD_ShowNum(2,1,Password,4);
						Delay(2000);
						LCD_ShowString(1,14,"   ");		
				 
					}
			}
	}
}
