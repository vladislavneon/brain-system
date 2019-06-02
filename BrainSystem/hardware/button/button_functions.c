/*
 * button_functions.c
 *
 * Created: 26.12.2017 1:38:21
 *  Author: Ne0n
 */ 

#include "button_functions.h"

void button_init() {
	DDR_BUTTON_1 &= ~(1 << NUM_BUTTON_1);
	DDR_BUTTON_2 &= ~(1 << NUM_BUTTON_2);
	DDR_BUTTON_3 &= ~(1 << NUM_BUTTON_3);
	DDR_BUTTON_4 &= ~(1 << NUM_BUTTON_4);
	PORT_BUTTON_1 |= (1 << NUM_BUTTON_1);
	PORT_BUTTON_2 |= (1 << NUM_BUTTON_2);
	PORT_BUTTON_3 |= (1 << NUM_BUTTON_3);
	PORT_BUTTON_4 |= (1 << NUM_BUTTON_4);
	
	DDR_BUTTON_MODE &= ~(1 << NUM_BUTTON_MODE);
	PORT_BUTTON_MODE |= (1 << NUM_BUTTON_MODE);
	
	DDR_BUTTON_CTRL &= ~(1 << NUM_BUTTON_CTRL);
	PORT_BUTTON_CTRL |= (1 << NUM_BUTTON_CTRL);	
}

char button_read(char num) {
	char pressed;
	switch (num) {
	case 1:
		pressed = get_bit(PIN_BUTTON_1, NUM_BUTTON_1);
		return reverse_bit(pressed, NUM_BUTTON_1);
		break;
	case 2:
		pressed = get_bit(PIN_BUTTON_2, NUM_BUTTON_2);
		return reverse_bit(pressed, NUM_BUTTON_2);
		break;
	case 3:
		pressed = get_bit(PIN_BUTTON_3, NUM_BUTTON_3);
		return reverse_bit(pressed, NUM_BUTTON_3);
		break;
	case 4:
		pressed = get_bit(PIN_BUTTON_4, NUM_BUTTON_4);
		return reverse_bit(pressed, NUM_BUTTON_4);
		break;	
	}
	return 0;
}

char button_ctrl_read() {
	char released = get_bit(PIN_BUTTON_CTRL, NUM_BUTTON_CTRL);
	if (!released) {
		if (!button_ctrl_was_pressed) {
			button_ctrl_was_pressed = 1;
			return 1;	
		}
		else {
			return 0;	
		}
	}
	else {
		if (button_ctrl_was_pressed) {
			button_ctrl_was_pressed = 0;	
		}
		return 0;
	}
}

char button_mode_read() {
	char released = get_bit(PIN_BUTTON_MODE, NUM_BUTTON_MODE);
	if (!released) {
		if (!button_mode_was_pressed) {
			button_mode_was_pressed = 1;
			return 1;
		}
		else {
			return 0;
		}
	}
	else {
		if (button_mode_was_pressed) {
			button_mode_was_pressed = 0;
		}
		return 0;
	}
}