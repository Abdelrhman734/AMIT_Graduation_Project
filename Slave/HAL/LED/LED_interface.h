/*
 * LED_interface.h
 *
 *  Created on: Jun 4, 2021
 *      Author: Khaled Shitos
 */

#ifndef HAL_LED_LED_INTERFACE_H_
#define HAL_LED_LED_INTERFACE_H_

#define LED_ACTIVE_HIGH  1
#define LED_ACTIVE_LOW   0

typedef struct{

	u8 LED_PORT         ;
	u8 LED_PIN          ;
	u8 LED_ACTIVE_STATE ;

}LED_Type;

void LED_voidOn      ( LED_Type LED_Cfg  );
void LED_voidOff     ( LED_Type LED_Cfg  );
void LED_voidToggle  ( LED_Type LED_Cfg  );


#endif /* HAL_LED_LED_INTERFACE_H_ */
