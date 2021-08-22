/*
 * SW_program.c
 *
 *  Created on: Jun 4, 2021
 *      Author: Khaled Shitos
 */


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.H"

#include "util/delay.h"
#include "../../MCAL/DIO/DIO_interface.h"

#include "SW_interface.h"
#include "SW_private.h"
#include "SW_config.h"


u8 SW_u8GetPressed( SW_Type SW_Cfg )
{
	u8 LOC_u8Result = 0 ;
	DIO_voidSetPinDirection( SW_Cfg.SW_PORT , SW_Cfg.SW_PIN , INPUT );

	if( SW_Cfg.SW_PULL_STATE == SW_PULL_UP ){

		if(

				DIO_u8GetPinValue( SW_Cfg.SW_PORT , SW_Cfg.SW_PIN ) == 0 ){

			_delay_ms(10);

			if( DIO_u8GetPinValue( SW_Cfg.SW_PORT , SW_Cfg.SW_PIN ) == 0 ){

				LOC_u8Result = 1 ;

			}

		}

	}else{

		if( DIO_u8GetPinValue( SW_Cfg.SW_PORT , SW_Cfg.SW_PIN ) == 1 ){

			_delay_ms(10);

			if( DIO_u8GetPinValue( SW_Cfg.SW_PORT , SW_Cfg.SW_PIN ) == 1 ){

				LOC_u8Result = 1 ;

			}

		}

	}

	return LOC_u8Result ;

}
