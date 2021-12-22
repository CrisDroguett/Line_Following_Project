// Cris Droguett
// Noah Fishman

#include <avr/io.h>
#include "right_motor_timer.h"

// DO NOT ADD TO .h FILE
void stop_right_timer0()
{
	TCCR2A = 0x03;
	TCCR2B = 0x00;
}

void start_right_timer0()
{
	TCCR2B = 0x01;
}

// ADD TO .h FILE
void set_right_motor_duty_cycle(uint8_t duty_cycle)
{
	OCR2A = duty_cycle;
	OCR2B = duty_cycle;
}

void configure_right_motor()
{
	brake_right_motor();
	set_right_motor_duty_cycle(0); //extra safety measure
	DDRD |= (1<<3); // PD3 as output
	DDRB |= (1<<3); // PB3 as output
}
void brake_right_motor()
{
	stop_right_timer0();
	PORTD |= (1<<3);
	PORTB |= (1<<3);
}
void coast_right_motor()
{
	stop_right_timer0();
	PORTD &= ~(1<<3);
	PORTB &= ~(1<<3);
}
void turn_on_right_motor_forwards()
{
	brake_right_motor();
	TCCR2A = 0x33;
	start_right_timer0();
}
void turn_on_right_motor_reverse()
{
	brake_right_motor();
	TCCR2A = 0xC3;
	start_right_timer0();
}
