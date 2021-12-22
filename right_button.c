// Cris Droguett
// Noah Fishman

#include <avr/io.h>
#include "right_button.h"

void configure_right_button()
{
	DDRB &= ~(1<<5);
	PORTB |= (1<<5);
}

_Bool right_button_is_pressed()
{
	return ((PINB & (1<<5)) == 0);
}

_Bool right_button_is_not_pressed()
{
	return !right_button_is_pressed();
}
