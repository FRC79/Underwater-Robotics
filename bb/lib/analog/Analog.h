#ifndef ANALOG_H
#define ANALOG_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Analog 
{
public:
	string SYSFS_ANA_DIR;

	Analog();

	void exportAllPins();
	int analogRead(int pin);
	void analogWrite(int pin, int value);
};

#endif
