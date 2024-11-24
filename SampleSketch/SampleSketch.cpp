#include <Arduino.h>

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
}

unsigned long lastms = 0;
void loop()
{
  // put your main code here, to run repeatedly:
  Serial.println("Hello World!");
  Serial.println(millis());
  Serial.println(micros());
  if(Serial.available() > 0)
  {
    while(Serial.available() > 0)
    {
      const int c = Serial.read();
      Serial.print(static_cast<char>(c));
    }
    Serial.println();
  }
  delay(1000);
}
