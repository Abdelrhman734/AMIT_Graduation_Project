/*
 * CLCD_config.h
 *
 *  Created on: Feb 3, 2021
 *      Author: Hesham Adel
 */

#ifndef HAL_CLCD_CLCD_CONFIG_H_
#define HAL_CLCD_CLCD_CONFIG_H_

/*
 Options :-

 	 1-CLCD_USE
 	 2-CLCD_NOT_USE

*/

#define CLCD_USAGE  CLCD_USE

/*

  Options :-

  	  1- DIO_PORTA
  	  2- DIO_PORTB
  	  3- DIO_PORTC
  	  4- DIO_PORTD

 */

#define CLCD_DATA_PORT      PORTA
#define CLCD_CONTROL_PORT   PORTB


/*

  Options :-

  	  1- DIO_PIN0
  	  2- DIO_PIN1
  	  3- DIO_PIN2
  	  4- DIO_PIN3
  	  4- DIO_PIN4
  	  4- DIO_PIN5
  	  4- DIO_PIN6
  	  4- DIO_PIN7

 */


#define CLCD_RS_PIN   PIN1
#define CLCD_RW_PIN   PIN2
#define CLCD_EN_PIN   PIN3


/*

  Options:-

     1- CLCD_4_BIT_MODE
     2- CLCD_8_BIT_MODE

 */


#define CLCD_MODE                CLCD_4_BIT_MODE


/*

  Options:-

     1- CLCD_2_LINE
     2- CLCD_1_LINE

 */


#define CLCD_NUMBER_OF_DISPLAY   CLCD_2_LINE


/*

  Options:-

     1- CLCD_5_7
     2- CLCD_5_8

 */


#define CLCD_FONT_SIZE         CLCD_5_8


/*

  Options:-

     1- CLCD_DISPLAY_ON
     2- CLCD_DISPLAY_OFF

 */


#define CLCD_DISPLAY          CLCD_DISPLAY_ON


/*

  Options:-

     1- CLCD_CURSOR_ON
     2- CLCD_CURSOR_OFF

 */


#define CLCD_CURSOR           CLCD_CURSOR_OFF


/*

  Options:-

     1- CLCD_CURSOR_BLINK_ON
     2- CLCD_CURSOR_BLINK_OFF

 */


#define CLCD_CURSOR_BLINK     CLCD_CURSOR_BLINK_OFF


/*

  Options:-

     1- CLCD_SHIFT_LEFT
     2- CLCD_SHIFT_RIGHT
     3- CLCD_DISABLE_SHIFT

 */


#define CLCD_SHIFT_DIRECTION  CLCD_DISABLE_SHIFT


#endif /* HAL_CLCD_CLCD_CONFIG_H_ */
