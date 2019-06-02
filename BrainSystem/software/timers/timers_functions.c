/*
 * timers_functions.c
 *
 * Created: 29.12.2017 18:03:48
 *  Author: Ne0n
 */ 

#include "timers_functions.h"

void timer_br_led_on_1() {
	led_on(1);
	set_timer(BR_LED_OFF_1, flash_speed);	
}

void timer_br_led_off_1() {
	led_off(1);
	set_timer(BR_LED_ON_1, flash_speed);	
}

void timer_br_led_on_2() {
	led_on(2);
	set_timer(BR_LED_OFF_2, flash_speed);
}

void timer_br_led_off_2() {
	led_off(2);
	set_timer(BR_LED_ON_2, flash_speed);
}

void timer_br_countdown() {
	if (countdown) {
		--countdown;	
	}
	set_timer(BR_COUNTDOWN, 1000);
}

void timer_speaker_off() {
	speaker_off();
	clear_timer(BR_SPEAKER_FALSE_ON);
	clear_timer(BR_SPEAKER_FALSE_OFF);	
}

void timer_br_speaker_false_on() {
	speaker_on();
	set_timer(BR_SPEAKER_FALSE_OFF, flash_speed / 2);	
}

void timer_br_speaker_false_off() {
	speaker_off();
	set_timer(BR_SPEAKER_FALSE_ON, flash_speed / 2);	
}

void timer_br_led_off() {
	led_off(1);
	led_off(2);	
}

void run_timer_functions() {
	for (u_char i = 0; i < NUM_TIMERS; ++i) {
		if ((timers[i].armed == 1) && (timers[i].time == 0)) {
			clear_timer(i);
			switch (i) {
			case BR_LED_ON_1:
				timer_br_led_on_1();
				break;	
			case BR_LED_OFF_1:
				timer_br_led_off_1();
				break;
			case BR_LED_ON_2:
				timer_br_led_on_2();
				break;
			case BR_LED_OFF_2:
				timer_br_led_off_2();
				break;
			case BR_COUNTDOWN:
				timer_br_countdown();
				break;
			case SPEAKER_OFF:
				timer_speaker_off();
				break;
			case BR_SPEAKER_FALSE_ON:
				timer_br_speaker_false_on();
				break;
			case BR_SPEAKER_FALSE_OFF:
				timer_br_speaker_false_off();
				break;
			case BR_LED_OFF:
				timer_br_led_off();
				break;
			}
		}
	}
}