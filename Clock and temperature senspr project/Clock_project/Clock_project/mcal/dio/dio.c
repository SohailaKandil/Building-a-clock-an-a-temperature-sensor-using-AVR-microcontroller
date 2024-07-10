#include "dio.h"



void dio_init (void){
	for (int i = 0 ; i<pin_count ; i++){
		//if portb
		if (pins_configs[i].port == portb){
			if (pins_configs[i].direction == output){
				set_bit (DDRB , pins_configs[i].pin);
				}else{
				clr_bit (DDRB , pins_configs[i].pin);
			}
		}
		
		//if portc
		else if (pins_configs[i].port == portc){
			if (pins_configs[i].direction == output){
				set_bit (DDRC , pins_configs[i].pin);
				}else{
				clr_bit (DDRC , pins_configs[i].pin);
			}
		}
		
		//if portd
		else if (pins_configs[i].port == portd){
			if (pins_configs[i].direction == output){
				set_bit (DDRD , pins_configs[i].pin);
				}else{
				clr_bit (DDRD , pins_configs[i].pin);
			}
		}
	}
}

void dio_write(channel_name chanell , dio_dir value){
	dio_port port = chanell / 8;
	dio_pin pin = chanell % 8;
	//on portb
	if (port == portb){
		if (value == high){
			set_bit(PORTB , pin);
		}else{
			clr_bit(PORTB , pin);
		}
	}
	
	//on portc
	else if (port == portc){
		if (value == high){
			set_bit(PORTC , pin);
			}else{
			clr_bit(PORTC , pin);
		}
	}
	
	//on portd
	else if (port == portd){
		if (value == high){
			set_bit(PORTD , pin);
			}else{
			clr_bit(PORTD , pin);
		}
	}
}


dio_dir dio_read(channel_name chanell){
	dio_port port = chanell / 8;
	dio_pin pin = chanell % 8;
	dio_dir status = low;
	
	//on portb
	if (port == portb){
		status = read_bit(PINB,pin);
	}
	
	//on portc
	else if (port == portc){
		status = read_bit(PINC,pin);
	}
	
	//on portd
	else if (port == portd){
		status = read_bit(PIND,pin);
	}
	
	return status;
}

void dio_write_port(dio_port port , uint8 level){
	//on portb
	if (port == portb){
		PORTB = level;
	}
	
	//on portc
	else if (port == portc){
		PORTC = level;
	}
	
	//on portd
	else if (port == portd){
		PORTD = level;
	}
}

void dio_flip(channel_name chanell){
	dio_port port = chanell / 8;
	dio_pin pin = chanell % 8;
	//on portb
	if (port == portb){
		tog_bit(PORTB , pin);
	}
	
	//on portc
	else if (port == portc){
		tog_bit(PORTC , pin);
	}
	
	//on portd
	else if (port == portd){
		tog_bit(PORTD , pin);
	}
}
