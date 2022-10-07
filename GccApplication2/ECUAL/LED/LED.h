/*
 * LED.h
 *
 * Created: 9/18/2022 1:17:52 PM
 *  Author: ahmed
 */ 


#ifndef LED_H_
#define LED_H_
#include"../../MCAL/DIO/DIO.h"
#include "../../MCAL/TIMER/Timer.h"

#define cars 1
#define pedestrian 2
#define RED_led  0
#define YELLOW_led 1
#define GREEN_led  2
//state macros
#define ON 1
#define OFF 0
//error enum
typedef enum LEDERROR{
	LED_OK,ON_OFF_ERROR,init_ERROR,toggle_ERROR,blink_ERROR
	} EN_LEDERROR_t ;

EN_LEDERROR_t LED_init(uint8_t portNumber,uint8_t pinNumber);
EN_LEDERROR_t LED_on_off(uint8_t portNumber,uint8_t pinNumber,uint8_t state);
EN_LEDERROR_t LED_toggle(uint8_t portNumber,uint8_t pinNumber);
EN_LEDERROR_t LED_blink(uint8_t portNumber,uint8_t pinNumber,int delayTime,int wholeTime);
EN_LEDERROR_t TWOLED_blink(int delayTime,int wholeTime);


#endif /* LED_H_ */