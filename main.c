#include <avr/pgmspace.h>

#include "led.h"
#include "serial.h"
#include "timer.h"

void main(void)
{
	timer_init();
	timer2_init();
	LED_init();

	uint8_t direction = -1;
	uint8_t pwmValue = 0;

	while (1)
	{
		//Checks for OCF0A flag when timer TCNT0 equals OCR0A (see value timer.c)
		if (TIFR2 & (1 << OCF2A))
		{
			TIFR2 |= (1 << OCF2A); //Clears interrupt flag

			//Set new duty cycle to OCR0A after each pass through
			OCR0A = simple_ramp(&direction, &pwmValue);
		}
	}
}