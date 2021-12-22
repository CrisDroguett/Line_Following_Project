// Cris Droguett
// Noah Fishman

#include <avr/io.h>
#include "middle_button.h"

void configure_middle_button()
{
	DDRB &= ~(1<<4);
	PORTB |= (1<<4);
}

_Bool middle_button_is_pressed()
{
	return ((PINB & (1<<4)) == 0);
}

_Bool middle_button_is_not_pressed()
{
	return !middle_button_is_pressed();
}
