/*
 * ADC_program.c
 *
 *  Created on: Jun 26, 2021
 *      Author: user
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "ADC_private.h"
#include "ADC_interface.h"
#include "../DIO/DIO_interface.h"
#include "ADC_config.h"


void ADC_voidINIT(){

	ADMUX_REG  =0b01000000;
	ADCSRA_REG =0b10010111;
}

void ADC_voidSetType(u8 Copy_u8type){
	ADMUX_REG|=Copy_u8type;
}
u16 ADC_u16GetResult(void){
	u16 Result=0;

	#if ADCD  ==  right
			SET_BIT(ADCSRA_REG,6);
			while(GET_BIT(ADCSRA_REG,4)==0);
			SET_BIT(ADCSRA_REG,4);
			Result=(ADCL_REG|(ADCH_REG<<8));

	#elif  ADCD == left
			SET_BIT(ADMUX_REG,5);
			SET_BIT(ADCSRA_REG,6);
			while(GET_BIT(ADCSRA_REG,4)==0);
			SET_BIT(ADCSRA_REG,4);
			Result=(ADCH_REG<<2);
	#endif
	return Result;
}

void ADC_voidSetAutoTrigger(u8 Copy_u8type){
	SET_BIT(ADCSRA_REG,5);

	SFIOR_REG |= Copy_u8type;

}
