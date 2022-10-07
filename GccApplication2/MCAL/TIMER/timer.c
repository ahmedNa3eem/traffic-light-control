/*
 * timer.c
 *
 * Created: 9/18/2022 1:20:30 PM
 *  Author: ahmed
 */ 
#include<math.h>
#include"Timer.h"
extern uint8_t INT0_Flag;
void timer_init(void){
	//choose timer mode
	TCCR0=0x00;
	//timer set initial value
	TCNT0=0x00;
}
uint8_t delay(int delayTime){
	//create  variables needed for delay calculations
	float maxDelay,tickTime;
	int timerIntialValue,numberOfOverFlowes, overFlowCounter=0;
	 tickTime =(1024/pow(10,6))*1000;
	 maxDelay = tickTime*256;
	 numberOfOverFlowes= ceil(delayTime/maxDelay);
	 timerIntialValue = 256-((delayTime/tickTime)/numberOfOverFlowes);
	
	TCNT0=0x00;
	//set timer prescaler and start the timer
	TCCR0=5;
	while(overFlowCounter<numberOfOverFlowes){
		//set timer initial value
		TCNT0=timerIntialValue;
		//wait until overflow flag set 1
		while((TIFR & (1<<0))==0){
			if(INT0_Flag==1){
				break;
			}
		}
		//overflow flag set 0
		if((TIFR & (1<<0))==1){
			TIFR |= (1<<0);
		}else if(INT0_Flag==1){
			break;
		}else{
			return timerError;
		} 
		//increment the overflow counter
		overFlowCounter++;
	}
	//stop the timer
	TCCR0=0x00;
	//set timer register to zero
	TCNT0=0x00;
	return timerOK;
}
