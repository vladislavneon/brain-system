/*
 * br_functions.c
 *
 * Created: 27.12.2017 20:56:29
 *  Author: Ne0n
 */ 

#include "br_functions.h"

char br_scan_start() {
	return button_ctrl_read();	
}

char br_scan_reset() {
	return button_mode_read();	
}

char br_scan_mode() {
	return button_mode_read();	
}

char br_scan_buttons() {
	if (button_read(1)) {
		return 1;	
	}
	if (button_read(2)) {
		return 2;	
	}
	return 0;
}

void br_led_on(u_char num) {
	led_on(num);	
}

void br_led_flash_on(u_char num) {
	if (num == 1) {
		set_timer(BR_LED_ON_1, 0);	
	}
	if (num == 2) {
		set_timer(BR_LED_ON_2, 0);	
	}
}

void br_led_flash_off() {
	clear_timer(BR_LED_ON_1);
	clear_timer(BR_LED_ON_2);
	clear_timer(BR_LED_OFF_1);
	clear_timer(BR_LED_OFF_2);
	br_led_off();	
}

void br_led_on_reset() {
	led_on(1);
	led_on(2);
	set_timer(BR_LED_OFF, 300);	
}

void br_led_off() {
	led_off(1);
	led_off(2);	
}

void br_sound_start() {
	speaker_set_freq(500);
	speaker_on();
	set_timer(SPEAKER_OFF, 1000);	
}

void br_sound_false() {
	speaker_off();
	clear_timer(SPEAKER_OFF);
	speaker_set_freq(400);
	set_timer(BR_SPEAKER_FALSE_ON, 0);
	set_timer(SPEAKER_OFF, 900);	
}

void br_sound_pressed() {
	speaker_off();
	clear_timer(SPEAKER_OFF);
	speaker_set_freq(300);
	speaker_on();
	set_timer(SPEAKER_OFF, 750);	
}

void br_sound_last10() {
	speaker_off();
	clear_timer(SPEAKER_OFF);
	speaker_set_freq(600);
	speaker_on();
	set_timer(SPEAKER_OFF, 200);	
}

void br_sound_end() {
	speaker_off();
	clear_timer(SPEAKER_OFF);
	speaker_set_freq(200);
	speaker_on();
	set_timer(SPEAKER_OFF, 2000);	
}

void br_start_countdown(u_char time) {
	countdown = time;
	last_sounded_sec = 11;
	set_timer(BR_COUNTDOWN, 1000);	
}

void br_sound_off() {
	speaker_off();
	clear_timer(BR_SPEAKER_FALSE_OFF);
	clear_timer(BR_SPEAKER_FALSE_ON);
	clear_timer(SPEAKER_OFF);	
}

void br_stop_countdown() {
	clear_timer(BR_COUNTDOWN);	
}