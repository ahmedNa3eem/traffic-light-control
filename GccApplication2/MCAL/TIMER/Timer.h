/*
 * Timer.h
 *
 * Created: 9/18/2022 1:20:15 PM
 *  Author: ahmed
 */ 


#ifndef TIMER_H_
#define TIMER_H_
#include "../../Utilities/registers.h"

# define timerError 1
#define  timerOK    0

void timer_init(void);
uint8_t delay(int delayTime);




#endif /* TIMER_H_ */