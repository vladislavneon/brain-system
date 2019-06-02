/*
 * speaker_functions.c
 *
 * Created: 29.12.2017 15:39:02
 *  Author: Ne0n
 */ 

#include "speaker_functions.h"

void speaker_on() {
	DDR_SPEAKER |= (1 << NUM_SPEAKER);
}

void speaker_off() {
	DDR_SPEAKER &= ~(1 << NUM_SPEAKER);	
}

void speaker_set_freq(u_int freq) {
	ICR1 = (F_CPU / (PRESCLR * freq)) - 1;
	OCR1A = ((F_CPU / (PRESCLR * freq)) - 1) / 2;
}

void speaker_on_si() {
	DDRB |= (1 << PINB1);
	PORTB |= (1 << PINB1);	
}

void speaker_off_si() {
	PORTB &= ~(1 << PINB1);	
}