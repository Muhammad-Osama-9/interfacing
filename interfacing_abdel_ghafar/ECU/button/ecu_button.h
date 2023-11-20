/*
 * ecu_button.h
 *
 * Created: 11/1/2023 9:56:10 PM
 *  Author: engmu
 */ 


#ifndef ECU_BUTTON_H_
#define ECU_BUTTON_H_

#include "../../MCAL/GPIO/gpio.h"

/*Section : Data types Declaration */
typedef enum {
	BUTTON_ACTIVE_LOW ,
	BUTTON_ACTIVE_HIGH
}button_active_t;
typedef enum {
	BUTTON_PRESSED ,
	BUTTON_UN_PRESSED
}button_state_t;
typedef struct {
	uint8 port_name       :3  ;
	uint8 pin             :3  ;
	uint8 button_state    :1  ;
	uint8 RESERVED        :1  ;
}button_t;

/*Section : functions Declaration */
std_ReturnType ecu_button_intialize (const button_t *button   ) ;
std_ReturnType ecu_button_read_state (const button_t *button  , button_state_t *button_state ) ;




#endif /* ECU_BUTTON_H_ */