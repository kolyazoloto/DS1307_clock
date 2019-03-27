/*
 * ds1307_clock.cpp
 *
 * Created: 26.03.2019 21:03:16
 * Author : Николай
 */ 

#include "main.h"

int main(void)
{
	/*i2c_init();
	i2c_start();
	i2c_sendbyte(0b11010000);
	i2c_sendbyte(0);
	i2c_sendbyte(fromDecToBinDec(00));//секунды
	i2c_sendbyte(fromDecToBinDec(17));//минуты
	i2c_sendbyte(fromDecToBinDec(19));//часы
	i2c_sendbyte(fromDecToBinDec(3));//день
	i2c_sendbyte(fromDecToBinDec(27));//дата
	i2c_sendbyte(fromDecToBinDec(3));//месяц
	i2c_sendbyte(fromDecToBinDec(19));//год
	i2c_stop();*/
	
	LCD_1602_I2C lcd(0x4E);
	i2c_init();
	
	

	unsigned char sec;
	unsigned char min;
	unsigned char hour;
	unsigned char day;
	unsigned char date;
	unsigned char month;
	unsigned char year ;
    while (1) 
    {
		lcd.move_cursor(1,1);
		i2c_start();
		i2c_sendbyte(0b11010000);//вначале нужно записать куда в память переходим
		i2c_sendbyte(0);//
		i2c_stop();
	
		
		i2c_start();
		i2c_sendbyte(0b11010001);
		sec = I2C_ReadByte();
		min = I2C_ReadByte();
		hour = I2C_ReadByte();
		day = I2C_ReadByte();
		date = I2C_ReadByte();
		month = I2C_ReadByte();
		year = I2C_ReadLastByte();
		i2c_stop();
		
		sec = fromBinDecToDec(sec);
		min = fromBinDecToDec(min);
		hour = fromBinDecToDec(hour);
		day = fromBinDecToDec(day);
		date = fromBinDecToDec(date);
		month = fromBinDecToDec(month);
		year = fromBinDecToDec(year);
		lcd.print(hour/10+'0');
		lcd.print(hour%10+'0');
		lcd.print(':');
		lcd.print(min/10+'0');
		lcd.print(min%10+'0');
		lcd.print(':');
		lcd.print(sec/10+'0');
		lcd.print(sec%10+'0');
		lcd.move_cursor(2,1);
		lcd.print(date/10+'0');
		lcd.print(date%10+'0');

		
    }
}

