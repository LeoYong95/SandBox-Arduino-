void setup()
{
 Serial.begin(9600);
OCR0A = 0xAF;
TIMSK0 |=_BV(OCIE0A);
}

void loop()
{
  Serial.println(TIMER0_COMPA_vect);
}

