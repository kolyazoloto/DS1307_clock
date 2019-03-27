#ifndef DS1307_H_
#define DS1307_H_
#include "main.h"
#include "I2C.h"

unsigned char fromDecToBinDec(unsigned char b){ //������� �� ����������� ���� � �������-����������
	unsigned char h_b = b/10;//�������
	unsigned char l_b = b%10;//�������
	return (h_b<<4)+l_b;
}
unsigned char fromBinDecToDec(unsigned char b){  //������� �� �������-���������� ���� � ����������
	return (((b>>4)&0b00001111)*10)+(b&0b00001111);  //������ ������� � ������� � ���������
}

#endif /* DS1307_H_ */