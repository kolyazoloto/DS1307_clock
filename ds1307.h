#ifndef DS1307_H_
#define DS1307_H_
#include "main.h"
#include "I2C.h"

unsigned char fromDecToBinDec(unsigned char b){ //Перевод из десятичного вида в двоично-десятичный
	unsigned char h_b = b/10;//Десятки
	unsigned char l_b = b%10;//Единицы
	return (h_b<<4)+l_b;
}
unsigned char fromBinDecToDec(unsigned char b){  //Перевод из двоично-десятичный вида в десятичный
	return (((b>>4)&0b00001111)*10)+(b&0b00001111);  //Делаем десятки и единицы и соединяем
}

#endif /* DS1307_H_ */