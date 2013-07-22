#ifndef ROBOTRUN_H
#define ROBOTRUN_H

#include "Run.h"
#include "lib\gpio\SimpleGPIO.h"
#include "lib\analog\Analog.h"

class RobotRun : public Run
{
	/* The RobotRun class will be the container for all of our robot
		functions and high level actions done. It overrides setup, loop,
		and cleanup to perform these actions from the Run class. */

public:
	RobotRun();
	~RobotRun();

	// Overriden from Run class
	void setup();
	bool loop();
	void cleanup();

private:
	Analog *ana;
};

#endif