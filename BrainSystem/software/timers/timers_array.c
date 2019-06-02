/*
 * timers_array.c
 *
 * Created: 27.12.2017 23:10:38
 *  Author: Ne0n
 */ 

#include "timers_array.h"

struct Timer timers[NUM_TIMERS];

void timer_array_init() {
	for (int i = 0; i < NUM_TIMERS; ++i) {
		timers[i].armed = 0;
		timers[i].time = 0;	
	}
}

void set_timer(u_char task, int time) {
	cli();
	timers[task].armed = 1;
	timers[task].time = time;
	sei();
}

void clear_timer(u_char task) {
	cli();
	timers[task].armed = 0;
	sei();	
}