#include "Dht12.h"

Dht12::Dht12( uint8_t address )
{
	Dht12Address = address;
	Wire.begin();
}

void Dht12::read()
{
	Wire.beginTransmission( Dht12Address );
	Wire.write(0);
	Wire.endTransmission();
	Wire.requestFrom( Dht12Address, (uint8_t)5 );
	uint8_t i = 0;
	while( Wire.available() && i<5 ) data[i++] = Wire.read();
}

float Dht12::getTemperature()
{
	return data[2] + (float)data[3] / 10;
}

float Dht12::getHumidity()
{
	return data[0] + (float)data[1] / 10;
}
