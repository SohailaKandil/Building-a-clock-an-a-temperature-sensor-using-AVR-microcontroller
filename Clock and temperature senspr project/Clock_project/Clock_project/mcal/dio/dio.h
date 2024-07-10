#ifndef DIO_H_
#define DIO_H_

#define F_CPU 16000000LU
#include <avr/io.h>
#include <util/delay.h>
#include "../../bit_math.h"
#include "../../std_types.h"
#include "dio_types.h"
#include "dio_config.h"

void dio_init(void);
void dio_write(channel_name chanell , dio_dir value);
dio_dir dio_read(channel_name chanell);
void dio_write_port(dio_port port , uint8 level);
void dio_flip(channel_name chanell);

#endif /* DIO_H_ */