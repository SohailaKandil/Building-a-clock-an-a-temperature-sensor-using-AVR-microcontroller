
#ifndef LCD_CFG_H_
#define LCD_CFG_H_
#include "../../mcal/dio/dio_types.h"

//command and data pins of the LCD
#define d7 portb_3
#define d6 portb_2
#define d5 portb_1
#define d4 portb_0

//register status pin to control if command or data and rw pin for read or write and E for trigger enable
#define rs portd_2
#define rw portd_3
#define e  portd_4


#endif /* LCD_CFG_H_ */