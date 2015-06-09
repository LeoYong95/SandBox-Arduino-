
#include <LiquidCrystal.h>


class LCD 
{
//---------sensor pin
int sensor_Pin;
//---------variables
 unsigned long previousTime;
 unsigned long currentTime;
//----------Line to print
 String line ="LEO YONG IS AWESOME";
 

public:

LCD()
{
LiquidCrystal lcd(12,11,5,4,3,2);
lcd.begin(16,2);
previousTime = 0;
lcd.print(line);
lcd.scrollDisplayLeft();
};

void update()
{
   
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
void setup() {
 
}

void loop() {
}

