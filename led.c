#include <avr/io.h>
#include "led.h"
#include <util/delay.h>
#include <stdbool.h> 

uint8_t light = 0;
bool lightfade = true;


void LED_init() {
	DDRB |= (1 << PORTB3); //arduino digital pin 11
	DDRD |= (1 << PORTD6); // PWM, DELUPPGIFT 2, man kan dra sladd från pin 11 till pin 6 på skölden
	
}

void led_PWM(){
	OCR0A = 255;
	_delay_ms(1000);

	OCR0A = 128;
	_delay_ms(1000);

	OCR0A = 0;
	_delay_ms(1000);
}

uint8_t simple_ramp(){
	
	if (light <= 255 && lightfade == true) {
        light++;
    }
    else if (light <= 255 && lightfade == false) {
        light--;
    }
    if (light == 255) {
        lightfade = false;
    }
    else if (light == 0) {
        lightfade = true;
    }
    return light;
	
}
