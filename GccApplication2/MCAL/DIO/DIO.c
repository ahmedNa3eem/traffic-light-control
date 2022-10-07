/*
 * DIO.c
 *
 * Created: 9/18/2022 12:17:38 AM
 *  Author: ahmed
 */ 
#include"DIO.h"

EN_DIOERROR_t DIO_init(uint8_t portNumber, uint8_t pinNumber, uint8_t direction){
	//make sure that pinNumber is less than 7 and if it is bigger return error
	if(pinNumber>7){
		return pinNumber_ERROR;
	}
	//check for the direction (IN or OUT)
	if(direction==IN){
		//in case of (IN) check the portNumber
		switch(portNumber){
            //in the DDR register of the PORT set the pinNumber bit to 0 & return DIO_OK
			case A:
			DDRA &= ~(1<<pinNumber);
			return DIO_OK;
			break;
			case B:
			DDRB &= ~(1<<pinNumber);
			return DIO_OK;
			break;
			case C:
			DDRC &= ~(1<<pinNumber);
			return DIO_OK;
			break;
			case D:
			DDRD &= ~(1<<pinNumber);
			return DIO_OK;
			break;
			//if the portNumber isn't exist return ERROR
			default:
			return portNumber_ERROR;
			break;
		}
		}else if(direction==OUT){
			//in case of (OUT) check the portNumber
		switch(portNumber){
			//in the register of PORT set the pinNumber bit to 1 & return DIO_OK
			case A:
			DDRA |= (1<<pinNumber);
			return DIO_OK;
			break;
			case B:
			DDRB |= (1<<pinNumber);
			return DIO_OK;
			break;
			case C:
			DDRC |= (1<<pinNumber);
			return DIO_OK;
			break;
			case D:
			DDRD |= (1<<pinNumber);
			return DIO_OK;
			break;
			//if the portNumber isn't exist return ERROR
			default:
			return portNumber_ERROR;
			break;
		}
		
	}else{
		//return direction error if the direction is not IN or OUT
		return direction_ERROR;
	}
}
EN_DIOERROR_t DIO_write(uint8_t portNumber, uint8_t pinNumber, uint8_t value){
	//make sure that pinNumber is less than 7 and if it is bigger return error
	if(pinNumber>7){
		return pinNumber_ERROR;
	}
	//check the value (LOW or HIgh)
	if(value==LOW){
		//if the value is LOW check the portNumber
		switch(portNumber){
			//in the PORT register of the portNumber set the pinNumber bit to 0 & return DIO_OK
			case A:
			PORTA &= ~(1<<pinNumber);
			return DIO_OK;
			break;
			case B:
			PORTB &= ~(1<<pinNumber);
			return DIO_OK;
			break;
			case C:
			PORTC &= ~(1<<pinNumber);
			return DIO_OK;
			break;
			case D:
			PORTD &= ~(1<<pinNumber);
			return DIO_OK;
			break;
			//if the portNumber isn't found return error
			default:
			return portNumber_ERROR;
			break;
		}
		}else if(value==HIGH){
			//if the value is HIGH check the portNumber
		switch(portNumber){
			//in the PORT register of the portNumber set the pinNumber bit to 1 & return DIO_OK
			case A:
			PORTA |= (1<<pinNumber);
			return DIO_OK;
			break;
			case B:
			PORTB |= (1<<pinNumber);
			return DIO_OK;
			break;
			case C:
			PORTC |= (1<<pinNumber);
			return DIO_OK;
			break;
			case D:
			PORTD |= (1<<pinNumber);
			return DIO_OK;
			break;
			//if the portNumber isn't found, return ERROR
			default:
			return portNumber_ERROR;
			break;
		}
		
	}else{
		//else return ERROR
		return value_ERROR;
	}
	
}
EN_DIOERROR_t DIO_read( uint8_t portNumber, uint8_t pinNumber, uint8_t *value){
	
	//make sure that pinNumber is less than 7 and if it is bigger return error
	if(pinNumber>7){
		return pinNumber_ERROR;
	}
	
	//check the portNumber  and pinNubmer
	switch(portNumber){
		//in the PIN register of portNumber read the pinNumber bit and save the result in a pointer & return DIO_OK
		case A:
		*value=(PINA & (1<<pinNumber))>>pinNumber;
		return DIO_OK;
		break;
		case B:
		*value=(PINB & (1<<pinNumber))>>pinNumber;
		return DIO_OK;
		break;
		case C:
		*value=(PINC & (1<<pinNumber))>>pinNumber;
		return DIO_OK;
		break;
		case D:
		*value=(PIND & (1<<pinNumber))>>pinNumber;
		return DIO_OK;
		break;
		//if the portNumber is not found return ERROR  
		default:
		return portNumber_ERROR;
		break;
	}
	
}
EN_DIOERROR_t DIO_toggle(uint8_t portNumber,uint8_t pinNumber){
	//check the portNumber and pinNumber
	//make sure that pinNumber is less than 7 and if it is bigger return error
	if(pinNumber>7){
		return pinNumber_ERROR;
	}
	switch(portNumber){
		//if the pinNumber bit in the PORT register of the portNumber is 1 change it to 0 and vice versa
		case A:
		PORTA ^= (1<<pinNumber);
		return DIO_OK;
		break;
		case B:
		PORTB ^= (1<<pinNumber);
		return DIO_OK;
		break;
		case C:
		PORTC ^= (1<<pinNumber);
		return DIO_OK;
		break;
		case D:
		PORTD ^= (1<<pinNumber);
		return DIO_OK;
		break;
		default:
		return portNumber_ERROR;
		break;
	}
}
void EXT_INT0_INIT(void){
	//enable the global interrupt
	SREG |= (1<<7);
	MCUCR=3;
	//enable the external INT0
	GICR |= (1<<6);
}

