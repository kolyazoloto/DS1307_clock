#ifndef LCD_1602_H_
#define LCD_1602_H_
#include "main.h"
#include "I2C.h"
class LCD_1602_I2C{
	public:
	LCD_1602_I2C(unsigned char add=0x4E){
		i2c_add = add;
		i2c_init();
		lcd_init();
	}
	void print(char *str)
	{
		while((*str) != '\0')
		{
			print(*str);
			str++;
		}
	}
	void clear_screen(){
		send_command(0x00);
		send_command(0x18);
		_delay_ms(2);
	}
	void move_cursor(unsigned char row,unsigned char columm){
		columm -= 1;
		columm += 64*(row-1);
		columm |= 0b10000000;
		unsigned char data_h = ((columm & 0xF0) + 0x08);//berem pol byte verhnee i dobavlyaem komandu
		unsigned char data_l = (((columm<<4)& 0xF0) + 0x08); //berem pol byte nijnee i dobavlyaem komandu
		send_command(data_h);
		send_command(data_l);
		_delay_us(40);
	}
	void print(unsigned char data){
		unsigned char data_h = ((data & 0xF0) + 0x09);//berem pol byte verhnee i dobavlyaem komandu
		unsigned char data_l = (((data<<4)& 0xF0) + 0x09); //berem pol byte nijnee i dobavlyaem komandu
		//peredaem starshie biti
		send_command(data_h);
		//peredaem mladshie biti
		send_command(data_l);

	}
	private:
	void byte_out(unsigned char data,unsigned char add){
		add &= 0xFE; //poslednii bit vsegda nol'
		i2c_start();
		i2c_sendbyte(add);
		i2c_sendbyte(data);
		i2c_stop();
	}
	void send_command(unsigned char com){
		com |=0x04;  //E on
		byte_out(com,i2c_add);
		com &= 0xFB; // E off
		byte_out(com,i2c_add);
	}
	void lcd_init(void){
		_delay_ms(15); //pausa posle podachi naprajeniya
		send_command(0x30);     //Perehod v chetireh bitnii rejim
		_delay_ms(4); //zaderjka dlya vipolneniya komandi
		send_command(0x30);     //Perehod v chetireh bitnii rejim
		_delay_us(100);
		send_command(0x20);     //Perehod v chetireh bitnii rejim
		_delay_ms(40);
		send_command(0x20); //ustanovka parametrov
		send_command(0x80); //ustanovka parametro
		_delay_us(40);
		send_command(0x00);
		send_command(0x80);
		_delay_us(40);
		send_command(0x00); //ochishaem ekran
		send_command(0x10); //ochishaem ekran
		_delay_ms(2);
		send_command(0x00);
		send_command(0x60);
		_delay_us(40);
		send_command(0x00);
		send_command(0xC0);
		_delay_us(40);
	}

	unsigned char i2c_add;
};
#endif /* LCD_1602_H_ */