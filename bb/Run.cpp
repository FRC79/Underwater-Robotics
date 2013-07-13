#include "Run.h"

Run::Run() { 
	isRunning = true; 
}

Run::~Run() 
{ 
	delete isRunning;
}

void Run::run()
{
	setup();

	// Continuously run loop
	while(isRunning){
		// Loop will return bool that says if we
		// want to keep running or not
		isRunning = loop();
	}

}
