/*
 * si_functions.h
 *
 * Created: 27.12.2017 20:22:17
 *  Author: Ne0n
 */ 


#ifndef SI_FUNCTIONS_H_
#define SI_FUNCTIONS_H_

#include "../../hardware/hardware_functions.h"
#include "../timers/timers_array.h"

char si_scan_buttons();

void si_led_on(char num);

void si_sound();

char si_scan_reset();

char si_scan_mode();

void si_led_off();



#endif /* SI_FUNCTIONS_H_ */