/*
 * gpio.h
 *
 * Created: 11/1/2023 9:51:33 PM
 *  Author: engmu
 */ 


#ifndef GPIO_H_
#define GPIO_H_ 

/* Section : includes */

#include "../register_file.h"
#include "../std_library.h"

/* Section : Macros */

#define PIN_A_ADRESS     0x39
#define PIN_B_ADRESS     0x36
#define PIN_C_ADRESS     0x33
#define PIN_D_ADRESS     0x30

#define DDR_A_ADRESS     0x3A
#define DDR_B_ADRESS     0x37
#define DDR_C_ADRESS     0x34
#define DDR_D_ADRESS     0x31


#define PORT_A_ADDRESS   0x3B
#define PORT_B_ADDRESS   0x38
#define PORT_C_ADDRESS   0x35
#define PORT_D_ADDRESS   0x32


#define PORT_PIN_MAX_NUMBER  7
#define PORT_MAX_NUMBER      4
#define BIT_MASK             1

#define  PORT_INPUT   0x00
#define  PORT_OUTPUT  0xFF 
/*Section : Macro Function */

#define CLEAR_BIT(port,pin)     (port&=~(BIT_MASK<<pin))
#define SET_BIT(port,pin)       (port|=(BIT_MASK<<pin))
#define READ_BIT(port,pin)      ((port >> pin) & (BIT_MASK))
#define TOGGLE_BIT(port,pin)    (port^=(BIT_MASK<<pin))

#define TOGGLE_NUM(num)         (num^=-1)

/*Section : User defined Data type*/
typedef enum {
	LOW ,
	HIGH
	
}logic_t;
typedef enum {
	GPIO_PIN_INPUT ,
	GPIO_PIN_OUTPUT
	
}direction_t;
typedef enum {
	GPIO_PORT_INPUT ,
	GPIO_PORT_OUTPUT
	
}direction_port_t;

typedef enum  {
	PIN0 = 0 ,
	PIN1 ,
	PIN2 ,
	PIN3 ,
	PIN4 ,
	PIN5 ,
	PIN6 ,
	PIN7 ,
	
}pins_t;
typedef enum {
	PORTA_INDEX = 0 ,
	PORTB_INDEX,
	PORTC_INDEX,
	PORTD_INDEX,
	
}port_index_t;
typedef struct {
	uint8 port       :3;
	uint8 pin        :3;
	uint8 direction  :1;
	uint8 logic      :1;
}pin_config_t;

typedef struct {
	uint8 port       :3;
	uint8 direction  :1;
	uint8 logic        ;
}port_config_t;


/*Section : Function Declaration */

std_ReturnType gpio_pin_direction_initialize (const pin_config_t *_pin_config  );
std_ReturnType gpio_pin_get_direction_status (const pin_config_t *_pin_config  ,direction_t *dic_stat  );
std_ReturnType gpio_pin_intialize (const pin_config_t *_pin_config );
std_ReturnType gpio_pin_write_logic (const pin_config_t *_pin_config ,logic_t logic   );
std_ReturnType gpio_pin_read_logic (const pin_config_t *_pin_config ,logic_t *logic   );
std_ReturnType gpio_pin_toggle_logic (const pin_config_t *_pin_config   );

std_ReturnType gpio_port_direction_initialize (const port_config_t * _port );
std_ReturnType gpio_port_get_direction_status (const port_index_t port  ,direction_t dic_stat  );

std_ReturnType gpio_port_read_logic (const port_index_t port , uint8 * logic ) ;
std_ReturnType gpio_port_write_logic (const port_config_t * _port  , uint8 logic ) ;
std_ReturnType gpio_port_toggle_logic (const port_index_t port ) ;



#endif /* GPIO_H_ */