/*
 * hardware_defines.h
 *
 * Created: 25.12.2017 22:13:44
 *  Author: Ne0n
 */ 


#ifndef HARDWARE_DEFINES_H_
#define HARDWARE_DEFINES_H_

#define F_CPU 1000000L


#include "led/led_defines.h"
#include "button/button_defines.h"
#include "speaker/speaker_defines.h"
#include <util/delay.h>
#include <avr/io.h>

#define get_bit(reg, num) ((reg) & (1 << (num)))
#define set_bit(reg, num, bit) ((bit) ? ((reg) |= (1 << (num))) : ((reg) &= ~(1 << (num))))
#define reverse_bit(reg, num) ((reg) ^= (1 << (num)))

#endif /* HARDWARE_DEFINES_H_ */