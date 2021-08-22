/*
 * DIO_program.c
 *
 *  Created on: May 29, 2021
 *      Author: AMIT
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"

void DIO_voidSetPortDirection (u8 Copy_u8Port , u8 Copy_u8Direction){

	switch( Copy_u8Port ){

	case PORTA: DDRA_REG = Copy_u8Direction ; break;
	case PORTB: DDRB_REG = Copy_u8Direction ; break;
	case PORTC: DDRC_REG = Copy_u8Direction ; break;
	case PORTD: DDRD_REG = Copy_u8Direction ; break;

	}

}

void DIO_voidSetPortValue     (u8 Copy_u8Port , u8 Copy_u8Value){

	switch( Copy_u8Port ){

	case PORTA: PORTA_REG = Copy_u8Value ; break;
	case PORTB: PORTB_REG = Copy_u8Value ; break;
	case PORTC: PORTC_REG = Copy_u8Value ; break;
	case PORTD: PORTD_REG = Copy_u8Value ; break;

	}


}


u8   DIO_u8GetPortValue       (u8 Copy_u8Port){

	u8 LOC_u8Result = 0 ;

	switch( Copy_u8Port ){

	case PORTA: LOC_u8Result = PINA_REG ; break;
	case PORTB: LOC_u8Result = PINB_REG ; break;
	case PORTC: LOC_u8Result = PINC_REG ; break;
	case PORTD: LOC_u8Result = PIND_REG ; break;

	}

	return LOC_u8Result ;

}


void DIO_voidSetPinDirection  (u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Direction){

	switch( Copy_u8Port ){

	case PORTA :

		if( Copy_u8Direction == OUTPUT ){ SET_BIT( DDRA_REG , Copy_u8Pin ); }
		else{ CLR_BIT( DDRA_REG , Copy_u8Pin ); }

		break;
	case PORTB :

		if( Copy_u8Direction == OUTPUT ){ SET_BIT( DDRB_REG , Copy_u8Pin ); }
		else{ CLR_BIT( DDRB_REG , Copy_u8Pin ); }

		break;
	case PORTC :

		if( Copy_u8Direction == OUTPUT ){ SET_BIT( DDRC_REG , Copy_u8Pin ); }
		else{ CLR_BIT( DDRC_REG , Copy_u8Pin ); }

		break;
	case PORTD :

		if( Copy_u8Direction == OUTPUT ){ SET_BIT( DDRD_REG , Copy_u8Pin ); }
		else{ CLR_BIT( DDRD_REG , Copy_u8Pin ); }

		break;

	}

}

void DIO_voidSetPinValue      (u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Value){

	switch( Copy_u8Port ){

	case PORTA :

		if( Copy_u8Value == HIGH ){ SET_BIT( PORTA_REG , Copy_u8Pin ); }
		else{ CLR_BIT( PORTA_REG , Copy_u8Pin ); }

		break;
	case PORTB :

		if( Copy_u8Value == HIGH ){ SET_BIT( PORTB_REG , Copy_u8Pin ); }
		else{ CLR_BIT( PORTB_REG , Copy_u8Pin ); }

		break;
	case PORTC :

		if( Copy_u8Value == HIGH ){ SET_BIT( PORTC_REG , Copy_u8Pin ); }
		else{ CLR_BIT( PORTC_REG , Copy_u8Pin ); }

		break;
	case PORTD :

		if( Copy_u8Value == HIGH ){ SET_BIT( PORTD_REG , Copy_u8Pin ); }
		else{ CLR_BIT( PORTD_REG , Copy_u8Pin ); }

		break;

	}

}


u8   DIO_u8GetPinValue        (u8 Copy_u8Port , u8 Copy_u8Pin ){

	u8 LOC_u8Result = 0 ;

	switch( Copy_u8Port ){

	case PORTA : LOC_u8Result = GET_BIT( PINA_REG , Copy_u8Pin ) ; break ;
	case PORTB : LOC_u8Result = GET_BIT( PINB_REG , Copy_u8Pin ) ; break ;
	case PORTC : LOC_u8Result = GET_BIT( PINC_REG , Copy_u8Pin ) ; break ;
	case PORTD : LOC_u8Result = GET_BIT( PIND_REG , Copy_u8Pin ) ; break ;

	}

	return LOC_u8Result ;

}
