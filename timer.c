#include <avr/io.h>
#include "timer.h"

    // DELUPPGIFT 1
void timer_init() {
	//TCCR0A |= (1 << COM0A0);  //Sets PORTB1/OC0A to toggle on timer, Toggle OC0A on Compare Match.
	TCCR0A |= (1 << WGM01);     //Sets timer CTC mode
	TCCR0B |= (1 << CS00) | (1 << CS02);    //prescaler 1024
	OCR0A = 157; //155     // 1/(16MHz/1024) * 157 = 10ms
	TCNT0 = 0;       // sets the timer back to 0
}
  // DELUPPGIFT 2 och 3
void timerPWM_init(){
	TCCR0A |= (1 << WGM01) | (1 << WGM00) | (1 << COM0A1); //Set Fast PWM mode (non-inverting mode)
	TCCR0B |= (1 << CS01) | (1 << CS00);  //sets prescaler to 64

	// PWM-frekvens = Fw = Fcpu/(256 * N) = 16MHz/(256 * 64) = 976.560Hz
}
 // DELUPPGIFT 3
void timer2_init(){
	//TCCR2A |= (1 << COM2A0);  //Sets PORTB3/OC2A to toggle on timer, Toggle OC2A on Compare Match.
	TCCR2A |= (1 << WGM21); //Sets timer CTC mode, sets automatically to 0 when ocr valuea is reached
	TCCR2B |= (1 << CS22) | (1 << CS21) | (1 << CS20); //prescaler 1024
	OCR2A = 250;  // 1/(16MHz/1024) * 250 = 16ms //16000000/1024 * 0.016 = 250-1
	TCNT2 = 0; // sets the timer back to 0
}

