#include <LiquidCrystal.h>
// 핀 번호 (RS, E, DB4, DB5, DB6, DB7)
LiquidCrystal lcd(44, 45, 46, 47, 48, 49); // LCD 연결
void setup() {
  lcd.begin(16, 2); // LCD 초기화
  Serial.begin(9600);
}

float readTemperature() {
  // put your main code here, to run repeatedly:
  int reading = analogRead(55);

  float tempC = (reading * 5.0 / 1024.0) * 100;
  Serial.print(tempC);
  Serial.print("C : ");

  return tempC;
}

int readIlluminance() {
  return analogRead(56);
}

void loop() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(String("tempC : ") + readTemperature());
  
  lcd.setCursor(0, 1);
  lcd.print(String("Ilumi : ") + readIlluminance()); 
  
  delay(1000);
}
