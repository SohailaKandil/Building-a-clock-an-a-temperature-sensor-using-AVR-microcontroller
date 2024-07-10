#ifndef DIO_CONFIG_H_
#define DIO_CONFIG_H_

#include "dio_types.h"



#define pin_count 24

typedef struct{
	dio_port port;
	dio_pin pin;
	direction_pin direction;
		
}dio_pin_config;

// we need to define here the pins_configs that is defined in dio_config.c in order to make it readable in dio_config.h
extern dio_pin_config pins_configs [pin_count];
//void dio_config_init(void);
#endif /* DIO_CONFIG_H_ */