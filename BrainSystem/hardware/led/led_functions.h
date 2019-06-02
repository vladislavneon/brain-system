/*
 * led_functions.h
 *
 * Created: 25.12.2017 22:17:17
 *  Author: Ne0n
 */ 


#ifndef LED_FUNCTIONS_H_
#define LED_FUNCTIONS_H_

#include "../hardware_defines.h"

void led_init();

void led_on(char num);

void led_off(char num);

void led_mode_change();

#endif /* LED_FUNCTIONS_H_ */