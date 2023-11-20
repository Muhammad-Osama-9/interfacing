/*
 * gpio.c
 *
 * Created: 11/1/2023 9:52:21 PM
 *  Author: engmu
 */ 
#include "gpio.h"

volatile uint8 *DDR_registers [] = {DDR_A_ADRESS , 
									DDR_B_ADRESS , 
									DDR_C_ADRESS ,
									DDR_D_ADRESS  };
									
volatile uint8 *PIN_registers [] = {PIN_A_ADRESS ,
									PIN_B_ADRESS ,
								    PIN_C_ADRESS , 
									PIN_D_ADRESS } ;
									
volatile uint8 *PORT_registers[]= {PORT_A_ADDRESS ,
								   PORT_B_ADDRESS, 
							   	   PORT_C_ADDRESS ,
								   PORT_D_ADDRESS } ;

std_ReturnType gpio_pin_intialize (const pin_config_t *_pin_config )
{
	uint8 ret = E_OK ;
	if (NULL == _pin_config )
	{
		ret = E_NOT_OK ;
		
	}
	else
	{
		ret =  gpio_pin_direction_initialize(_pin_config) ;
		if (_pin_config->direction == GPIO_PIN_OUTPUT)
		{
			ret =  gpio_pin_write_logic(_pin_config , _pin_config->logic ) ;
		}
		
		
	}
	return ret ;
}

std_ReturnType gpio_pin_direction_initialize (const pin_config_t *_pin_config  )
{
	uint8 ret = E_OK ;
	if(NULL == _pin_config || _pin_config->port >= PORT_MAX_NUMBER || _pin_config->pin >= PORT_PIN_MAX_NUMBER )
	{
		ret =   E_NOT_OK ;
	}
	else
	{
		switch(_pin_config->direction )
		{
			case GPIO_PIN_INPUT :
			CLEAR_BIT(*DDR_registers[_pin_config->port] , _pin_config->pin);
			break ;
			case GPIO_PIN_OUTPUT :
			SET_BIT(*DDR_registers[_pin_config->port] , _pin_config->pin);
			break ;
			default :
			ret =  E_NOT_OK ;
			break ;
			
		}
		
		
	}
	return ret ;
}
std_ReturnType gpio_pin_get_direction_status (const pin_config_t *_pin_config  ,direction_t *dic_stat  )
{
	uint8 ret = E_OK ;
	if(NULL == _pin_config)
	{
		ret =  E_NOT_OK ;
	}
	else
	{
		
		
	}
	
	return ret ;
}

std_ReturnType gpio_pin_write_logic (const pin_config_t *_pin_config ,logic_t logic   )
{
	// _pin_config->logic = logic ;
	uint8 ret = E_OK ;
	if(NULL == _pin_config)
	{
		ret =  E_NOT_OK ;
	}
	else
	{
		switch(logic )
		{
			case GPIO_PIN_INPUT :
			CLEAR_BIT(*PORT_registers[_pin_config->port] , _pin_config->pin);
			break ;
			
			case GPIO_PIN_OUTPUT :
			SET_BIT(*PORT_registers[_pin_config->port] , _pin_config->pin);
			break ;
			
			default :
			ret =  E_NOT_OK ;
			break ;
			
		}
		
	}
	
	return ret ;
}
std_ReturnType gpio_pin_read_logic (const pin_config_t *_pin_config ,logic_t  *logic   )
{
	uint8 ret = E_OK ;
	
	if(NULL == _pin_config ||  NULL == logic )
	{
		ret = E_NOT_OK ;
	}
	else
	{
		*logic =  READ_BIT((*PIN_registers[_pin_config ->port]) , _pin_config ->pin );
	}
	
	return ret ;
	
}
std_ReturnType gpio_pin_toggle_logic (const pin_config_t *_pin_config   )
{
	uint8 ret = E_OK ;
	if(NULL == _pin_config)
	{
		ret =   E_NOT_OK ;
	}
	else
	{
		TOGGLE_BIT(*PORT_registers[_pin_config->port] , _pin_config->pin);
	}
	
	return ret ;
}

std_ReturnType gpio_port_direction_initialize (const port_config_t * _port )
{
	uint8 ret = E_OK ;
	if (NULL == _port)
	{
		
		ret = E_NOT_OK ; 
	}
	else {
		switch (_port->direction)
		{
			
		
		case GPIO_PORT_INPUT :
		*DDR_registers[_port->port] = PORT_INPUT ; 
		
		break  ; 
		
		case GPIO_PORT_OUTPUT :
		*DDR_registers[_port->port] = PORT_OUTPUT ; 
		break ;
		
		default : 
		ret = E_NOT_OK ; 
		break ;  
		}
	}
	
	return ret ;
}
std_ReturnType gpio_port_get_direction_status (const port_index_t port  ,direction_t dic_stat  )
{
	uint8 ret = E_OK ;

	
	return ret ;
}
std_ReturnType gpio_port_read_logic (const port_index_t port , uint8 * logic )
{
	uint8 ret = E_OK ;

	
	return ret ;
}
std_ReturnType gpio_port_write_logic (const port_config_t * _port , uint8 logic )
{
	uint8 ret = E_OK ;
	if ( NULL == _port  )
	{
		
		ret = E_NOT_OK ; 
	}
	else {
		
		*PORT_registers[_port->port] = logic ; 
		ret= E_OK ; 
	}
	return ret ;
}
std_ReturnType gpio_port_toggle_logic (const port_index_t port )
{
	uint8 ret = E_OK ;
	
	return ret ;
}