import procontroll.*;
import net.java.games.input.*;
import processing.serial.*; // Load serial library 

Serial arduinoPort; // Set arduinoPort as serial connection 
ControllIO controllIO;
ControllDevice joystick;
ControllSlider stickX;
ControllSlider stickY;
ControllButton upButton;
ControllButton downButton;
PFont font;

int joystick_ID = 2;
float DEBOUNCE_VAL = 0.05;

float x; // used to store joystick input
float y;
int goingUp;
int goingDown;

// Debouncing joystick input
float debounce(float val){
  return (abs(val) <= DEBOUNCE_VAL) ? 0.0 : val;
}

//--- Function: setup 
void setup() 
{ 

//  arduinoPort = new Serial(this, Serial.list()[1], 9600); // Set arduinoPort to 9600 baud 

  // Setup the joystick controls
  controllIO = ControllIO.getInstance(this);
  joystick = controllIO.getDevice(joystick_ID);
  stickX = joystick.getSlider(2);
  stickY = joystick.getSlider(1);
  upButton = joystick.getButton(2);
  downButton = joystick.getButton(1);
  
  // Setup the window
  size(400, 400);
  font = createFont("Arial", 18, true);
} 

//--- Function: draws servo on/off 
void draw() 
{ 
  // Store joystick input
  x = debounce(stickX.getValue());
  y = debounce(stickY.getValue() * -1); // invert Y direction
  // Prevent both buttons from being pressed
  if(upButton.pressed() && downButton.pressed()){
    goingUp = 0;
    goingDown = 0;
  } else {
    goingUp = upButton.pressed() ? 1 : 0;
    goingDown = downButton.pressed() ? 1 : 0;
  }
  
  // Set drawing parameters
  background(255);
  fill(0);
  textFont(font);
  textAlign(LEFT);
  
  // Output values in the window
  text("Joystick", 30, 40);
  text("X: " + x, 30, 80);
  text("Y: " + y, 30, 120);
  text("Up: " + goingUp, 30, 160);
  text("Down: " + goingDown, 30, 200);

  /* Send data back to arduino
  0  |  X joystick value
  1  |  Y joystick value
  2  |  Up button value
  3  |  Down button value
                              */
//  arduinoPort.write(x);
//  arduinoPort.write(",");
//  arduinoPort.write(y);
//    arduinoPort.write(",");
//    arduinoPort.write(goingUp);
//    arduinoPort.write(",");
//    arduinoPort.write(goingDown);

} 
