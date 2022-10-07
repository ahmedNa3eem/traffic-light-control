/*
 * LED.c
 *
 * Created: 9/18/2022 1:17:38 PM
 *  Author: ahmed
 */ 

#include"LED.h"

EN_LEDERROR_t LED_init(uint8_t portNumber,uint8_t pinNumber){
	//use DIO_init to initialize the LED
	if(DIO_init(portNumber,pinNumber,OUT)==0){
		return LED_OK;
	}else{
		return init_ERROR;
	}
}
EN_LEDERROR_t LED_on_off(uint8_t portNumber,uint8_t pinNumber,uint8_t state){
	//use DIO_write to turn the LED ON or OFF
	if(DIO_write(portNumber,pinNumber,state)==0){
		return LED_OK;
	}else{
		return ON_OFF_ERROR;
	}
}
EN_LEDERROR_t LED_toggle(uint8_t portNumber,uint8_t pinNumber){
	//use DIO_Toggle to toggle the LED
	if(DIO_toggle(portNumber,pinNumber)==0){
		return LED_OK;
	}else{
			return toggle_ERROR;
		}
}
EN_LEDERROR_t LED_blink(uint8_t portNumber, uint8_t pinNumber, int delayTime,int wholeTime){
	//create variable that save the passed time and another one that saves the number of toggles done
	int passedTime=0,numberOfToggles=0;
		//loop that toggle the led after each delayTime
	while(passedTime<wholeTime){
		//toggle the led
		if(LED_toggle(portNumber,pinNumber)!=0){
			return blink_ERROR;
		}
		//delay
		if(delay(delayTime)!=0){
			return blink_ERROR;
		}
		//increment numberOfToggles and calculate the time passed
		numberOfToggles++;
		passedTime=numberOfToggles*delayTime;
	}
	//make sure that the led is off after the loop
	if(LED_on_off(portNumber,pinNumber,OFF)!=0){
		return blink_ERROR;
	}
	return LED_OK;
}
EN_LEDERROR_t TWOLED_blink(int delayTime,int wholeTime){
	//create variable that save the passed time and another one that saves the number of toggles done
	int passedTime=0,numberOfToggles=0;
	//loop that toggle the led after each delayTime
	while(passedTime<wholeTime){
		//toggle the leds
		if(LED_toggle(A,1)!=0||LED_toggle(B,1)!=0){
			return blink_ERROR;
		}
		//delay
		if(delay(delayTime)!=0){
			return blink_ERROR;
		}
		//increment numberOfToggle and calculate the time passed
		numberOfToggles++;
		passedTime=numberOfToggles*delayTime;
	}
	//make sure that the leds are off after the loop
	if(LED_on_off(A,1,OFF)!=0||LED_on_off(B,1,OFF)){
		return blink_ERROR;
	}
	return LED_OK;
}

