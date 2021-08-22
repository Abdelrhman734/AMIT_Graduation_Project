/*
 * EXTI_interface.h
 *
 *  Created on: Jun 19, 2021
 *      Author: le
 */

#ifndef MCAL_EXTI_EXTI_INTERFACE_H_
#define MCAL_EXTI_EXTI_INTERFACE_H_


#define EXTI_DISABLE       0
#define EXTI_ENABLE        1

#define EXTI_FALLING_EDGE  2
#define EXTI_RISING_EDGE   3
#define EXTI_ON_CHANGE     1
#define EXTI_LOW_LEVEL     0


#define EXTI_LINE0   0  //6
#define EXTI_LINE1   1  //7
#define EXTI_LINE2   2  //5

void EXTI_voidInit(void);

void EXTI_voidSetSignalLatch( u8 Copy_u8Line , u8 Copy_u8Mode );

void EXTI_voidEnable ( s8 Copy_u8Line );

void EXTI_voidDisable( s8 Copy_u8Line );

void EXTI_voidClearFlag ( s8 Copy_u8Line );

void EXTI_voidSetCallBack(void(*ptr)(void),u8 Copy_u8Line);


#endif /* MCAL_EXTI_EXTI_INTERFACE_H_ */
