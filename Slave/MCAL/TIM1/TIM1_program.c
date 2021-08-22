/*

 * TIM1_program.c
 *
 *  Created on: Jul 9, 2021
 *      Author: user


#include "TIM1_interface.h"
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

u32 volatile counter=0;
u32 volatile snap1=0;
u32 volatile snap2=0;
u32 volatile snap3=0;
u32 volatile flag=0;
u32 volatile freq=0;
u32 volatile DC=0;

void __vector_9(void){
	counter++;
}



void __vector_6(void){
	if(flag==0){
		snap1=ICR1;
		CLR_BIT(TCCR1B,6);
		counter=0;
	}

	else if(flag==1){
		snap2=ICR1+(counter*65536);
		SET_BIT(TCCR1B,6);
	}
	else if(flag==2){
		snap3=ICR1+(counter*65536);
		CLR_BIT(TIMSK,5);
		CLR_BIT(TIMSK,2);
	}


	flag++;
}
*/
