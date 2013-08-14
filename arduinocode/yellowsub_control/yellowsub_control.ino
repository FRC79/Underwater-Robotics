//----------------------------start Arduino code-------------------------------- 

#include <Servo.h> // include servo headers 
// using 4 motors to drive robot
String message;
int xaxisval = 0;
int yaxisval = 0;
int ballastval = 0;
const int NUMBER_OF_FIELDS = 3; // how many comma separated fields we expect
int fieldIndex = 0;            // the current field being received
int values[NUMBER_OF_FIELDS];   // array holding values for all the fields



//--- Function: Setup () 
void setup() 
{ 
    
    Serial.begin(9600); //set serial to 9600 baud rate 
} 

//--- Function: loop () 
void loop() 
{ 
    // Check if there is a new message 
    if( Serial.available())
  {
    for(fieldIndex = 0; fieldIndex  < 3; fieldIndex ++)
    {
      values[fieldIndex] = Serial.parseInt(); // get a numeric value
      if (fieldIndex == 0) {
        xaxisval = values[0]; 
       }
       if (fieldIndex == 1){
         yaxisval = values[1];
       }
       if (fieldIndex == 2){
         ballastval = values[2];
       }
    }
 
      //now start calling motor and ballast methods
       Serial.println(xaxisval);
       Serial.println(yaxisval);
       Serial.println(ballastval);
       
    
    fieldIndex = 0;  // ready to start over
   
    
  }
} 
//----------------------------end Arduino code--------------------------------
