#ifndef _LED_H_
#define _LED_H_

#include <util/delay.h>
#include <avr/io.h>

#define LED_BLUE PD6 //Digital pin 6

void LED_init(void);
void LED_Blink(void);
void Led_cycle_brightness(void);

#endif // _LED_H_

