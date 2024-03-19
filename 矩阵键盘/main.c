#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include "MatrixKey.h"

unsigned char KeyNum;

void main()
{	
	LCD_Init();
	LCD_ShowString(1,4,"MATRIXKEY");
	LCD_ShowString(2,14,"Jay");
	while(1)
	{
		KeyNum=MatrixKey();
		if(KeyNum)
			{	
				LCD_ShowNum(2,8,KeyNum,2);
			}
	}
}
