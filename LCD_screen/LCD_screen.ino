
#include <LiquidCrystal.h>


class LCD 
{
//---------sensor pin
int sensor_Pin;
//---------variables
 unsigned long previousTime;
 unsigned long currentTime;
//----------Line to print
 String line ;
 

public:

LCD(int sense)
{
LiquidCrystal lcd(12,11,5,4,3,2);
lcd.begin(16,2);
previousTime = 0;
lcd.print(line);
lcd.scrollDisplayLeft();
 sensor_Pin = sense;
};

void update()
{
   if( analogRead(sensor_Pin) <= 341)
  {
    line ="IT IS A GLOOMY DAY";
    
  }else if(analogRead(sensor_Pin) >= 341)
  {
    line ="IT IS A SUNNY DAY";
    
  }else{
    line ="LEO YONG IS AWESOME";
  }
  
  
}

void time()
{
  currentTime = millis();
  if (currentTime - previousTime >=500)
  {
    LCD::update();
  }
}

};

LCD screen1(A0);

void setup() {
 
}

void loop() {
  
}

