#include <REGX52.H>
#include "Delay.h"
#include "Nixie.h"
void main()
{
	while(1)
	{
		nixie(1,2);
		nixie(2,0);
		nixie(3,2);
		nixie(4,4);
	}
}