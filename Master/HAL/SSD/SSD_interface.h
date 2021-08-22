/*
 * SSD_interface.h
 *
 *  Created on: Jun 5, 2021
 *      Author: user
 */

#ifndef DIO_HAL_SSD_SSD_INTERFACE_H_
#define DIO_HAL_SSD_SSD_INTERFACE_H_

#define SSD_A        0
#define SSD_B        1
#define SSD_DISABLE  2

void SSD_voidInit( void );

void SSD_voidEnableA  (void);
void SSD_voidEnableB  (void);
void SSD_voidDisbaleA (void);
void SSD_voidDisbaleB (void);
void SSD_voidSendNumber( u8 Copy_u8Number );
void SSD_voidSendTwoNumbers( u8 Number1,u8 Number2 );

#endif /* DIO_HAL_SSD_SSD_INTERFACE_H_ */
