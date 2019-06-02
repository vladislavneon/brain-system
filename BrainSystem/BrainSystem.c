/*
 * BrainSystem.c
 *
 * Created: 24.12.2017 22:32:43
 *  Author: Ne0n
 */ 

#include "software/automaton/automaton.h"

int main(void) {
	automaton_init();
	while (1) {
		automaton_run();	
	}
	
	
	//timer_init();
	//led_init();
	//speaker_set_freq(500);
	//speaker_on();
    //while(1) {
		//for (int i = 1; i <= 4; ++i) {
			//if (button_read(i)) {
				//led_on(i);
			//}
			//else {
				//led_off(i);	
			//}
		//}
    //}
}