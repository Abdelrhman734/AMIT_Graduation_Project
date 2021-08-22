/*
 * CLCD_interface.h
 *
 *  Created on: Feb 3, 2021
 *      Author: Hesham Adel
 */

#ifndef HAL_CLCD_CLCD_INTERFACE_H_
#define HAL_CLCD_CLCD_INTERFACE_H_


#define CLCD_NOT_USE            0
#define CLCD_USE                1

/* Function Set */

#define CLCD_8_BIT_MODE         1
#define CLCD_4_BIT_MODE         0

#define CLCD_2_LINE             1
#define CLCD_1_LINE             0

#define CLCD_5_7                1
#define CLCD_5_8                0

/* Display ON / OFF */

#define CLCD_DISPLAY_ON         1
#define CLCD_DISPLAY_OFF        0

#define CLCD_CURSOR_ON          1
#define CLCD_CURSOR_OFF         0

#define CLCD_CURSOR_BLINK_ON    1
#define CLCD_CURSOR_BLINK_OFF   0

/* Entry Mode */

#define CLCD_SHIFT_LEFT         0
#define CLCD_SHIFT_RIGHT        1
#define CLCD_DISABLE_SHIFT      2

/* Clear The Entire Display */

#define CLCD_DISPLAY_CLEAR      1

#define CLCD_ROW_1              1
#define CLCD_ROW_2              2

#define CLCD_COL_1              1
#define CLCD_COL_2              2
#define CLCD_COL_3              3
#define CLCD_COL_4              4
#define CLCD_COL_5              5
#define CLCD_COL_6              6
#define CLCD_COL_7              7
#define CLCD_COL_8              8
#define CLCD_COL_9              9
#define CLCD_COL_10             10
#define CLCD_COL_11             11
#define CLCD_COL_12             12
#define CLCD_COL_13             13
#define CLCD_COL_14             14
#define CLCD_COL_15             15
#define CLCD_COL_16             16



void CLCD_voidInit            ( void );
void CLCD_voidWriteCommend    ( u8 Copy_u8Commend );
void CLCD_voidWriteData       ( u8 Copy_u8Data    );

void CLCD_voidWriteString     ( u8 * Copy_u8ptrString );
void CLCD_voidSetPosition     ( u8   Copy_u8Row , u8 Copy_u8Col );
void CLCD_voidWriteNumber     ( u64  Copy_u8Number );

void CLCD_voidWriteExtraChare ( u8 Copy_u8Row , u8 Copy_u8Col , u8 * Copy_u8ExtraChar , u8 Copy_u8CharSize );

#endif /* HAL_CLCD_CLCD_INTERFACE_H_ */
