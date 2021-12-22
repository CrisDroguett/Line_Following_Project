// Cris Droguett
// Noah Fishman

#include <avr/io.h>
#include "green_led.h"

void configure_green_led()
{
	DDRD |= (1<<7);
}

void turn_on_green_led()
{
	PORTD |= (1<<7);
}

void turn_off_green_led()
{
	PORTD &= ~(1<<7);
}

void toggle_green_led()
{
	PORTD ^= (1<<7);
}
