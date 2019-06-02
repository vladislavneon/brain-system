/*
 * br_states_functions.c
 *
 * Created: 28.12.2017 0:43:17
 *  Author: Ne0n
 */ 

#include "br_states_functions.h"

void run_br_reading() {
	//init
	br_first_pressed = 0;
	
	//mode changing
	u_char mode_pressed = br_scan_mode();
	if (mode_pressed) {
		led_mode_change();
		state = SI_WAITING;
		return;	
	}
	
	//false start
	u_char player_pressed = br_scan_buttons();
	if (player_pressed) {
		br_led_flash_on(player_pressed);
		br_sound_false();
		br_first_pressed = player_pressed;
		state = BR_FALSE;
		return;	
	}
	
	//start time
	u_char start_pressed = br_scan_start();
	if (start_pressed) {
		br_sound_start();
		br_start_countdown(60);
		state = BR_MINUTE;
		return;	
	}
}

void run_br_false() {
	//reset to reading
	char reset_pressed = br_scan_reset();
	if (reset_pressed) {
		br_led_flash_off();
		br_sound_off();
		state = BR_READING;
		return;	
	}
	
	//start 20 sec
	u_char start_pressed = br_scan_start();
	if (start_pressed) {
		br_led_flash_off();
		br_sound_off();
		br_sound_start();
		br_start_countdown(20);
		state = BR_20SEC;
		return;	
	}
}

void run_br_minute() {
	//reset to reading
	u_char reset_pressed = br_scan_reset();
	if (reset_pressed) {
		br_led_on_reset();
		br_stop_countdown();
		state = BR_READING;
		return;	
	}
	
	//players' buttons
	u_char player_pressed = br_scan_buttons();
	if (player_pressed) {
		br_first_pressed = player_pressed;
		br_stop_countdown();
		br_led_on(player_pressed);
		br_sound_pressed();
		state = BR_FS_TEAM_PRESSED;
		return;	
	}
	
	//timeover
	if (countdown == 0) {
		br_stop_countdown();
		br_led_on(1);
		br_led_on(2);
		br_sound_end();
		state = BR_TIMEOVER;
		return;	
	}
	
	//10 sec countdown
	if ((countdown <= 10) && (countdown != last_sounded_sec)) {
		br_sound_last10();
		last_sounded_sec = countdown;	
	}
}

void run_br_20sec() {
	//reset to reading
	u_char reset_pressed = br_scan_reset();
	if (reset_pressed) {
		br_led_on_reset();
		br_stop_countdown();
		state = BR_READING;
		return;
	}
	
	//players' buttons
	u_char player_pressed = br_scan_buttons();
	if ((player_pressed) && (player_pressed != br_first_pressed)) {
		br_stop_countdown();
		br_led_on(player_pressed);
		br_sound_pressed();
		state = BR_SC_TEAM_PRESSED;
		return;	
	}
	
	//timeover
	if (countdown == 0) {
		br_stop_countdown();
		br_led_on(1);
		br_led_on(2);
		br_sound_end();
		state = BR_TIMEOVER;
		return;
	}
	
	//5 sec countdown
	if ((countdown <= 5) && (countdown != last_sounded_sec)) {
		br_sound_last10();
		last_sounded_sec = countdown;
	}
}

void run_br_fs_team_pressed() {
	//reset to reading
	u_char reset_pressed = br_scan_reset();
	if (reset_pressed) {
		br_led_off();
		state = BR_READING;
		return;	
	}
	
	//start 20 sec
	u_char start_pressed = br_scan_start();
	if (start_pressed) {
		br_led_off();
		br_sound_start();
		br_start_countdown(20);
		state = BR_20SEC;
		return;	
	}
}

void run_br_sc_team_pressed() {
	//reset
	u_char reset_pressed = br_scan_reset();
	if (reset_pressed) {
		br_led_off();
		state = BR_READING;
		return;	
	}
}

void run_br_timeover() {
	//reset
	u_char reset_pressed = br_scan_reset();
	if (reset_pressed) {
		br_led_off();
		br_sound_off();
		state = BR_READING;
		return;
	}	
}