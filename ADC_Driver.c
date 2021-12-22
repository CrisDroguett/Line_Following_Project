// Noah Fishman
// Cris Droguett

#include <stdbool.h>
#include <stdint.h>
#include <avr/io.h>
#include "ADC_Driver.h"

void configure_adc()
{
	ADCSRA = 0x87;
}

uint16_t get_adc_result()
{
	return ADC;
}

void start_adc_conversion(uint8_t channel)
{
	ADMUX = (1<<REFS0) | (channel&0x0f);
}

_Bool adc_conversion_is_complete()
{
	return ADCSRA & (1<<ADIF);
}