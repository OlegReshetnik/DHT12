#pragma once
#include <Wire.h>

#define DHT12_DEFAULT_ADDRESS	0x5c // default I2C adress

class Dht12
{
public:
	Dht12( uint8_t address = DHT12_DEFAULT_ADDRESS );
	void read(); // call >= 700 ms period
	float getTemperature(); // read from data, first call read()
	float getHumidity(); // also

private:
	uint8_t Dht12Address;
	uint8_t data[5];
};
