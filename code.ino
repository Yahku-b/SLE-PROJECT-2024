#include <LiquidCrystal.h>
int DHT11 = A0;
int Fan = 1;
int Threshold = 27;
int sensorReading;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() 
{
  pinMode(DHT11, INPUT);
  pinMode(Fan, OUTPUT);
  lcd.begin(16, 2);

  Serial.begin(9600);

}

void loop() 
{
  sensorReading=analogRead(DHT11);
  if(sensorReading < Threshold)
  {
    pinMode(Fan, LOW);
    Serial.println("COLD");
    Serial.println(analogRead(A0));
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(sensorReading);
    lcd.setCursor(5,0);
    lcd.setCursor(0,2);
    lcd.print("FAN OFF");
  }
  else
  {
    pinMode(Fan, HIGH);
    Serial.println("HOT");
    Serial.println(analogRead(A0));
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(sensorReading);
    lcd.setCursor(0,1);
    lcd.setCursor(0,2);
    lcd.print("FAN ON");
    delay(A0);
  }

}
