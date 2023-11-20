/*
 * interfacing_abdel_ghafar.c
 *
 * Created: 11/1/2023 9:44:20 PM
 * Author : engmu
 */ 

//#include <avr/io.h>

#include "ECU/ecu.h"
#define F_CPU  8000000UL
#include <util/delay.h>

uint8 numbers_com_anode [10] = {0xC0 , 0xF9 , 0xA4 , 0xB0,0x99 , 0x92,0x82,0xF8,0x80 , 0x90} ;


int main(void)
{
	
	/*Initialization Section */
	
	port_config_t port1 = {
		.port=PORTA_INDEX ,
		.direction = GPIO_PORT_OUTPUT  , 
		.logic = LOW  		
	} ; 
	
	led_t led2 = {.port_name = PORTC_INDEX,
		.led_status = LOW ,
		.pin = PIN1};
		
	pin_config_t new_pin = {
		.direction= GPIO_PIN_OUTPUT , 
		.port = PORTA_INDEX ,
		.pin = PIN0 ,
		.logic = LOW
		};
		
dc_motor_t motor1 = {
	.dc_motor[0].port = PORTD_INDEX ,
	.dc_motor[1].port = PORTD_INDEX ,
	.dc_motor[0].pin  = PIN0 ,
	.dc_motor[1].pin  = PIN1 ,
	.enable_pin.direction = GPIO_PIN_OUTPUT ,
	.enable_pin .port = PORTD_INDEX ,
	.enable_pin.pin   = PIN4 ,
	.enable_pin.logic = LOW ,
	};
	
	
	led_t led1 = {
	.port_name = PORTC_INDEX,
	.led_status = LOW ,
	.pin = PIN0 
	};
	
	button_t button1 = {
		.port_name = PORTB_INDEX ,
		.pin=PIN0 , 
		.button_state = BUTTON_ACTIVE_HIGH 
	};
	uint8 ret = gpio_pin_intialize(&new_pin) ; 
	ecu_dc_motor_intialize(&motor1) ; 
	ecu_led_initialize(&led1) ; 
	ecu_led_initialize(&led2) ; 
	ecu_button_intialize(&button1);
	 gpio_port_direction_initialize(&port1) ; 
	ret =  gpio_port_write_logic(&port1 , 0xC0) ; 
    /* Replace with your application code */
	//DDRA = 0xFF ; 
	//PORTA = 0x00 ; 
	
	button_state_t button_1_state = BUTTON_UN_PRESSED ; 
	
    if (ret == E_NOT_OK)
	{
		ecu_led_on(&led2) ; 
	}
	for (int i = 0 ; i < 10 ; i ++ )
	{
		gpio_port_write_logic(&port1 , TOGGLE_NUM(numbers_com_anode[i])) ; 
		_delay_ms(500) ; 
	}
	
	while (1) 
    {
	 	ecu_button_read_state(&button1 , &button_1_state) ; 
		if (button_1_state == BUTTON_PRESSED)
		{
			ecu_dc_motor_move_right(&motor1) ; 
				ecu_led_toggle(&led1) ;
				_delay_ms(100) ;
				
		}
		
		else { ecu_led_off(&led1) ; 
			 ecu_dc_motor_stop(&motor1);
		 }  
		
		
		
    }
	
}

