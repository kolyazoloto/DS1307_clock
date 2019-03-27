#ifndef DS1307_H_
#define DS1307_H_
#include "main.h"
#include "I2C.h"
class ds1307{
public:
	ds1307(){
		i2c_init();
		//sec,min,hour,day,date,month,year = 0;
	}
	void set_datetime(unsigned char sec,
					  unsigned char min,
					  unsigned char hour,
					  unsigned char day,
					  unsigned char date,
					  unsigned char mounth,
					  unsigned char year)
	{
		i2c_init();
		i2c_start();
		i2c_sendbyte(0b11010000);
		i2c_sendbyte(0);
		i2c_sendbyte(fromDecToBinDec(sec));//секунды
		i2c_sendbyte(fromDecToBinDec(min));//минуты
		i2c_sendbyte(fromDecToBinDec(hour));//часы
		i2c_sendbyte(fromDecToBinDec(day));//день
		i2c_sendbyte(fromDecToBinDec(date));//дата
		i2c_sendbyte(fromDecToBinDec(month));//месяц
		i2c_sendbyte(fromDecToBinDec(year));//год
		i2c_stop();
	}
	void get_datetime(){
		i2c_start();
		i2c_sendbyte(0b11010000);// Записываем в какую область памяти переходим
		i2c_sendbyte(0);//
		i2c_stop();
		
		i2c_start();
		i2c_sendbyte(0b11010001);// Включаем режим чтения
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
	}
	void get_time(){
		i2c_start();
		i2c_sendbyte(0b11010000);// Записываем в какую область памяти переходим
		i2c_sendbyte(0);//
		i2c_stop();
		
		i2c_start();
		i2c_sendbyte(0b11010001);// Включаем режим чтения
		sec = I2C_ReadByte();
		min = I2C_ReadByte();
		hour = I2C_ReadLastByte();
		i2c_stop();
		
		sec = fromBinDecToDec(sec);
		min = fromBinDecToDec(min);
		hour = fromBinDecToDec(hour);
	}
	void get_date(){
		i2c_start();
		i2c_sendbyte(0b11010000);// Записываем в какую область памяти переходим
		i2c_sendbyte(3);//
		i2c_stop();
		
		i2c_start();
		i2c_sendbyte(0b11010001);// Включаем режим чтения
		day = I2C_ReadByte();
		date = I2C_ReadByte();
		month = I2C_ReadByte();
		year = I2C_ReadLastByte();
		i2c_stop();
		
		day = fromBinDecToDec(day);
		date = fromBinDecToDec(date);
		month = fromBinDecToDec(month);
		year = fromBinDecToDec(year);
	}
	
	unsigned char sec,min,hour,day,date,month,year;
private:
	unsigned char fromDecToBinDec(unsigned char b){ //Перевод из десятичного вида в двоично-десятичный
		unsigned char h_b = b/10;//Десятки
		unsigned char l_b = b%10;//Единицы
		return (h_b<<4)+l_b;
	}
	unsigned char fromBinDecToDec(unsigned char b){  //Перевод из двоично-десятичный вида в десятичный
		return (((b>>4)&0b00001111)*10)+(b&0b00001111);  //Делаем десятки и единицы и соединяем
	}

};


#endif /* DS1307_H_ */