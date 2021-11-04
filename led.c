#include "led.h"

void LED_init()
{
	DDRD |= (1 << LED_BLUE);
}
