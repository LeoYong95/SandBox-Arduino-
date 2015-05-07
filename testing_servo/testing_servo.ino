//servo testing
#include <Servo.h>
Servo S1;

//Define Pins
int servopin= 9;

void setup()
{
   S1.attach(servopin);  
}

void loop()
{
 for (int i =0; i <=60; i=i+20)
 {
   S1.write(i);
   delay(1000);
 } 
}
