#include "bit_math.h"
#include "std_types.h"
#include "mcal/dio/dio.h"
#include "hal/lcd/lcd.h"
#include <avr/interrupt.h>

uint8 hours = 11;
uint8 min = 59;
uint8 sec = 50;

void init_timer1 (void){
	TCNT1L  =  0x00;
	TCNT1H  =  0x00;//reset these registers to start counting from 0
	
    TCCR1A  =  0x00;
	set_bit(TCCR1B , CS12);   //make the prescaler = /256
	set_bit(TCCR1B , WGM12);  // make it work in the ctc mode
	TCCR1C  =  0x00;
	
	OCR1A = 62499;
	
	//TCNT1L  =  0xC2;
	//TCNT1L  =  0xD8;

	set_bit(TIMSK1 , OCIE1A);  // enable the timer1 interrupt
	sei(); // set the interrupt bit in the SREG
}

//********************

ISR (TIMER1_COMPA_vect){
	dio_write(portc_5 , low);

	load_reg(TCNT1L , 0xC2);
	load_reg(TCNT1L , 0xD8);  //reset the TCNT1 reg to make another interrupt in the coming cycle
	
	if (sec==60 && min == 59){
		sec=0;
		min=0;
		hours +=1;
		dio_write(portc_5 , high);
	}
	
	else if(sec == 60){
		sec=0;
		min+=1;
		dio_write(portc_5 , high);
	}
	
	else if (min == 60){
		min = 0;
		hours+=1;
	}
	
	lcd_set_cursor_position(second_line , 0);
	if (hours <= 9)  {
		lcd_send_number(0);
	}
	lcd_send_number (hours);
	lcd_send_data (':');
	if (min <= 9)  {
		lcd_send_number(0);
	}
	lcd_send_number (min);
	lcd_send_data (':');
	if (sec <= 9)  {
		lcd_send_number(0);
	}
	lcd_send_number (sec );
	_delay_ms(1000);
	sec+=1;
	
	TCNT1L  =  0x00;
	TCNT1H  =  0x00;
	set_bit(TIFR1 , OCF1A);
	
}
void init_ADC(void)
{
	set_bit(ADCSRA , ADEN);  // to set the ADC enable
	
	set_bit(ADCSRA , ADPS0);
	set_bit(ADCSRA , ADPS1);
	set_bit(ADCSRA , ADPS2);//these three bits are set to make the prescaler = 1
	
	set_bit(ADMUX , REFS0);
	set_bit(ADMUX , REFS1); // to select a the vref to be internal = 1.1
	clr_bit(ADCSRA , ADLAR);  // to make the result in ADCL and the remaining in ADCH
	
	set_bit(ADCSRA , ADSC);//set this bit to start conversion	
}

uint8 ADC_READ(void)
{
	while(read_bit(ADCSRA , ADIF) == 0); //wait for conversion to finish
	
	uint8 low_adc_bits = ADCL;
	uint8 high_adc_bits = ADCH;

	uint8  ADC_read_val =(low_adc_bits|(high_adc_bits<<8)) * 10/93;//PORTB
	return ADC_read_val;
	
	set_bit(ADCSRA , ADIF);
}

void print_temp_lcd(uint8 ADC_read_val){
	
	if (ADC_read_val > 60) {
		dio_write(portd_5 , low); // Output 0 PORTD Pin 5 (buzzer)
		dio_write(portb_4 , high); // make the led high  
	}
	
	if (ADC_read_val < 60) {
		dio_write(portd_5 , high); // Output high on PORTD Pin 5 (buzzer)
		dio_write(portb_4 , low); // make the led low
	}
	
	lcd_set_cursor_position(first_line, 0);
	lcd_send_string("Temperature:");
	lcd_send_number(ADC_read_val);
	lcd_send_data('C');
}


//********************************************
int main(void)
{
	dio_init ();
	lcd_init();
	init_timer1();
	init_ADC();
	
	//uint8 num=0;
    while (1){
		uint8 temperature = ADC_READ();
		print_temp_lcd(temperature);
		_delay_ms(500);
// 		num+=1;
// 		lcd_set_cursor_position(first_line , 0);
// 		lcd_send_number(num);
// 		_delay_ms(500);

	}		
}
