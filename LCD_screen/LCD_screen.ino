
#include <LiquidCrystal.h>


LiquidCrystal LCD(12, 11, 5, 4, 3, 2);

byte Heart[8] = {
  B00000,
  B00000,
  B00000,
  B11011,
  B11111,
  B01110,
  B00100,
};


void LCD_setup()
{
//stearting the LCD screen.(16 collumn, 2 row)
LCD.begin(16,2);
char line[]= "LEO YONG IS AWESOME";
//for loop to move text on screen
LCD.print(line);
}

void LCD_Display()
{
 //scroll text from right to left
 LCD.scrollDisplayLeft();
 delay(500);
}

void setup() {
  LCD_setup();
}

void loop() {
  LCD_Display();
}

