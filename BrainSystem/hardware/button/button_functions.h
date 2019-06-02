/*
 * button_functions.h
 *
 * Created: 26.12.2017 1:36:53
 *  Author: Ne0n
 */ 


#ifndef BUTTON_FUNCTIONS_H_
#define BUTTON_FUNCTIONS_H_

#include "../hardware_defines.h"
#include "../../software/variables.h"

void button_init();

char button_read(char num);

char button_ctrl_read();

char button_mode_read();



#endif /* BUTTON_FUNCTIONS_H_ */