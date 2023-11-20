/*
 * std_library.h
 *
 * Created: 11/1/2023 9:48:57 PM
 *  Author: engmu
 */ 


#ifndef STD_LIBRARY_H_
#define STD_LIBRARY_H_


typedef unsigned char    uint8  ;
typedef char             sint8  ;
typedef unsigned short   uint16 ;
typedef short            sint16 ;
typedef unsigned long    uint32 ;
typedef long             sint32 ;

typedef uint8    std_ReturnType ;
/*****************************************/

/*Section : Macros */

#define STD_ON  0x01
#define STD_OFF 0x00

#define E_OK    (std_ReturnType)0x01
#define E_NOT_OK   (std_ReturnType)0x00
#define NULL 0



#endif /* STD_LIBRARY_H_ */