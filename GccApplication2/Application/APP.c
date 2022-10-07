/*
 * APP.c
 *
 * Created: 9/21/2022 12:03:58 AM
 *  Author: ahmed
 */ 
# include "APP.h"
uint8_t INT0_Flag=0;

void APP_init(void){
	//initialize the pins , timer and the external interrupt
	DIO_init(D,2,IN);
	LED_init(cars,RED_led);
	LED_init(cars,YELLOW_led);
	LED_init(cars,GREEN_led);
	LED_init(pedestrian,RED_led);
	LED_init(pedestrian,YELLOW_led);
	LED_init(pedestrian,GREEN_led);
	timer_init();
	EXT_INT0_INIT();
	
}
void APP_start(void){
	//1.normal mode
	// yellow car's light blink every 512ms for 5s 
	LED_blink(cars,YELLOW_led,512,5000);
	//if the int_flag equal to 1 change it's value to 0 and start from the beginning 
	if(INT0_Flag==0){
		//turn on the red car's led 
		LED_on_off(cars,RED_led,ON);
		//delay
		delay(5000);
		//turn off the red car's led
		LED_on_off(cars,RED_led,OFF);
		//if the int_flag equal to 1 change it's value to 0 and start from the beginning
		if(INT0_Flag==0){
			//again the yellow car's led blink every 512ms for 5s
			LED_blink(cars,YELLOW_led,512,5000);
			//if the int_flag equal to 1 change it's value to 0 and start from the beginning
			if(INT0_Flag==0){
				//turn on the green car's led
				LED_on_off(cars,GREEN_led,ON);
				//delay for 5s
				delay(5000);
				//turn off the green car's led
				LED_on_off(cars,GREEN_led,OFF);
				}else{
					//set the int_flag equal to 0
				INT0_Flag=0;
			}
			}else{
				//set the int_flag equal to 0
			INT0_Flag=0;
		}
		}else{
			//set the int_flag equal to 0
		INT0_Flag=0;
	}
	
	
}


ISR(EXT_INT_0){
	//create a variable to save the value of the car's red led
	uint8_t redLedState;
	//read the state of car's red led and save it to the variable
	DIO_read(cars,RED_led,&redLedState);
	//check if the red light is ON 
	if(redLedState==1){
		//__in case the car's red led is ON
		//turn ON the car's red led and the pedestrian's green led
		LED_on_off(cars,RED_led,ON);
		LED_on_off(pedestrian,GREEN_led,ON);
		//delay for 5s
		delay(5000);
		//turn off the car's red led
		LED_on_off(cars,RED_led,OFF);
		//the two yellow led start to blink for 5s
		TWOLED_blink(512,5000);
		//the pedestrian's green led is turned off
		LED_on_off(pedestrian,GREEN_led,OFF);
		//the pedestrian's red led and the car's green led are turned ON
		LED_on_off(cars,GREEN_led,ON);
		LED_on_off(pedestrian,RED_led,ON);
		//delay for 5s
		delay(5000);
		//the pedestrian's red led and the car's green led are turned OFF
		LED_on_off(cars,GREEN_led,OFF);
		LED_on_off(pedestrian,RED_led,OFF);
		//set the INT0_Flag to 1 and start the timer
		INT0_Flag=1;
		TCCR0=5;
		}else{
			//__in case that the car's red led is off
			//make sure that the all car's led are OFF
		LED_on_off(cars,YELLOW_led,OFF);
		LED_on_off(cars,GREEN_led,OFF);
		//the pedestrian's red led is turned ON and the two yellow leds blink for 5s
		LED_on_off(pedestrian,RED_led,ON);
		TWOLED_blink(512,5000);
		//the pedestrian's red led is turned off
		LED_on_off(pedestrian,RED_led,OFF);
		//the pedestrian's green led and the car's red led are turned ON
		LED_on_off(pedestrian,GREEN_led,ON);
		LED_on_off(cars,RED_led,ON);
		//delay for 5 seconds
		delay(5000);
		//the car's red led is turned off
		LED_on_off(cars,RED_led,OFF);
		//the two yellow led blinks for 5s
		TWOLED_blink(512,5000);
		//the pedestrian' green led is turned off 
		LED_on_off(pedestrian,GREEN_led,OFF);
		//the pedestrian's red led and the car's green led turned ON
		LED_on_off(cars,GREEN_led,ON);
		LED_on_off(pedestrian,RED_led,ON);
		//delay for 5s
		delay(5000);
		//the pedestrian's red led and the car's green led turned OFF
		LED_on_off(cars,GREEN_led,OFF);
		LED_on_off(pedestrian,RED_led,OFF);
		// set INT0_Flag to 1 and starts the timer 
		INT0_Flag=1;
		TCCR0=5;
		
	}
	
	
}