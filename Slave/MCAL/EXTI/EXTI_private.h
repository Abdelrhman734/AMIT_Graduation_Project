/*
 * EXTI_private.h
 *
 *  Created on: Jun 19, 2021
 *      Author: le
 */

#ifndef MCAL_EXTI_EXTI_PRIVATE_H_
#define MCAL_EXTI_EXTI_PRIVATE_H_

#define MCUCR_REG    *((volatile u8 *)0x55)
#define MCUCSR_REG   *((volatile u8 *)0x54)

#define GICR_REG     *((volatile u8 *)0x5B)
#define GIFR_REG     *((volatile u8 *)0x5A)

void __vector_1(void) __attribute__((signal));

#endif /* MCAL_EXTI_EXTI_PRIVATE_H_ */
