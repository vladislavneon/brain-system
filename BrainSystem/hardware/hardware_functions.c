/*
 * hardware_functions.c
 *
 * Created: 03.01.2018 23:45:12
 *  Author: Ne0n
 */ 

#include "hardware_functions.h"

void hardware_init() {
	led_init();
	button_init();
	timer_init();	
}