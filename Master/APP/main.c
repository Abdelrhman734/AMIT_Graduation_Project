/*
 * main.c
 *
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
#include "../MCAL/UART/UART_interface.h"

int main(void){
	// SETTING LED0 PIN (PC2) DIRECTION TO OUTPUT
	DIO_voidSetPinDirection(PORTC,PIN2,OUTPUT);

	//SETTING UART TRASMITTING PIN (Tx) (PD1) TO OuTPUT
	DIO_voidSetPinDirection(PORTD,PIN1,OUTPUT);

	//SETTING UART RECIEVING PIN (Rx) (PD0) TO INPUT
	DIO_voidSetPinDirection(PORTD,PIN0,INPUT);

	//UART INITIALIZATION
	UART_VoidInit();

	//SPI MASTER INITIALIZATION
	SPI_voidMasterInit();

	//CREATING VARIABLE TO STORE THE DATA WE WILL RECIEVE FROM BLUETOOTH
	u8 mobile_to_slave;

	//STARTIN THE PROGRAM
	while(1){

		//RECIEVING THE DATA FROM BLUETOOTH IN flag VARIABLE
		mobile_to_slave=UART_VoidRecieve();

		//SENDING DATA BY SPI PROTOCOL TO ThE OTHER MICRO
		SPI_u8MasterTransmitReceive(mobile_to_slave);

		//TURN LED0 ON IF DATA EQUAL 1 AND TURN IT OFF WHEN DATA EQUAL 0
		if(mobile_to_slave=='1') {DIO_voidSetPinValue(PORTC,PIN2,HIGH);}

		else if(mobile_to_slave=='0')
		{

			DIO_voidSetPinValue(PORTC,PIN2,LOW);

		}

	}

	//RETURN ZER0 FOR INT MAIN
	return 0;

}
