/*
 * speaker_functions.h
 *
 * Created: 27.12.2017 19:41:25
 *  Author: Ne0n
 */ 


#ifndef SPEAKER_FUNCTIONS_H_
#define SPEAKER_FUNCTIONS_H_

#include "../hardware_defines.h"
#include "../../software/structures.h"
#define PRESCLR 8

void speaker_on();

void speaker_off();

void speaker_set_freq(u_int freq);

void speaker_on_si();

void speaker_off_si();


#endif /* SPEAKER_FUNCTIONS_H_ */