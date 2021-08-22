/*
 * TIM0_private.h
 *
 *  Created on: Jul 2, 2021
 *      Author: le
 */

#ifndef MCAL_TIM0_TIM0_PRIVATE_H_
#define MCAL_TIM0_TIM0_PRIVATE_H_

#define TIFR0_REG  *((volatile u8*)0x58)
#define TIMSK0_REG *((volatile u8*)0x59)
#define TCCR0_REG  *((volatile u8*)0x53)
#define OCR0_REG   *((volatile u8*)0x5C)
#define TCNT0_REG  *((volatile u8*)0x52)


void __vector_10(void) __attribute__((signal));
void __vector_11(void) __attribute__((signal));

#endif /* MCAL_TIM0_TIM0_PRIVATE_H_ */
