// Cris Droguett
// Noah Fishman

#include <avr/io.h>
#include "left_button.h"

void configure_left_button()
{
	DDRB &= ~(1<<1);
	PORTB |= (1<<1);
}

_Bool left_button_is_pressed()
{
	return ((PINB & (1<<1)) == 0);
}

_Bool left_button_is_not_pressed()
{
	return !left_button_is_pressed();
}
