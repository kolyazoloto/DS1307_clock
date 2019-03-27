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
	//clock.set_datetime(25,12,5,6,12,25,0);

    while (1) 
    {	
		clock.get_datetime();
		lcd.move_cursor(1,1);
		lcd.print(clock.hour/10+'0');
		lcd.print(clock.hour%10+'0');
		lcd.print(':');
		lcd.print(clock.min/10+'0');
		lcd.print(clock.min%10+'0');
		lcd.print(':');
		lcd.print(':');
		lcd.print(clock.sec/10+'0');
		lcd.print(clock.sec%10+'0');
		
    }
}

