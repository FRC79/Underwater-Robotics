#ifndef RUN_H
#define RUN_H

class Run
{
	/* The Run class is a base to run a group of functions called 
		setup, loop, and cleanup. The class must be inherited and those
		methods must be overriden. The run method is called in the main program
		and takes care of the back-end ordering of those functions	*/

public:
	// Constants for loop returns
	static const bool RELOOP = true;
	static const bool EXIT = false;

	// Constructor and Destructor
	Run();
	~Run();

	// Main run function that takes care of setup, loop, cleanup
	// Called in main methods
	void run();

	virtual void setup() = 0;
	virtual bool loop() = 0;
	virtual void cleanup() = 0;

private:
	bool isRunning;
};

#endif
