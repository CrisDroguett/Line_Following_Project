// Noah Fishman
// Cris Droguett

#ifndef ADC_DRIVER_H_
#define ADC_DRIVER_H_
#include <stdbool.h>
#include <stdint.h>

void configure_adc();
uint16_t get_adc_result();
void start_adc_conversion(uint8_t channel);
_Bool adc_conversion_is_complete();

#endif /* ADC_DRIVER_H_ */