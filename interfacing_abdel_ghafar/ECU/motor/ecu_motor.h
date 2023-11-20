/*
 * ecu_motor.h
 *
 * Created: 11/1/2023 9:56:30 PM
 *  Author: engmu
 */ 


#ifndef ECU_MOTOR_H_
#define ECU_MOTOR_H_
/* Section : includes  */

#include "../../MCAL/GPIO/gpio.h"

/* Section : Macros */
#define DC_MOTOR_STATUS_ON  01UL 
#define DC_MOTOR_STATUS_OFF 00UL

/* Section : User defined Data types */
typedef struct {
uint8 port	   :3 ;
uint8 pin	   :3 ;
uint8 reserved :2 ; 
}dc_motor_pin_t;

typedef struct {	
dc_motor_pin_t dc_motor[2] ; 
pin_config_t   enable_pin   ;
}dc_motor_t;

/*Section : Soft ware interface declaration */

std_ReturnType ecu_dc_motor_intialize  (const dc_motor_t *dc_motor_ )  ;
std_ReturnType ecu_dc_motor_move_left  (const dc_motor_t *dc_motor_ )  ; 
std_ReturnType ecu_dc_motor_move_right (const dc_motor_t *dc_motor_ )  ;
std_ReturnType ecu_dc_motor_stop       (const dc_motor_t *dc_motor_ )  ;

#endif /* ECU_MOTOR_H_ */