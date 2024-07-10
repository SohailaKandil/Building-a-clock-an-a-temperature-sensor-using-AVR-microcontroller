#include "dio_config.h"
#include "dio.h" 


dio_pin_config pins_configs [pin_count] = {
	//portb
	{portb , pin0 , output },
	{portb , pin1 , output },
	{portb , pin2 , output },
	{portb , pin3 , output },
	{portb , pin4 , output },
	{portb , pin5 , output },
	{portb , pin6 , output },
	{portb , pin7 , output },
	
	//portc	
	{portc , pin0 , input },
	{portc , pin1 , output },
	{portc , pin2 , output },
	{portc , pin3 , output },
	{portc , pin4 , output },
	{portc , pin5 , output },
	{portc , pin6 , output },
	{portc , pin7 , output },
	
	//portd	
	{portd , pin0 , output },
	{portd , pin1 , output },
	{portd , pin2 , output },
	{portd , pin3 , output },
	{portd , pin4 , output },
	{portd , pin5 , output },
	{portd , pin6 , output },
	{portd , pin7 , output }		
};






