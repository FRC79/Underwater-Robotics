# Compiling
Here is one way to compile your source into the main binary.

### GNU C++ (GCC)

```g++ -std=c++0x -W -Wno-unused-variable -Wall *[LIST OF SOURCE FILES]* -o *[BINARY FILE]*```

**Example:**
```g++ -std=c++0x -W -Wno-unused-variable -Wall Main.cpp Run.h Run.cpp RobotRun.cpp RobotRun.h lib/gpio/SimpleGPIO.h lib/gpio/SimpleGPIO.cpp lib/analog/Analog.cpp lib/analog/Analog.h  -o bin/Run_Robot.o```
