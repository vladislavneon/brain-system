/*
 * si_functions.c
 *
 * Created: 27.12.2017 20:25:29
 *  Author: Ne0n
 */

#include "si_functions.h" 

char si_scan_buttons() {
	if (button_read(1)) {
		return 1;	
	}
	if (button_read(2)) {
		return 2;	
	}
	if (button_read(3)) {
		return 3;	
	}
	if (button_read(4)) {
		return 4;	
	}
	return 0;
}

void si_led_on(char num) {
	led_on(num);	
}

void si_sound() {
	speaker_set_freq(300);
	speaker_on();
	set_timer(SPEAKER_OFF, 800);	
}

char si_scan_reset() {
	return button_ctrl_read();	
}

char si_scan_mode() {
	return button_mode_read();
}

void si_led_off() {
	led_off(1);
	led_off(2);
	led_off(3);
	led_off(4);	
}