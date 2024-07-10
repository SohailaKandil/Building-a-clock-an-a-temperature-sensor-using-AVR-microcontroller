#include "../../mcal/dio/dio.h"
#include "lcd.h"




void lcd_init (void){
 	lcd_send_cmd(0x33);
 	lcd_send_cmd(0x32);
    lcd_send_cmd(lcd_4_bit_mode_2lines_display);
	lcd_send_cmd(lcd_display_and_remove_cursor);
	lcd_send_cmd(lcd_disaple_shifting);
	lcd_send_cmd(lcd_write_ddram);
    lcd_send_cmd(lcd_clear_display);
	_delay_ms(1000);	
}

void trigger_enable (void){
	dio_write (e,high);
	_delay_us(10);
	dio_write (e,low);
	_delay_us(10);
}

void lcd_send_cmd (uint8 cmd){
	//make rs bit low to send a command
	dio_write (rs , low);
	//make rw pin = 0 to write to the LCD
	dio_write (rw , low);
	
	//now read the values f the command and send them serially to the LCD
	//D7
	if (read_bit(cmd , 7) == 1){
		dio_write(d7 , high);
	}else{
		dio_write(d7 , low);
	}
	
	//D6
	if (read_bit(cmd , 6) == 1){
		dio_write(d6 , high);
		}else{
		dio_write(d6 , low);
	}
	
	//D5
	if (read_bit(cmd , 5) == 1){
		dio_write(d5 , high);
		}else{
		dio_write(d5 , low);
	}
	
	//D4
	if (read_bit(cmd , 4) == 1){
		dio_write(d4 , high);
		}else{
		dio_write(d4 , low);
	}
	
	//now trigger the enable to read the first 4 bits of the command
	trigger_enable();
	
	//now send the lower bits
	//D3
	if (read_bit(cmd , 3) == 1){
		dio_write(d7 , high);
		}else{
		dio_write(d7 , low);
	}
	
	//D6
	if (read_bit(cmd , 2) == 1){
		dio_write(d6 , high);
		}else{
		dio_write(d6 , low);
	}
	
	//D5
	if (read_bit(cmd , 1) == 1){
		dio_write(d5 , high);
		}else{
		dio_write(d5 , low);
	}
	
	//D4
	if (read_bit(cmd , 0) == 1){
		dio_write(d4 , high);
		}else{
		dio_write(d4 , low);
	}
	
	trigger_enable();
}



void lcd_send_data (uint8 data){
	//make rs bit high to send data
	dio_write (rs , high);
	//make rw pin = 0 to write to the LCD
	dio_write (rw , low);
	
	//now read the values f the command and send them serially to the LCD
	//D7
	if (read_bit(data , 7) == 1){
		dio_write(d7 , high);
		}else{
		dio_write(d7 , low);
	}
	
	//D6
	if (read_bit(data , 6) == 1){
		dio_write(d6 , high);
		}else{
		dio_write(d6 , low);
	}
	
	//D5
	if (read_bit(data , 5) == 1){
		dio_write(d5 , high);
		}else{
		dio_write(d5 , low);
	}
	
	//D4
	if (read_bit(data , 4) == 1){
		dio_write(d4 , high);
		}else{
		dio_write(d4 , low);
	}
	
	//now trigger the enable to read the first 4 bits of the command
	trigger_enable();
	
	//now send the lower bits
	//D3
	if (read_bit(data , 3) == 1){
		dio_write(d7 , high);
		}else{
		dio_write(d7 , low);
	}
	
	//D6
	if (read_bit(data , 2) == 1){
		dio_write(d6 , high);
		}else{
		dio_write(d6 , low);
	}
	
	//D5
	if (read_bit(data , 1) == 1){
		dio_write(d5 , high);
		}else{
		dio_write(d5 , low);
	}
	
	//D4
	if (read_bit(data , 0) == 1){
		dio_write(d4 , high);
		}else{
		dio_write(d4 , low);
	}
	
	trigger_enable();
}

void lcd_send_number (uint8 num){
	uint8 nchar[16];
    uint8 num_digits = 0;
	if (num == 0){
		lcd_send_data('0');
	}
	else{
		while(num){
			nchar[num_digits] = num % 10 + '0';   // to cast the integer and convert it to a char we add '0' to it
			num = num/10;
			num_digits+=1;
		}
	}
	for (int j=num_digits ; j>0 ; j--){
		lcd_send_data (nchar[j-1]);
	}
}

void lcd_send_string (uint8 * string){
	while(* string != '\0'){
		lcd_send_data(*string++);
		_delay_us(10);
	}
}
void lcd_set_cursor_position (lcd_line x, uint8 y){
	if (y <=0){
		for (int i =0 ; i< y ; i++){
			lcd_send_cmd(shift_all_display_left);
		}
	}
	else if (y>0){
		for (int i =0 ; i< y ; i++){
			lcd_send_cmd(shift_all_display_right);
		}
	}
	
	if (x == 0){
		lcd_send_cmd(shift_all_display_first_line);
		
	}
	else if (x == 1){
		lcd_send_cmd(shift_all_display_second_line);
	}
	_delay_us(500);
}

void lcd_send_string_xy (uint8 * string , lcd_line x, uint8 y){
	lcd_set_cursor_position ( x,  y);
	lcd_send_string(string);
	_delay_us(500);	
}
