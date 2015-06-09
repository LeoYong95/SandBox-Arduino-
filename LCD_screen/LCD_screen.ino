
#include <LiquidCrystal.h>
 
 LiquidCrystal lcd(12,11,5,4,3,2);
 
class LCD 
{
  public:
//---------variables

 unsigned long previousTime;
 unsigned long currentTime;
 int sensorvalue;

//----------Line to print
String line;
 
LCD()
{
  previousTime = 0;
  
};

void update()
{
  currentTime = millis();
  if (currentTime - previousTime >=1000)
  {
    lcd.clear();
    previousTime = currentTime;
    sensorvalue = analogRead(A0);
    Serial.println(sensorvalue);
    
   if( sensorvalue <100)
  {
    lcd.print("DARK DAY");
    
    
  }else if(sensorvalue > 300)
  {
    lcd.print("SUNNY DAY");
    
  }else{
   lcd.print("LEO YONG AWESOME");
   
  }

  }

}

};

LCD screen1;

void setup() {
  lcd.begin(16,2);
  lcd.print("starting");
   Serial.begin(9600);
     

OCR0A = 0xAF;
TIMSK0 |= _BV(OCIE0A);
}

SIGNAL(TIMER0_COMPA_vect)
{
  screen1.update();  
}
  
  
void loop() {
}

