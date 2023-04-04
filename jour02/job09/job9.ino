#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int joystickXPin = A0;
const int joystickYPin = A1;

const int threshold = 300;

void setup() {
  lcd.begin(16, 2);
}

void loop() {
  int xValue = analogRead(joystickXPin);
  int yValue = analogRead(joystickYPin);

  String direction;
  if (xValue > (1023 - threshold)) {
    direction = "Droite";
  } else if (xValue < threshold) {
    direction = "Gauche";
  } else if (yValue > (1023 - threshold)) {
    direction = "Haut";
  } else if (yValue < threshold) {
    direction = "Bas";
  } else {
    direction = "Centre";
  }

  lcd.setCursor(0, 0);
  lcd.print("Direction:      ");
  lcd.setCursor(0, 1);
  lcd.print(direction);
  lcd.print("        ");

  delay(100);
}
