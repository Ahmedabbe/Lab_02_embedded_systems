#ifndef _LED_H_
#define _LED_H_

#include <util/delay.h>
#include <avr/io.h>

#define LED_BLUE PD6 //Digital pin 6

void LED_init(void);
void LED_Blink(void);
uint8_t simple_ramp(uint8_t*, uint8_t* );

#endif // _LED_H_

