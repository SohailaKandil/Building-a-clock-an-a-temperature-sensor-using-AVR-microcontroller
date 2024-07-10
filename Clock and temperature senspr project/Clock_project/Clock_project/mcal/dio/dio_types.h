#ifndef DIO_TYPES_H_
#define DIO_TYPES_H_

typedef enum{
	portb_0,
	portb_1,
	portb_2,
	portb_3,
	portb_4,
	portb_5,
	portb_6,
	portb_7,
	
	portc_0,
	portc_1,
	portc_2,
	portc_3,
	portc_4,
	portc_5,
	portc_6,
	portc_7,
	
	portd_0,
	portd_1,
	portd_2,
	portd_3,
	portd_4,
	portd_5,
	portd_6,
	portd_7,
}channel_name;

typedef enum{
	low,
	high
}dio_dir;

typedef enum {
	pin0,
	pin1,
	pin2,
	pin3,
	pin4,
	pin5,
	pin6,
	pin7
}dio_pin;

typedef enum{
	portb,
	portc,
	portd
}dio_port;

typedef enum{
	input,
	output
}direction_pin;

#endif /* DIO_TYPES_H_ */