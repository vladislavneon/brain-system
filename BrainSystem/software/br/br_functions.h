/*
 * br_functions.h
 *
 * Created: 27.12.2017 20:47:25
 *  Author: Ne0n
 */ 


#ifndef BR_FUNCTIONS_H_
#define BR_FUNCTIONS_H_

#include "../../hardware/hardware_functions.h"
#include "../variables.h"
#include "../timers/timers_array.h"

char br_scan_start();

char br_scan_reset();

char br_scan_mode();

char br_scan_buttons();

void br_led_on(u_char num);

void br_led_flash_on(u_char num);

void br_led_flash_off();

void br_led_off();

void br_led_on_reset();

void br_sound_start();

void br_sound_false();

void br_sound_pressed();

void br_sound_last10();

void br_sound_end();

void br_sound_off();

void br_start_countdown(u_char time);

void br_stop_countdown();


#endif /* BR_FUNCTIONS_H_ */