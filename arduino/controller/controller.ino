#include <Servo.h> // include servo library

#define R_PIN 5
#define L_PIN 6
#define U_PIN 9
#define D_PIN 10
#define P_PIN 1
#define S_PIN 3
#define B_PIN 11
#define TOLERANCE 10

Servo R_MOTOR;
Servo L_MOTOR;
Servo C_SERVO;

const int NUM_OF_FIELDS = 5; // number of comma separated fields
int value[NUM_OF_FIELDS]; // values for all the fields
int rval = 1500;
int lval = 1500;
int uval = 0;
int dval = 0;
int sval = 115;
int bval = 0;

void runRobot
() {
  R_MOTOR.writeMicroseconds(rval); 
  L_MOTOR.writeMicroseconds(lval);
  C_SERVO.write(sval);

  digitalWrite(U_PIN, uval);
  digitalWrite(D_PIN, dval);
  digitalWrite(B_PIN, bval);

  Serial.print("R: ");
  Serial.println(rval);
  Serial.print("L: ");
  Serial.println(lval);
  Serial.print("U: ");
  Serial.println(uval);
  Serial.print("D: ");
  Serial.println(dval);
  Serial.print("S: ");
  Serial.println(sval);
  Serial.print("B: ");
  Serial.println(bval);
}

void setup() { 
  // attach servo control
  R_MOTOR.attach(R_PIN); 
  L_MOTOR.attach(L_PIN);
  C_SERVO.attach(S_PIN); // resets default angle

  // initialize ballast and led
  pinMode(U_PIN, OUTPUT);
  pinMode(D_PIN, OUTPUT);
  pinMode(B_PIN, OUTPUT);

  // set serial to 9600 baud rate
  Serial.begin(9600);

  // initalize motors
  runRobot();
} 

void loop() {
  if( Serial.available()) {
    // read serial
    for(int i = 0; i < NUM_OF_FIELDS; i++) {
      value[i] = Serial.parseInt(); // get numeric value
      if (i == 0) rval = value[0];
      if (i == 1) lval = value[1];
      if (i == 2) uval = value[2];
      if (i == 3) dval = value[3];
      if (i == 4) sval = value[4];
      if (i == 5) bval = value[5];
    }

    // check potentiometer
    int pval = analogRead(P_PIN); 
    if (pval < TOLERANCE || pval > (1023 - TOLERANCE)) {
      uval = 0;
      dval = 0;
    }

    // run robot
    runRobot();
  }
} 

