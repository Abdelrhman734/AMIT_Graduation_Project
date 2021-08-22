/*
 * EXTI_program.c
 *
 *  Created on: Jun 19, 2021
 *      Author: le
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../DIO/DIO_interface.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

void (*EXTI_CALLBACK[3])(void);

void EXTI_voidSetCallBack( void(*ptr)(void),u8 Copy_u8Line ){

	EXTI_CALLBACK[Copy_u8Line] = ptr;

}

void __vector_1(void){

	EXTI_CALLBACK[0]();

}
void __vector_2(void){

	EXTI_CALLBACK[1]();

}
void __vector_3(void){

	EXTI_CALLBACK[2]();

}

void EXTI_voidInit(void){
  //if there anything still stock on it, like the water you found in shower_heads;
	MCUCR_REG  = 0 ;
	MCUCSR_REG = 0 ;

	#if EXTI_LINE == EXTI_LINE0

		DIO_voidSetPinDirection( PORTD , PIN2 , INPUT );

		MCUCR_REG = EXTI_SENSE_MODE ;

	#elif EXTI_LINE == EXTI_LINE1

		DIO_voidSetPinDirection( PORTD , PIN3 , INPUT );

		MCUCR_REG = EXTI_SENSE_MODE << 2 ;

	#elif EXTI_LINE == EXTI_LINE2

		DIO_voidSetPinDirection( PORTB , PIN2 , INPUT );

		MCUCSR_REG = ( EXTI_SENSE_MODE - 2 ) << 6 ;

	#endif

}

void EXTI_voidSetSignalLatch( u8 Copy_u8Line , u8 Copy_u8Mode ){

	if( Copy_u8Line == EXTI_LINE0 ){

		DIO_voidSetPinDirection( PORTD , PIN2 , INPUT );

		MCUCR_REG = Copy_u8Mode ;

	}else if( Copy_u8Line == EXTI_LINE1 ){

		DIO_voidSetPinDirection( PORTD , PIN3 , INPUT );

		MCUCR_REG = Copy_u8Mode << 2 ;

	}else if (Copy_u8Line == EXTI_LINE2){

		DIO_voidSetPinDirection( PORTB , PIN2 , INPUT );

		MCUCSR_REG = ( Copy_u8Mode - 2 ) << 6 ;

	}

}


void EXTI_voidEnable ( s8 Copy_u8Line ){

	if( Copy_u8Line == EXTI_LINE2 ){ Copy_u8Line -= 3;  }

	SET_BIT( GICR_REG , (Copy_u8Line + 6) );



}

void EXTI_voidDisable( s8 Copy_u8Line ){

	if( Copy_u8Line == EXTI_LINE2 ){ Copy_u8Line -= 3;  }

	CLR_BIT( GICR_REG , (Copy_u8Line + 6) );

}

void EXTI_voidClearFlag ( s8 Copy_u8Line ){

	if( Copy_u8Line == EXTI_LINE2 ){ Copy_u8Line -= 3;  }

	SET_BIT( GIFR_REG , (Copy_u8Line + 6) );

}
