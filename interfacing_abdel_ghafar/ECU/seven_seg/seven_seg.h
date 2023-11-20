/*
 * seven_seg.h
 *
 * Created: 11/18/2023 2:11:39 PM
 *  Author: engmu
 */ 


#ifndef SEVEN_SEG_H_
#define SEVEN_SEG_H_
/*  Includes - Section  */

#include "../../MCAL/GPIO/gpio.h"

/*  User defined Data Type  - Section  */
typedef struct {
	uint8 port  :3 ;
	uint8 pin   :3 ;
	
	}seven_seg_pin_t;

typedef struct {
seven_seg_pin_t seven_seg_disp [7] ; 
	
}seven_seg_t ;

std_ReturnType ecu_seven_seg_disp_init (const seven_seg_t *disp ) ;
std_ReturnType ecu_seven_seg_disp_write (const seven_seg_t *disp , uint8 value  ) ;

#endif /* SEVEN_SEG_H_ */