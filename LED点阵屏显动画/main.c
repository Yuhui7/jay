#include <REGX52.H>
#include "Delay.h"
#include "MatrixLED.h"


void main()
{	
	void MatrixLED_Init();
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
