/*
 * timers_functions.h
 *
 * Created: 29.12.2017 18:00:55
 *  Author: Ne0n
 */ 


#ifndef TIMERS_FUNCTIONS_H_
#define TIMERS_FUNCTIONS_H_

#include "../../hardware/hardware_functions.h"
#include "../variables.h"
#include "timers_array.h"

#define flash_speed 300

void timer_br_led_on_1();

void timer_br_led_off_1();

void timer_br_led_on_2();

void timer_br_led_off_2();

void timer_br_countdown();

void timer_speaker_off();

void timer_br_speaker_false_on();

void timer_br_speaker_false_off();

void timer_br_led_off();

void run_timer_functions();



#endif /* TIMERS_FUNCTIONS_H_ */