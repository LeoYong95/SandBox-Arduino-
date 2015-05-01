int ledpin = 9;
int sensepin = 0;

void setup()
{
  analogReference(DEFAULT); //its not necessary
  pinMode(ledpin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  
  int val = analogRead(sensepin);
  val=constrain(val,750,900);
  int ledLevel = map(val,750,900,255,0);
  analogWrite(ledpin,ledLevel);
  Serial.println(analogRead(sensepin));
  delay(500);
  

}
