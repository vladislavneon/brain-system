/*
 * timers_array.h
 *
 * Created: 27.12.2017 23:10:05
 *  Author: Ne0n
 */ 


#ifndef TIMERS_ARRAY_H_
#define TIMERS_ARRAY_H_

#include "timers_numeration.h"
#include "../structures.h"
#include <avr/interrupt.h>

extern struct Timer timers[NUM_TIMERS];

void timer_array_init();

void set_timer(u_char task, int time);

void clear_timer(u_char task);


#endif /* TIMERS_ARRAY_H_ */