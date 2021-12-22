// Cris Droguett
// Noah Fishman

#include <avr/io.h>
#include <stdint.h>

void configure_reflective_sensor()
{
	DDRC &= ~ 0x3F;
	PORTC |= 0x1F;
}

uint8_t get_sensor_info()
{
	return PINC & 0x1F;	
}