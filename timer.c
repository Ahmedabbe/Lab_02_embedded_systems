#include "timer.h"

void timer2_init()
{
	//Enable CTC timer2
	TCCR2A &= ~(1 << WGM20);
	TCCR2A |= (1 << WGM21);
	TCCR2B &= ~(1 << WGM22);

	//Set prescaler to Clk/1024
	TCCR2B |= (1 << CS22) | (1 << CS21) | (1 << CS20);

	//Output compare value calculated based on prescaler and period of 10ms
	OCR2A = 249;

	//Counter init 0
	TCNT2 = 0;
}

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
