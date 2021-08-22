/*
 * main.c
 *  Created on: Aug 22, 2021
 *      Author: Abdelrhman Nasr eldeen mohamed
 */
#include <stdio.h>
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.H"

#include <util/delay.h>

#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/DIO/DIO_private.h"
#include "../HAL/CLCD_Eng_Hesham/CLCD_interface.h"
#include "../HAL/SW/SW_interface.h"
#include "../HAL/LED/LED_interface.h"
#include "../HAL/SSD/SSD_config.h"
#include "../HAL/SSD/SSD_interface.h"
#include "../MCAL/EXTI/EXTI_interface.h"
#include "../MCAL/EXTI/EXTI_config.h"
#include "../MCAL/GIE/GIE_interface.h"
#include "../MCAL/GIE/GIE_private.h"
#include "../HAL/KBP/KBD_interface.h"
#include "../MCAL/ADC/ADC_interface.h"
#include "../MCAL/ADC/ADC_private.h"
#include "../MCAL/TIM0/TIM0_interface.h"
#include "../MCAL/SPI/SPI_interface.h"
#include "../MCAL/SPI/SPI_private.h"
#include "../MCAL/UART/UART_interface.h"
//MAKING ISR TOGGLE FUNCTION
void toggle (void){
	//TURN ON LED1
	DIO_voidSetPinValue(PORTC,PIN7,HIGH);
	//DELAY FOR THE TOGGLE
	_delay_ms(500);
	//TURN OFF LED1
	DIO_voidSetPinValue(PORTC,PIN7,LOW);
	//DELAY FOR THE TOGGLE
	_delay_ms(500);
}
int main(void){

	//MAKING TOGGLE AN ISR FUNCTION BY MAKING GLOBAL POINTER TO FUNCTION POINT AT IT, PLEASE OPEN SPI_program.C
	SPI_voidMakeMeISR(toggle);

	//SETTING LED0 PIN DIRECTION TO OUTPUT
	DIO_voidSetPinDirection(PORTC,PIN2,OUTPUT);

	//SETTING LED1 PIN DIRECTION TO OUTPUT
	DIO_voidSetPinDirection(PORTC,PIN7,OUTPUT);

	//SETTING LED2 PIN DIRECTION TO OUTPUT
	DIO_voidSetPinDirection(PORTD,PIN3,OUTPUT);

	//ACTIVING SLAVE MODE
	SPI_voidSlaveInit();

	//MAKING EXTERNAL INTERRUPT READY TO GO
	EXTI_voidInit();

	//OPENING GIE FOR THE INTERRUPT
	GIE_voidEnable();

	//MAKING PLACE TO STORE THE DATA IN
	u8 Received_Data = 0;

	//STARTING INFINITY WHILE
	while(1){

		//RECEIVING DATA AND STORING IT
		Received_Data = SPI_u8SlaveTransmitReceive('1');

		//CHECKING DATA IF IT EQUAL TO ONE
		if(Received_Data=='1')
		{

			//ENABLE SPI PIE OR SPI INTERRUPT
			SPCR_REG = 0b11101100;

		}

		//CHECKING DATA IF IT EQUALS TWO
		else if(Received_Data=='2')
		{

			//TURN ON THE THREE LEDS
			DIO_voidSetPinValue(PORTC,PIN2,HIGH);
			DIO_voidSetPinValue(PORTC,PIN7,HIGH);
			DIO_voidSetPinValue(PORTD,PIN3,HIGH);

		}

		//CHECKING DATA IF IT EQUAL TO THREE
		else if(Received_Data=='3')
		{

			//TURN OFF THE THREE LEDS
			DIO_voidSetPinValue(PORTC,PIN2,LOW);
			DIO_voidSetPinValue(PORTC,PIN7,LOW);
			DIO_voidSetPinValue(PORTD,PIN3,LOW);

		}

	}
	//RETURN ZER0 FOR INT MAIN
	return 0;

}
