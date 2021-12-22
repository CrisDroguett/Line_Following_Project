// Cris Droguett
// Noah Fishman

#include <avr/io.h>
#include "left_motor.h"

void configure_left_motor()
{
	DDRD |= (1<<5); // PD5 as output
	DDRD |= (1<<6); // PD6 as output
}
void brake_left_motor()
{
	PORTD |= (1<<5);
	PORTD |= (1<<6);
}
void coast_left_motor()
{
	PORTD &= ~(1<<5);
	PORTD &= ~(1<<6);
}
void turn_on_left_motor_forwards()
{
	PORTD &= ~(1<<5);
	PORTD |= (1<<6);
}
void turn_on_left_motor_reverse()
{
	PORTD |= (1<<5);
	PORTD &= ~(1<<6);
}
