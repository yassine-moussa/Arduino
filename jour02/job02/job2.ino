#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int analogPin = A0;

void setup() {
  lcd.begin(16, 2);
}

void loop() {
  int analogValue = analogRead(analogPin);

  float voltage = analogValue * (5.0 / 1023.0);

  lcd.setCursor(0, 0); 
  lcd.print("Tension: ");
  lcd.setCursor(0, 1); 
  lcd.print(voltage);
  lcd.print(" V      "); 

  delay(500); 
}
