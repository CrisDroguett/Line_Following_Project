// Cris Droguett
// Noah Fishman

#include <avr/io.h>
#include "right_motor.h"

void configure_right_motor()
{
	DDRD |= (1<<3); // PD3 as output
	DDRB |= (1<<3); // PB3 as output
}
void brake_right_motor()
{
	PORTD |= (1<<3);
	PORTB |= (1<<3);
}
void coast_right_motor()
{
	PORTD &= ~(1<<3);
	PORTB &= ~(1<<3);
}
void turn_on_right_motor_forwards()
{
	PORTD &= ~(1<<3);
	PORTB |= (1<<3);
}
void turn_on_right_motor_reverse()
{
	PORTD |= (1<<3);
	PORTB &= ~(1<<3);
}
