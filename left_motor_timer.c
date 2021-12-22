// Cris Droguett
// Noah Fishman

#include <avr/io.h>
#include "left_motor_timer.h"

// DO NOT ADD TO .h FILE
void stop_left_timer0()
{
	TCCR0A = 0x03;
	TCCR0B = 0x00;
}

void start_left_timer0()
{
	TCCR0B = 0x01;
}

// ADD TO .h FILE
void set_left_motor_duty_cycle(uint8_t duty_cycle)
{
	OCR0A = duty_cycle;
	OCR0B = duty_cycle;
}

void configure_left_motor()
{
	brake_left_motor();
	set_left_motor_duty_cycle(0); //extra safety measure
	DDRD |= (1<<5); // PD5 as output (A)
	DDRD |= (1<<6); // PD6 as output (B)
}
void brake_left_motor()
{
	stop_left_timer0();
	PORTD |= (1<<5);
	PORTD |= (1<<6);
}
void coast_left_motor()
{
	stop_left_timer0();
	PORTD &= ~(1<<5);
	PORTD &= ~(1<<6);
}
void turn_on_left_motor_forwards()
{
	brake_left_motor();
	TCCR0A = 0x33;
	start_left_timer0();
}
void turn_on_left_motor_reverse()
{
	brake_left_motor();
	TCCR0A = 0xC3;
	start_left_timer0(); 
}
