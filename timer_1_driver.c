// Cris Droguett
// Noah Fishman

#include <avr/io.h>
#include "timer_1_driver.h"

void configure_timer_1() {
	
	ICR1 = 20000; // 20000000/1000
	TCCR1A = 0x00;
	TCCR1B = 0x19;
	
}

void wait_for_next_timer_period() {
	
	while((TIFR1 & (1<<ICF1)) == 0);
	TIFR1 |= (1<<ICF1);
	
}