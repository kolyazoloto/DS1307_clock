#ifndef I2C_H_
#define I2C_H_
#include "main.h"
void i2c_init(){
	TWBR = 0x20; //vibor chastoti
}
void i2c_start(){
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while(!(TWCR & (1<<TWINT)));
}
void i2c_stop(){
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
}

void i2c_sendbyte(unsigned char byte){
	TWDR = byte;
	TWCR = (1<<TWINT)|(1<<TWEN);
	while(!(TWCR & (1<<TWINT)));
}
unsigned char I2C_ReadByte(void)
{
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	while (!(TWCR & (1<<TWINT)));//ожидание установки бита TWIN
	return TWDR;//читаем регистр данных
}
unsigned char I2C_ReadLastByte(void)
{
	TWCR = (1<<TWINT)|(1<<TWEN);
	while (!(TWCR & (1<<TWINT)));//ожидание установки бита TWIN
	return TWDR;//читаем регистр данных
}

#endif /* I2C_H_ */