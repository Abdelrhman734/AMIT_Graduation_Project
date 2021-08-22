/*
 * LED_program.c
 *
 *  Created on: Jun 4, 2021
 *      Author: Khaled Shitos
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_interface.h"

#include "LED_interface.h"
#include "LED_private.h"
#include "LED_config.h"



void LED_voidOn  ( LED_Type LED_Cfg  ){

	DIO_voidSetPinDirection( LED_Cfg.LED_PORT , LED_Cfg.LED_PIN , OUTPUT );

	if( LED_Cfg.LED_ACTIVE_STATE == LED_ACTIVE_HIGH ){

		DIO_voidSetPinValue( LED_Cfg.LED_PORT , LED_Cfg.LED_PIN , HIGH );

	}else if( LED_Cfg.LED_ACTIVE_STATE == LED_ACTIVE_LOW ) {

		DIO_voidSetPinValue( LED_Cfg.LED_PORT , LED_Cfg.LED_PIN , LOW  );
	}

}
void LED_voidOff ( LED_Type LED_Cfg  ){


	if( LED_Cfg.LED_ACTIVE_STATE == LED_ACTIVE_HIGH ){

		DIO_voidSetPinValue( LED_Cfg.LED_PORT , LED_Cfg.LED_PIN , LOW );

	}else if( LED_Cfg.LED_ACTIVE_STATE == LED_ACTIVE_LOW ) {

		DIO_voidSetPinValue( LED_Cfg.LED_PORT , LED_Cfg.LED_PIN , HIGH );
	}

}

void LED_voidToggle  ( LED_Type LED_Cfg  ){

	DIO_voidSetPinDirection( LED_Cfg.LED_PORT , LED_Cfg.LED_PIN , OUTPUT );
	static u8 LOC_u8Tog = 0 ;

	TOG_BIT( LOC_u8Tog , 0 );

	if( LED_Cfg.LED_ACTIVE_STATE == LED_ACTIVE_HIGH ){


		DIO_voidSetPinValue( LED_Cfg.LED_PORT , LED_Cfg.LED_PIN , LOC_u8Tog );

	}else if( LED_Cfg.LED_ACTIVE_STATE == LED_ACTIVE_LOW ) {

		DIO_voidSetPinValue( LED_Cfg.LED_PORT , LED_Cfg.LED_PIN , LOC_u8Tog  );
	}
}
