/*
 * TIM1_private.h
 *
 *  Created on: Jul 9, 2021
 *      Author: user
 */

#ifndef MCAL_TIM1_TIM1_PRIVATE_H_
#define MCAL_TIM1_TIM1_PRIVATE_H_

#define TCCR1A *((volatile u8*)  (0x4F))
#define TCCR1B *((volatile u8*)  (0x4E))
#define TCNT1  *((volatile u16*) (0x4C))
#define OCR1A  *((volatile u16*) (0x4A))
#define ICR1   *((volatile u16*) (0x46))
#define TIMSK  *((volatile u8*)  (0x59))
#define TIFR   *((volatile u8*)  (0x58))
#define OCR1B  *((volatile u16*) (0x48))

void __vector_6(void) __attribute__((signal));
void __vector_9(void) __attribute__((signal));
#endif /* MCAL_TIM1_TIM1_PRIVATE_H_ */
