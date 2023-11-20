/*
 * ecu_button.c
 *
 * Created: 11/1/2023 9:55:54 PM
 *  Author: engmu
 */ 

#include "ecu_button.h"

std_ReturnType ecu_button_intialize (const button_t *button   )
{
	uint8 ret = E_OK ;
	if (NULL == button )
	{
		ret = E_NOT_OK;
	}
	else {
		pin_config_t pin_obj  = {
			.direction = GPIO_PIN_INPUT ,
			.pin = button->pin,
			.port = button->port_name ,
			.logic = LOW
			
		};
		gpio_pin_intialize (&pin_obj) ;
	}
	return ret  ;
	
}



std_ReturnType ecu_button_read_state (const button_t *button  , button_state_t *button_state )
{
	uint8 ret= E_OK ;
	*button_state = BUTTON_UN_PRESSED ;
	logic_t button_logic = LOW ;
	if(NULL == button || NULL == button_state)
	{
		ret= E_NOT_OK ;
	}
	else {
		
		pin_config_t pin_obj  = {
			.direction = GPIO_PIN_INPUT ,
			.pin = button->pin,
			.port= button->port_name ,
			.logic = LOW
			
		};
		ret = gpio_pin_read_logic(&pin_obj , &button_logic );
		
		if (BUTTON_ACTIVE_HIGH == button->button_state)
		{
			if (button_logic == HIGH  )
			{
				*button_state = BUTTON_PRESSED ;
			}
			else {
				*button_state = BUTTON_UN_PRESSED ;
			}
		}
		else if (BUTTON_ACTIVE_LOW == button->button_state)
		{
			if (button_logic == LOW  )
			{
				*button_state = BUTTON_PRESSED ;
			}
			else {
				*button_state = BUTTON_UN_PRESSED ;
			}
			
		}
		else {
			ret = E_NOT_OK ;
		}
		
	}
	return ret ;
	
}
