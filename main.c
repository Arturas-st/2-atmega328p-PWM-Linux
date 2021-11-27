#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include <stdio.h>
#include "led.h"
#include "serial.h"
#include "timer.h"

void main (void) {
	int counter = 0;
	uart_init();
	LED_init();
	//timer_init();  // DELUPPGIFT 1
	timerPWM_init(); // DELUPPGIFT 2 och 3
	timer2_init();   // DELUPPGIFT 3

	while (1) {
		/* remove this once you've verified it works */
		/*printf_P(PSTR("Hello there\n"));
		_delay_ms(1000);*/

		// DELUPPGIFT 1
		/*while((TIFR0 & (1 << OCF0A)) > 0){ //wait for overflow
			counter ++;
			if (counter == 10){
				PORTD ^= (1 << PORTD6);
				counter = 0;
			}
			TIFR0 |= (1 << OCF0A); //clears flag

		}*/

		/* //DELUPPGIFT 2
		led_PWM();*/
	
		// DELUPPGIFT 3
		while((TIFR2 & (1 << OCF2A)) > 0){ //wait for overflow
			
			OCR0A = simple_ramp();
			
			TIFR2 |= (1 << OCF2A); //clears overflow flag

		}

	}

}
