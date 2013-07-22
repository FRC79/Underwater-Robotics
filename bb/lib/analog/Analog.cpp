#include "Analog.h"

Analog::Analog(){
	SYSFS_ANA_DIR = "/sys/devices/ocp.2/helper.14/"; // Later we can mess with this (helper.14)
}

void Analog::exportAllPins(){
	// Exported all analog pins (not able to export one pin at a time, yet)
	system("echo cape-bone-iio > /sys/devices/bone_capemgr.*/slots");
}

int Analog::analogRead(int pin){
	
	ifstream stream (SYSFS_ANA_DIR + ("ANA" + pin)); // Opens stream to where analog input is
	string fileContents ( ( istreambuf_iterator<char>(stream) ), // stores file contents as string
					( istreambuf_iterator<char>() ) );
	int value = stoi(fileContents); // convert string to int
	return value;
}

void Analog::analogWrite(int pin, int value){
	// Do this later...
}
