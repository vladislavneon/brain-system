/*
 * si_states_functions.c
 *
 * Created: 27.12.2017 23:13:01
 *  Author: Ne0n
 */ 

#include "si_states_functions.h"

void run_si_waiting() {
	//mode changing
	char mode_pressed = si_scan_mode();
	if (mode_pressed) {
		led_mode_change();
		state = BR_READING;
		return;	
	}
	
	//players buttons
	char player_pressed = si_scan_buttons();
	if (player_pressed > 0) {
		si_led_on(player_pressed);
		si_sound();
		state = SI_PRESSED;
		return;
	}
}

void run_si_pressed() {
	//reset button
	char reset_pressed = si_scan_reset();
	if (reset_pressed) {
		si_led_off();
		state = SI_WAITING;
		return;	
	}
}