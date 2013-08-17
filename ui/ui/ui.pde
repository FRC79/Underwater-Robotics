import procontroll.*;
import net.java.games.input.*;
import processing.serial.*; // Load serial library 

Serial arduinoPort; // Set arduinoPort as serial connection 
ControllIO controllIO;
ControllDevice joystick;
ControllSlider stickX;
ControllSlider stickY;
ControllSlider servo;
ControllButton upButton;
ControllButton downButton;
ControllButton onButton;
ControllButton offButton;

PFont font;

int JOYSTICK_ID = 0;
int ARDUINO_ID = 0;
float DEBOUNCE_VAL = 0.05;
int TOLERANCE = 5;
int DELAY = 200;
int CHANGE = 15;
int FORWARD = 1200;
int REVERSE = 1800;

int oldt = 0; // timer
int rval = 0; // store output to arduino
int lval = 0;
int uval = 0;
int dval = 0;
int sval = 115;
int bval = 0;

/* float debounce(float val) {
 // Debouncing joystick input
 return (abs(val) <= DEBOUNCE_VAL) ? 0.0 : val;
 }
 */

void setValue(float x, float y) {
  // convert to polar
  float r = sqrt(pow(x, 2) + pow(y, 2));
  float a = atan2(abs(y), abs(x));

  float speed = map(a, 0, PI/2, 0, 100);
  float percent = map(r, 0, 142, 0, 1);
  if (speed < TOLERANCE) speed = 0; // set tolerance
  else if (speed > (100 - TOLERANCE)) speed = 100;

  // apply directions
  int direction = 1; // default positive direction
  if (y < 0) direction = -1;

  // set temp value holders
  float rtemp = 0;
  float ltemp = 0;
  if (x >= 0) {
    rtemp = speed * percent * direction;
    ltemp = 100 * percent * direction;
  }
  if (x < 0) {
    rtemp = 100 * percent * direction;
    ltemp = speed * percent * direction;
  }

  // map values
  rval = int(map(rtemp, -100, 100, REVERSE, FORWARD));
  lval = int(map(ltemp, -100, 100, REVERSE, FORWARD));
}

void setup() { 
  // Set arduinoPort to 9600 baud 
  oldt = millis();
  arduinoPort = new Serial(this, Serial.list()[ARDUINO_ID], 9600); 
  println(Serial.list());

  // Setup the joystick controls
  controllIO = ControllIO.getInstance(this);
  joystick = controllIO.getDevice(JOYSTICK_ID);
  joystick.setTolerance(DEBOUNCE_VAL); // EXPERIMENTAL
  stickX = joystick.getSlider(0);
  stickY = joystick.getSlider(1);
  servo = joystick.getSlider(2);
  upButton = joystick.getButton(2);
  downButton = joystick.getButton(1);
  onButton = joystick.getButton(7);
  offButton = joystick.getButton(8);

  // Setup the window
  size(400, 400);
  font = createFont("Arial", 18, true);
  textFont(font);
  textAlign(LEFT);
} 

void draw() 
{ 
  // Store joystick input
  float x = stickX.getValue() * 100;
  float y = stickY.getValue() * -100; // invert Y direction
  float s = servo.getValue() * 100;
  
  // Prevent both buttons from being pressed
  uval = int(upButton.pressed());
  dval = int(downButton.pressed());
  if (upButton.pressed() && downButton.pressed()) {
    uval = 0;
    dval = 0;
  }
  
  // led control
  if (onButton.pressed()) bval = 1;
  else if (offButton.pressed()) bval = 0;
  if (onButton.pressed() && offButton.pressed()) bval = 0;
  
  // servo control
  sval = int(map(s, -100, 100, 179, 1));

  // Set motor values and send to arduino
  setValue(x, y);
  int passt = millis() - oldt;
  if (passt > DELAY) {
    arduinoPort.write(rval + "," + lval + "," + uval + "," + dval + "," + sval + "," + bval + "\n");
    println(rval + "," + lval + "," + uval + "," + dval + "," + sval + "," + bval);
    oldt = millis();
  }

  // Output values in the window
  background(255);
  fill(0);
  text("Joystick", 30, 40);
  text("X: " + x, 30, 80);
  text("Y: " + y, 30, 120);
  text("U: " + uval, 30, 160);
  text("D: " + dval, 30, 200);
  text("R: " + rval, 30, 240);
  text("L: " + lval, 30, 280);
  text("S: " + sval, 30, 320);
  text("B: " + bval, 30, 360);
}

