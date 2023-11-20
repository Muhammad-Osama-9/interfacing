/*
 * ecu_led.h
 *
 * Created: 11/1/2023 9:55:32 PM
 *  Author: engmu
 */ 


#ifndef ECU_LED_H_
#define ECU_LED_H_

#include "../../MCAL/GPIO/gpio.h"

typedef enum {
	LED_OFF ,
	LED_ON
}led_stats_t;

typedef struct {
	uint8 port_name  :3  ;
	uint8 pin        :3  ;
	uint8 led_status :1  ;
	uint8 RESERVED   :1  ;
}led_t;

/*Section : Function Declaration*/

std_ReturnType  ecu_led_initialize (const led_t *led) ;
std_ReturnType  ecu_led_off        (const led_t *led) ;
std_ReturnType  ecu_led_on         (const led_t *led );
std_ReturnType  ecu_led_toggle     (const led_t *led );




#endif /* ECU_LED_H_ */