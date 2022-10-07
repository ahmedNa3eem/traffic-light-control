/*
 * DIO.h
 *
 * Created: 9/18/2022 12:17:20 AM
 *  Author: ahmed
 */ 


#ifndef DIO_H_
#define DIO_H_
#include "../../Utilities/registers.h"

//macros for external interrupt
#define EXT_INT_0 __vector_1
#define ISR(INT_VECT) void INT_VECT(void) __attribute__ ((signal,used));\
void INT_VECT(void)
//macros for PORTS
#define A 1
#define B 2 
#define C 3
#define D 4
//direction macros
#define OUT 1
#define IN  0
//value macros
#define HIGH 1
#define LOW  0
//enum for errors
typedef enum DIOERROR{
	DIO_OK ,value_ERROR,direction_ERROR,pinNumber_ERROR,portNumber_ERROR
	} EN_DIOERROR_t; 


EN_DIOERROR_t DIO_init( uint8_t portNumber, uint8_t pinNumber, uint8_t direction);
EN_DIOERROR_t DIO_write( uint8_t portNumber, uint8_t pinNumber, uint8_t value);
EN_DIOERROR_t DIO_read( uint8_t portNumber, uint8_t pinNumber, uint8_t *value);
EN_DIOERROR_t DIO_toggle(uint8_t portNumber,uint8_t pinNumber);
void EXT_INT0_INIT(void);




#endif /* DIO_H_ */