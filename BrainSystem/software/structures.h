/*
 * structures.h
 *
 * Created: 27.12.2017 23:00:14
 *  Author: Ne0n
 */ 


#ifndef STRUCTURES_H_
#define STRUCTURES_H_

typedef unsigned char u_char;
typedef unsigned int u_int;

enum States {SI_WAITING, SI_PRESSED, BR_READING, BR_FALSE, BR_MINUTE, BR_20SEC, BR_FS_TEAM_PRESSED, BR_SC_TEAM_PRESSED, BR_TIMEOVER};
enum Modes {SI, BR};

struct Timer {
	u_char armed;
	u_int time;
};


#endif /* STRUCTURES_H_ */