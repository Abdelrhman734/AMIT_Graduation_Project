/*
 * ADC_private.h
 *
 *  Created on: Jun 26, 2021
 *      Author: user
 */

#ifndef MCAL_ADC_ADC_PRIVATE_H_
#define MCAL_ADC_ADC_PRIVATE_H_

#define ADMUX_REG     *((volatile u8 *)0x27)
#define ADCSRA_REG     *((volatile u8 *)0x26)
#define ADCH_REG     *((volatile u8 *)0x25)
#define ADCL_REG     *((volatile u8 *)0x24)
#define SFIOR_REG     *((volatile u8 *)0x50)

#endif /* MCAL_ADC_ADC_PRIVATE_H_ */
