/*
 * registers.h
 *
 * Created: 9/17/2022 9:27:17 PM
 *  Author: ahmed
 */ 


#ifndef REGISTERS_H_
#define REGISTERS_H_
typedef unsigned char uint8_t;
//PORTA
#define PORTA *((volatile uint8_t* )0x3B)
#define DDRA *((volatile uint8_t* )0x3A)
#define PINA *((volatile uint8_t* )0x39)
//PORTB
#define PORTB *((volatile uint8_t* )0x38)
#define DDRB *((volatile uint8_t* )0x37)
#define PINB *((volatile uint8_t* )0x36)
//PORTC
#define PORTC *((volatile uint8_t* )0x35)
#define DDRC *((volatile uint8_t* )0x34)
#define PINC *((volatile uint8_t* )0x33)
//PORTD
#define PORTD *((volatile uint8_t* )0x32)
#define DDRD *((volatile uint8_t* )0x31)
#define PIND *((volatile uint8_t* )0x30)
//TIMER0
#define TCNT0 *((volatile uint8_t* )0x52)
#define TCCR0 *((volatile uint8_t* )0x53)
#define TIFR *((volatile uint8_t* )0x58)
//EXT_INT
#define MCUCR *((volatile uint8_t* )0x55)
#define GIFR *((volatile uint8_t* )0x5A)
#define GICR *((volatile uint8_t* )0x5B)
//GLOBAL_INT
#define SREG *((volatile uint8_t* )0x5F)







#endif /* REGISTERS_H_ */