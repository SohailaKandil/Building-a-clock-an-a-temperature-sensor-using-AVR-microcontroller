#ifndef LCD_H_
#define LCD_H_

#include "../../std_types.h"
#include "lcd_cfg.h"

typedef enum{
	first_line,
	second_line
}lcd_line;

void lcd_init (void);
void lcd_send_cmd (uint8 cmd);
void lcd_send_data (uint8 data);
void lcd_send_number (uint8 num);
void lcd_send_string (uint8 * string);
void lcd_set_cursor_position (lcd_line x, uint8 y);
void lcd_send_string_xy (uint8 * string , lcd_line x, uint8 y);
void trigger_enable (void);


// the commands of the lcd
#define lcd_clear_display 0x01
#define lcd_return_home 0x02
#define lcd_disaple_shifting 0x04
#define lcd_display_and_remove_cursor 0x0C
#define lcd_left_to_right 0x14
#define lcd_write_ddram   0x80
#define lcd_4_bit_mode_2lines_display   0x2C //****

#define shift_all_display_left  0x18
#define shift_all_display_right 0x1C
#define shift_all_display_second_line 0xC0
#define shift_all_display_first_line 0x80
	
#endif /* LCD_H_ */