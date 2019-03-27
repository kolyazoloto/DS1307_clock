/*
 * ds1307_clock.cpp
 *
 * Created: 26.03.2019 21:03:16
 * Author : Николай
 */ 

#include "main.h"

int main(void){
	LCD_1602_I2C lcd;
	ds1307 clock;
	//clock.set_datetime(19,03,27,3,23,28,0);

    while (1) 
    {	
		clock.get_time();
		lcd.move_cursor(1,1);
		lcd.print(clock.hour/10+'0');
		lcd.print(clock.hour%10+'0');
		lcd.print(':');
		lcd.print(clock.min/10+'0');
		lcd.print(clock.min%10+'0');
		lcd.print(':');
		lcd.print(clock.sec/10+'0');
		lcd.print(clock.sec%10+'0');
		
    }
}

