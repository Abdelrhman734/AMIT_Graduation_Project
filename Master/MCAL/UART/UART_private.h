/*
 * UART_private.h
 *
 *  Created on: Jul 16, 2021
 *      Author: user
 */

#ifndef MCAL_UART_UART_PRIVATE_H_
#define MCAL_UART_UART_PRIVATE_H_

#define UDR    *((volatile u8*)  0x2C)
#define UCSRA  *((volatile u8*)  0x2B)
#define UCSRB  *((volatile u8*)  0x2A)
#define UCSRC  *((volatile u8*)  0x40)
#define UBRRL  *((volatile u8*)  0x29)
#define UBRRH  *((volatile u8*)  0x40)


#endif /* MCAL_UART_UART_PRIVATE_H_ */
