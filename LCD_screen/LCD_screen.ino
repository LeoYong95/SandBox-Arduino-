/*
 - This code display the fucntionality of the LiquidCrystal Librarry of Arduino.
 - Here the code allow the LCD screen to be interupted by an AIpin.
 - A Timer built in the micro processor is also utilised to call the update function.
*/
#include <LiquidCrystal.h>

 
//list down the variables
LiquidCrystal lcd(12,11,5,4,3,2);
 
//create a LCD class
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

//----------update the lcd screen
void update()
{
  currentTime = millis();
  
  //--------only interupt for every second
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
//-----------one lcd variables
LCD screen1;

void setup() {
//----------initiate LCD screen

  lcd.begin(16,2);
  lcd.print("starting");

   Serial.begin(9600);
     
//----------Timer setup.
OCR0A = 0xAF;
TIMSK0 |= _BV(OCIE0A);
}

//---------signal generated for every milisecond
SIGNAL(TIMER0_COMPA_vect)
{
  screen1.update();  
}
  
//empty loop.  
void loop() {
}

