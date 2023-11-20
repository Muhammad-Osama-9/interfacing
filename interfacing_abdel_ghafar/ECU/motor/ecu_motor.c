/*
 * ecu_motor.c
 *
 * Created: 11/1/2023 9:56:49 PM
 *  Author: engmu
 */ 

#include "ecu_motor.h"

std_ReturnType ecu_dc_motor_intialize  (const dc_motor_t *dc_motor_ ) 
{
	std_ReturnType ret = E_OK ;
	if (NULL == dc_motor_ )
	{
		ret = E_NOT_OK ; 
	}
	else {
		
		/*
		Pin Object Motor have 2 pins according to spin direction 
	    */
				pin_config_t pin_obj_1 = {
					.port = dc_motor_->dc_motor[0].port ,
					.pin  = dc_motor_->dc_motor[0].pin  ,
					.direction = GPIO_PIN_OUTPUT         ,
					.logic = LOW
				};
				
				pin_config_t pin_obj_2 = {
					.port = dc_motor_->dc_motor[1].port ,
					.pin  = dc_motor_->dc_motor[1].pin  ,
					.direction = GPIO_PIN_OUTPUT         ,
					.logic = LOW
				};
			ret = gpio_pin_intialize(&(dc_motor_->enable_pin) ) ;
			ret = gpio_pin_intialize(&pin_obj_1); 
			ret = gpio_pin_intialize(&pin_obj_2); 
	}
		
	
	return ret ; 
}


std_ReturnType ecu_dc_motor_move_left  (const dc_motor_t *dc_motor_ ) 
{
	std_ReturnType ret = E_OK ;
	if (NULL == dc_motor_ )
	{
		ret = E_NOT_OK ;
	}
	else {
		
		/*
		Pin Object Motor have 2 pins according to spin direction 
	    */
				pin_config_t pin_obj_1 = {
					.port = dc_motor_->dc_motor[0].port ,
					.pin  = dc_motor_->dc_motor[0].pin  ,
					.direction = GPIO_PIN_OUTPUT         ,
					.logic = LOW
				};
				
				pin_config_t pin_obj_2 = {
					.port = dc_motor_->dc_motor[1].port ,
					.pin  = dc_motor_->dc_motor[1].pin  ,
					.direction = GPIO_PIN_OUTPUT         ,
					.logic = LOW
				};
			ret = gpio_pin_write_logic(&(dc_motor_->enable_pin),HIGH);
			ret = gpio_pin_write_logic(&pin_obj_1,LOW) ; 
			ret = gpio_pin_write_logic(&pin_obj_2,HIGH)  ; 
	}
		
	
	return ret ;
}
std_ReturnType ecu_dc_motor_move_right (const dc_motor_t *dc_motor_ ) 
{
	std_ReturnType ret = E_OK ;
	if (NULL == dc_motor_ )
	{
		ret = E_NOT_OK ;
	}
		else 
		{
		/*
		Pin Object Motor have 2 pins according to spin direction 
	    */
				pin_config_t pin_obj_1 = {
					.port = dc_motor_->dc_motor[0].port ,
					.pin  = dc_motor_->dc_motor[0].pin  ,
					.direction = GPIO_PIN_OUTPUT         ,
					.logic = LOW
				    };
				
				pin_config_t pin_obj_2 = {
					.port = dc_motor_->dc_motor[1].port ,
					.pin  = dc_motor_->dc_motor[1].pin  ,
					.direction = GPIO_PIN_OUTPUT         ,
					.logic = LOW
				    };
			ret = gpio_pin_write_logic(&(dc_motor_->enable_pin),HIGH);
			ret = gpio_pin_write_logic(&pin_obj_1,HIGH) ; 
			ret = gpio_pin_write_logic(&pin_obj_2,LOW)  ; 
	    }
	
	return ret ;
}
std_ReturnType ecu_dc_motor_stop  (const dc_motor_t *dc_motor_ ) 
{
	std_ReturnType ret = E_OK ;
	if (NULL == dc_motor_ )
	{
		ret = E_NOT_OK ;
	}
	else {
		
		/*
		Pin Object Motor have 2 pins according to spin direction 
	    */
				pin_config_t pin_obj_1 = {
					.port = dc_motor_->dc_motor[0].port ,
					.pin  = dc_motor_->dc_motor[0].pin  ,
					.direction = GPIO_PIN_OUTPUT         ,
					.logic = LOW
				};
				
				pin_config_t pin_obj_2 = {
					.port = dc_motor_->dc_motor[1].port ,
					.pin  = dc_motor_->dc_motor[1].pin  ,
					.direction = GPIO_PIN_OUTPUT         ,
					.logic = LOW
				};
			ret = gpio_pin_write_logic(&(dc_motor_->enable_pin),HIGH);
			ret = gpio_pin_write_logic(&pin_obj_1,LOW) ; 
			ret = gpio_pin_write_logic(&pin_obj_2,LOW)  ; 
	}
	
	return ret ;
}
