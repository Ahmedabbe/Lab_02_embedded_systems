#include "led.h"

void LED_init()
{
	DDRD |= (1 << LED_BLUE);
}

uint8_t simple_ramp(uint8_t *direction, uint8_t *pwmValue)
{
	//Change direction when either min or max values are reached
	if (*pwmValue >= 255 || *pwmValue <= 0)
	{
		*direction *= -1;
	}

	//imcrement or decrement value based on direction
	*pwmValue += *direction;

	//return new value
	return *pwmValue; 
}