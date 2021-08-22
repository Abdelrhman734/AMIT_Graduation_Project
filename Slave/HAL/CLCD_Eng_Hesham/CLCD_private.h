/*
 * CLCD_private.h
 *
 *  Created on: Feb 3, 2021
 *      Author: Hesham Adel
 */

#ifndef HAL_CLCD_CLCD_PRIVATE_H_
#define HAL_CLCD_CLCD_PRIVATE_H_


/*

  BIT2 = F  Font                        5x7    = 1 / 5x8    = 0
  BIT3 = N  Number Of Display Line      2-Line = 1 / 1-Line = 0
  BIT4 = DL Data Length                 8BIT   = 1 / 4BIT   = 0

 */

#define CLCD_FUNCTION_SET_BIT_COMMEND  0b00111000


/*

  BIT0 = B Cursor Blinking    ON = 1 / OFF = 0
  BIT1 = C Cursor             ON = 1 / OFF = 0
  BIT2 = D Display            ON = 1 / OFF = 0

 */

#define CLCD_DISPLAY_ON_OFF_COMMEND      0b00001100


/*
  BIT0 = SH  Shift             Display  Shift              = 1 / Display  Does  Not     Shift = 0
  BIT1 = I/D Increase/Decrease Increase DDRAM Address By 1 = 1 / Decrease DDRAM Address by 1  = 0

 */

#define CLCD_ENTRY_MODE_SET_COMMEND      0b00000110

#define CLCD_SET_DDRAM_ADDRESS_COMMEDN   0b10000000

#define CLCD_SET_CGRAM_ADDRESS_COMMEND   0b01000000

#endif /* HAL_CLCD_CLCD_PRIVATE_H_ */
