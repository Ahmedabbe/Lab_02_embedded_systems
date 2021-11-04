#include <avr/pgmspace.h>

#include "led.h"
#include "serial.h"
#include "timer.h"

uint8_t simple_ramp(uint8_t *direction, uint8_t *pwmValue);

void main(void)
{
	timer_init();
	LED_init();

	while (1)
	{
		/*
		Setting different output compare values to shift led brightness/duty cycle
		*/
		OCR0A = 50;
		_delay_ms(1000);
		OCR0A = 175;
		_delay_ms(1000);
		OCR0A = 250;
		_delay_ms(1000);
	}
}