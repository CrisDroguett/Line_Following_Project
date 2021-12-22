// Cris Droguett
// Noah Fishman

#include <avr/io.h>
#include "red_led.h"

void configure_red_led()
{
	DDRD |= (1<<1);
}

void turn_on_red_led()
{
	PORTD |= (1<<1);
}

void turn_off_red_led()
{
	PORTD &= ~(1<<1);
}

void toggle_red_led()
{
	PORTD ^= (1<<1);
}
