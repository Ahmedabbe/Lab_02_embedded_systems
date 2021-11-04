#include "timer.h"

void timer_init()
{
	/*
	WGMO0-1 bit set high in TCCR0A register activates PWM fast mode

	Set COM0A1 bit activates clear on match(start from bottom), non inverted
	*/

	TCCR0A |= (1 << WGM00) | (1 << WGM01);
	TCCR0A &= ~(1 << WGM02);
	TCCR0A |= (1 << COM0A1);

	//Set prescaler to Clk/64
	TCCR0B |= (1 << CS00) | (1 << CS01);
	TCCR0B &= ~(1 << CS02);
}
