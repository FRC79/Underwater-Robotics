#include <cstdlib>
#include <iostream>
#include "RobotRun.h"

using namespace std;

int main(int argc, char *argv[])
{	
	// Create a RobotRun instance and tell it to run
	RobotRun *run = new RobotRun();
	run->run();

    return EXIT_SUCCESS;
}
