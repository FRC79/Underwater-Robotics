#ifndef GPIO_H
#define GPIO_H

#include <cstdlib>
#include <string>
#include <string.h>
#include <map>
#include <iostream>
using namespace std;

class GPIO 
{
	/*	The GPIO class is used for communicating between the BB's IO
		system that controls input and output pins, how they are configured,
		and interacting with them. The class gives a high level of control
		as opposed to the difficulty and length of managing the IO manually. 

		Based on code by Matt Richardson on Github
		https://github.com/mrichardson23/mrBBIO		*/

public:
	// Constants
	static const string LOW = "LOW";
	static const stirng HIGH = "HIGH";
	static const string INPUT = "INPUT";
	static const string OUTPUT = "OUTPUT";

	/* Digital pins */
	static const unsigned char P8_3_DIG = 38;
	static const unsigned char P8_4_DIG = 39;
	static const unsigned char P8_5_DIG = 34;
	static const unsigned char P8_6_DIG = 35;
	static const unsigned char P8_7_DIG = 66;
	static const unsigned char P8_8_DIG = 67;
	static const unsigned char P8_9_DIG = 69;
	static const unsigned char P8_10_DIG = 68;
	static const unsigned char P8_11_DIG = 45;
	static const unsigned char P8_12_DIG = 44;
	static const unsigned char P8_13_DIG = 23;
	static const unsigned char P8_14_DIG = 26;
	static const unsigned char P8_15_DIG = 47;
	static const unsigned char P8_16_DIG = 46;
	static const unsigned char P8_17_DIG = 27;
	static const unsigned char P8_18_DIG = 65;
	static const unsigned char P8_19_DIG = 22;
	static const unsigned char P8_20_DIG = 63;
	static const unsigned char P8_21_DIG = 62;
	static const unsigned char P8_22_DIG = 37;
	static const unsigned char P8_23_DIG = 36;
	static const unsigned char P8_24_DIG = 33;
	static const unsigned char P8_25_DIG = 32;
	static const unsigned char P8_26_DIG = 61;
	static const unsigned char P8_27_DIG = 86;
	static const unsigned char P8_28_DIG = 88;
	static const unsigned char P8_29_DIG = 87;
	static const unsigned char P8_30_DIG = 89;
	static const unsigned char P8_31_DIG = 10;
	static const unsigned char P8_32_DIG = 11;
	static const unsigned char P8_33_DIG = 9;
	static const unsigned char P8_34_DIG = 81;
	static const unsigned char P8_35_DIG = 8;
	static const unsigned char P8_36_DIG = 80;
	static const unsigned char P8_37_DIG = 78;
	static const unsigned char P8_38_DIG = 79;
	static const unsigned char P8_39_DIG = 76;
	static const unsigned char P8_40_DIG = 77;
	static const unsigned char P8_41_DIG = 74;
	static const unsigned char P8_42_DIG = 75;
	static const unsigned char P8_43_DIG = 72;
	static const unsigned char P8_44_DIG = 73;
	static const unsigned char P8_45_DIG = 70;
	static const unsigned char P8_46_DIG = 71;
	static const unsigned char P9_11_DIG = 30;
	static const unsigned char P9_12_DIG = 60;
	static const unsigned char P9_13_DIG = 31;
	static const unsigned char P9_14_DIG = 50;
	static const unsigned char P9_15_DIG = 48;
	static const unsigned char P9_16_DIG = 51;
	static const unsigned char P9_17_DIG = 5;
	static const unsigned char P9_18_DIG = 4;
	static const unsigned char P9_19_DIG = 13;
	static const unsigned char P9_20_DIG = 12;
	static const unsigned char P9_21_DIG = 3;
	static const unsigned char P9_22_DIG = 2;
	static const unsigned char P9_23_DIG = 49;
	static const unsigned char P9_24_DIG = 15;
	static const unsigned char P9_25_DIG = 117;
	static const unsigned char P9_26_DIG = 14;
	static const unsigned char P9_27_DIG = 115;
	static const unsigned char P9_28_DIG = 113;
	static const unsigned char P9_29_DIG = 111;
	static const unsigned char P9_30_DIG = 112;
	static const unsigned char P9_31_DIG = 110;
	static const unsigned char P9_41_DIG = 20;
	static const unsigned char P9_42_DIG = 7;

	/* Pin mux */
	static map<char, string> pinmux;

	/* Analog pins */
	static const string P9_33_ANA = "ain4";
	static const string P9_35_ANA = "ain6";
	static const string P9_36_ANA = "ain5";
	static const string P9_37_ANA = "ain2";
	static const string P9_38_ANA = "ain3";
	static const string P9_39_ANA = "ain0";
	static const string P9_40_ANA = "ain1";

	// Constructor and Destructor
	GPIO();
	~GPIO();

	// Public member functions

	// Currently, pinMode() only works for digital pins
	void pinMode(char pin, string direction);	// direction: INPUT or OUTPUT

	// Only pass digital pins into here
	void digitalWrite(char pin, string value);	// value: LOW or HIGH
	string digitalRead(char pin);				// returns LOW or HIGH

	// Only pass analog pins into here
	void analogWrite(string pin, string value);	// not sure what value can be set to yet
	string analogRead(string pin);				// not sure what this returns exactly

	// [NEED TO GO IN A DIFFERENT FILE]
	void delay(int millis);						// used to wait for a period of time
	int millis();								// returns time in milliseconds since when the program started

private:
	// Private member functions

	// pinUnexport() and cleanUp() should only have to deal with digital pins for now
	void pinUnexport(char pin);		// helper function for cleanUp()
	void cleanUp();					// takes care of unexporting exported pins
};

#endif
