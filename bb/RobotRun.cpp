#include "RobotRun.h"

using namespace std;

RobotRun::RobotRun() { 
	ana = new Analog();
}

RobotRun::~RobotRun() { }

void RobotRun::setup() 
{
	// Setup functions

	ana->exportAllPins(); // Export all analog pins
}

bool RobotRun::loop() 
{
	// Loop function runs iteratively (over and over again)
	

	return EXIT; // RELOOP: we want to keep looping
				 // EXIT: we want to terminate loop
}

void RobotRun::cleanup() 
{
	// Cleanup functions
	
}
