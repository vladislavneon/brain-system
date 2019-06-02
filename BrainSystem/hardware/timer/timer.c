/*
 * timer.c
 *
 * Created: 27.12.2017 21:58:50
 *  Author: Ne0n
 */ 

#include "timer.h"

unsigned int cnt = 0;
unsigned char tmr = 255 - 125 + 1;

void timer_init() {
	//reset prescaler
	SFIOR |= (1 << PSR10);
	
	//timer0 for time
	//set prescaler 8
	TCCR0 |= (1 << CS01);
	//enable timer0 interrupt
	TIMSK |= (1 << TOIE0);
	
	//timer1 for pwm
	//set prescaler 8
	TCCR1B |= (1 << CS11);
	//set non-inverting mode
	TCCR1A |= (1 << COM1A1);
	//set wavegen mode
	TCCR1A |= (1 << WGM11);
	TCCR1B |= (1 << WGM12) | (1 << WGM13);
	
	
	sei();			
}

ISR (TIMER0_OVF_vect) {
	cli();
	TCNT0 = tmr;
	for (u_int i = 0; i < NUM_TIMERS; ++i) {
		if (timers[i].armed && timers[i].time) {
			--timers[i].time;	
		}
	}
	sei();
}