/*
 * SPI_private.h
 *
 *  Created on: Jul 6, 2021
 *      Author: mohamed els
 */

#ifndef MCAL_SPI_SPI_PRIVATE_H_
#define MCAL_SPI_SPI_PRIVATE_H_

#define SPCR_REG *( (volatile u8 *)0x2D )
#define SPSR_REG *( (volatile u8 *)0x2E )
#define SPDR_REG *( (volatile u8 *)0x2F )

void __vector_12(void) __attribute__((signal));

#endif /* MCAL_SPI_SPI_PRIVATE_H_ */
