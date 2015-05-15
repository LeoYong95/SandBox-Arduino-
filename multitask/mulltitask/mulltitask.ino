#include <Servo.h>

class servos
{
  Servo servo;
  int pos;
  int increment;
  int updateinterval;
  unsigned long lastupdate;
  
  public:
  servos(int interval)
  {
    updateinterval=interval;
    increment=1;
  }
  
  void Attach(int pin)
  {
    servo.attach(pin);
  }
  
  void Detached()
  {
    servo.detach();
  }
  
  void update()
  {
    if((millis() -lastupdate) > updateinterval)
    {
    lastupdate=millis();
    pos +=increment;
    servo.write(pos);
    }
    
    if ((millis()-lastupdate) > 999)
    {
    Serial.println(pos);
    }
    
    if ((pos >=60) || (pos<=0))
   {
    increment=-increment; 
   }
    }
  };
servos servo1(7);
servos servo2(10);

void setup()
{
 Serial.begin(9600);
servo1.Attach(9);
servo2.Attach(10);

}

void loop()
{
  servo1.update();
  servo2.update();
}
