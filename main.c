#include <avr/pgmspace.h>

#include "led.h"
#include "serial.h"
#include "timer.h"

void main(void)
{
	timer_init();
	LED_init();

	int counter = 0;

	while (1)
	{
		//Checks for OCF0A flag when timer TCNT0 equals OCR0A (see value timer.c)
		if (TIFR0 & (1 << OCF0A))
		{
			counter++;
			TIFR0 |= (1 << OCF0A); //Clears interrupt flag
			if (counter >= 10)
			{
				PORTD ^= (1 << LED_BLUE); //Toggles LED-pin
				counter = 0;
			}
		}
	}
}