/*
 * ecu_led.c
 *
 * Created: 11/1/2023 9:54:56 PM
 *  Author: engmu
 */ 
#include "ecu_led.h"

std_ReturnType ecu_led_initialize (const led_t *led)
{
	uint8 ret = E_OK ;
	if (NULL == led )
	{
		ret = E_NOT_OK ;
	}
	else
	{
		pin_config_t pin_obj  = {
			.port = led ->port_name ,
			.direction = GPIO_PIN_OUTPUT ,
			.pin = led->pin ,
			.logic = led->led_status
		} ;
		
		ret =  gpio_pin_intialize(&pin_obj) ;
	}
	return ret ;
}
std_ReturnType ecu_led_off (const led_t *led)
{
	uint8 ret = E_OK ;
	if (NULL == led )
	{
		ret = E_NOT_OK ;
	}
	else
	{
		pin_config_t pin_obj  = {
			.port = led ->port_name ,
			.direction = GPIO_PIN_OUTPUT ,
			.pin = led->pin ,
			.logic = led->led_status
		} ;
		ret  = gpio_pin_write_logic (&pin_obj , LOW );
		
	}
	return ret  ;
}
std_ReturnType ecu_led_on (const led_t *led )
{
	uint8 ret = E_OK ;
	if (NULL == led )
	{
		ret = E_NOT_OK ;
	}
	else
	{
		pin_config_t pin_obj  = {
			.port = led ->port_name ,
			.direction = GPIO_PIN_OUTPUT ,
			.pin = led->pin ,
			.logic = led->led_status
		} ;
		ret  = gpio_pin_write_logic (&pin_obj , HIGH );
	}
	return ret  ;
	
}
std_ReturnType ecu_led_toggle (const led_t *led )
{
	uint8 ret = E_OK ;
	if (NULL == led )
	{
		ret = E_NOT_OK ;
	}
	else
	{
		pin_config_t pin_obj  = {
			.port = led ->port_name ,
			.direction = GPIO_PIN_OUTPUT ,
			.pin = led->pin ,
			.logic = led->led_status
		} ;
		ret = gpio_pin_toggle_logic(&pin_obj) ;
	}
	return ret  ;
}