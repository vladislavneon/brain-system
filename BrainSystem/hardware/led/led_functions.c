/*
 * led_functions.c
 *
 * Created: 25.12.2017 22:19:37
 *  Author: Ne0n
 */ 

#include "led_functions.h"

void led_init() {
	//players LEDs
	DDR_LED_1 |= (1 << NUM_LED_1);
	DDR_LED_2 |= (1 << NUM_LED_2);
	DDR_LED_3 |= (1 << NUM_LED_3);
	DDR_LED_4 |= (1 << NUM_LED_4);
	PORT_LED_1 &= ~(1 << NUM_LED_1);
	PORT_LED_2 &= ~(1 << NUM_LED_2);
	PORT_LED_3 &= ~(1 << NUM_LED_3);
	PORT_LED_4 &= ~(1 << NUM_LED_4);
	//mode LED
	DDR_LED_MODE |= (1 << NUM_LED_MODE);
	PORT_LED_MODE &= ~(1 << NUM_LED_MODE);
}

void led_on(char num) {
	switch (num) {
	case 1:
		PORT_LED_1 |= (1 << NUM_LED_1);
		break;	
	case 2:
		PORT_LED_2 |= (1 << NUM_LED_2);
		break;
	case 3:
		PORT_LED_3 |= (1 << NUM_LED_3);
		break;
	case 4:
		PORT_LED_4 |= (1 << NUM_LED_4);
		break;
	}
}

void led_off(char num) {
	switch (num) {
	case 1:
		PORT_LED_1 &= ~(1 << NUM_LED_1);
		break;
	case 2:
		PORT_LED_2 &= ~(1 << NUM_LED_2);
		break;
	case 3:
		PORT_LED_3 &= ~(1 << NUM_LED_3);
		break;
	case 4:
		PORT_LED_4 &= ~(1 << NUM_LED_4);
		break;
	}
}

void led_mode_change() {
	reverse_bit(PORT_LED_MODE, NUM_LED_MODE);
	//if (get_bit(PORT_LED_MODE, NUM_LED_MODE)) {
		//set_bit(PORT_LED_MODE, NUM_LED_MODE, 0);	
	//}
	//else {
		//set_bit(PORT_LED_MODE, NUM_LED_MODE, 1);	
	//}
}