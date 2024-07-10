#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define load_reg(reg,val) reg=val
#define set_bit(reg,bit) reg|=(1<<bit)
#define clr_bit(reg,bit) reg&=~(1<<bit)
#define tog_bit(reg,bit) reg^=(1<<bit)
#define rot_left(reg,num) (reg=(reg<<num | reg>>(8-num)))
#define rot_right(reg,num) (reg=reg>>num | reg<<(8-num))
#define read_bit(reg,bit) ((reg>>bit)&0x1)

#endif /* BIT_MATH_H_ */