/*
 * SPI_program.c


 *
 *  Created on: Jul 6, 2021
 *      Author: mohamed els
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../DIO/DIO_interface.h"

#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"

void SPI_voidMasterInit (void)
{
	 DIO_voidSetPinDirection  (PORTB , PIN5 , OUTPUT);
	 DIO_voidSetPinDirection  (PORTB , PIN6 , INPUT);
	 DIO_voidSetPinDirection  (PORTB , PIN7 , OUTPUT);
	 DIO_voidSetPinDirection  (PORTB , PIN4 , OUTPUT);
	SPCR_REG = 0b01111110;

}

void SPI_voidSlaveInit (void)
{
	DIO_voidSetPinDirection  (PORTB , PIN5 , INPUT);
	DIO_voidSetPinDirection  (PORTB , PIN6 , OUTPUT);
	DIO_voidSetPinDirection  (PORTB , PIN7 , INPUT);
	DIO_voidSetPinDirection  (PORTB , PIN4 , INPUT);
	SPCR_REG = 0b01101100;
}

u8 SPI_u8MasterTransmitReceive (u8 Data)
{
	DIO_voidSetPinValue      (PORTB , PIN4 , 0);
	SPDR_REG = Data;
	while (GET_BIT (SPSR_REG , 7) == 0);
	DIO_voidSetPinValue      (PORTB , PIN4 , 1);
	return SPDR_REG;
}

u8 SPI_u8SlaveTransmitReceive (u8 Data)
{
	SPDR_REG = Data;
	while (GET_BIT (SPSR_REG , 7) == 0);
	return SPDR_REG;
}

void (*SPI)(void);

void SPI_voidMakeMeISR( void(*ptr)(void)){

	SPI = ptr;

}


void __vector_12(void){

	SPI();

}
