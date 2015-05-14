#include <Servo.h>

class sweep
{
  Servo servo;
  int pos;
  int increment;
  int updateinterval;
  unsigned long lastupdate;
  
  public:
  sweep(int interval)
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
   Serial.println(pos);
   if ((pos >=60) || (pos<=0))
   {
    increment=-increment; 
   }
    }
  }
    };
sweep servo1(15);
sweep servo2(5);

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
