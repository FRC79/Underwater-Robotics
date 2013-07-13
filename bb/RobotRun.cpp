#include "RobotRun.h"
#include "gpio\SimpleGPIO.h"

RobotRun::RobotRun() { }

RobotRun::~RobotRun() { }

void RobotRun::setup() 
{
	// Setup functions
	
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
