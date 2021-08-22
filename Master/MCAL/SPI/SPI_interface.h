/*
 * SPI_interface.h
 *
 *  Created on: Jul 6, 2021
 *      Author: mohamed els
 */

#ifndef MCAL_SPI_SPI_INTERFACE_H_
#define MCAL_SPI_SPI_INTERFACE_H_

void SPI_voidMasterInit (void);

void SPI_voidSlaveInit (void);

u8 SPI_u8MasterTransmitReceive (u8 Data);

u8 SPI_u8SlaveTransmitReceive (u8 Data);




#endif /* MCAL_SPI_SPI_INTERFACE_H_ */
