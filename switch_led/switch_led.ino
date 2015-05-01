//My first Project

 int switchpin = 8;
 int ledpin = 11;
 boolean lastButton = LOW;
 boolean ledOn = HIGH;
 boolean currentButton =LOW;
 int ledLevel = 0; 
void setup()
{
 //set the pin as output here
  pinMode(ledpin, OUTPUT);
  pinMode(switchpin, INPUT);
}

boolean debounce(boolean last)
{
  boolean current = digitalRead(switchpin);
  if (last != current)
  {
    delay(5);
    current = digitalRead(switchpin);
  }
  return current;
}

void loop()
{
  currentButton = debounce(lastButton);

      analogWrite(ledpin, ledLevel);

  if(lastButton == LOW && currentButton == HIGH)
  {
      ledLevel = ledLevel + 51;
  }
  lastButton = currentButton;
  
  if(ledLevel > 255) ledLevel = 0;
  
}
