/*
 * automaton.c
 *
 * Created: 28.12.2017 0:48:02
 *  Author: Ne0n
 */ 

#include "automaton.h"

void automaton_init() {
	
	timer_array_init();
	
	hardware_init();
	
	state = SI_WAITING;
	
	button_mode_was_pressed = 0;
	button_ctrl_was_pressed = 0;
}

void automaton_run() {
	run_timer_functions();
	switch (state) {
	case SI_WAITING:
		run_si_waiting();
		break;
	case SI_PRESSED:
		run_si_pressed();
		break;
	case BR_READING:
		run_br_reading();
		break;
	case BR_FALSE:
		run_br_false();
		break;
	case BR_MINUTE:
		run_br_minute();
		break;
	case BR_20SEC:
		run_br_20sec();
		break;
	case BR_FS_TEAM_PRESSED:
		run_br_fs_team_pressed();
		break;
	case BR_SC_TEAM_PRESSED:
		run_br_sc_team_pressed();
		break;
	case BR_TIMEOVER:
		run_br_timeover();
		break;	
	}
}