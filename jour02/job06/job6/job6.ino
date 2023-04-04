#include <Wire.h>
#include <DS3231.h>
#include <LiquidCrystal.h>

// Initialise le module RTC DS3231
DS3231 rtc(SDA, SCL);

// Initialise l'afficheur LCD (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

void setup() {
  // Initialise la communication avec l'afficheur LCD
  lcd.begin(16, 2);

  // Initialise la communication avec le module RTC
  rtc.begin();

  // Si vous souhaitez régler l'heure, décommentez les lignes ci-dessous et modifiez les valeurs selon vos besoins.
  // rtc.setDOW(FRIDAY);    // Jour de la semaine
  // rtc.setTime(12, 0, 0); // Heures, minutes et secondes
  // rtc.setDate(1, 1, 2023);  // Jour, mois et année
}

void loop() {
  // Efface l'écran de l'afficheur LCD
  lcd.clear();

  // Récupère l'heure, les minutes et les secondes
  int hours = rtc.getTime().hour;
  int minutes = rtc.getTime().minute;
  int seconds = rtc.getTime().second;

  // Affiche l'heure sur l'afficheur LCD
  lcd.setCursor(0, 0);
  if (hours < 10) {
    lcd.print("0");
  }
  lcd.print(hours);
  lcd.print(":");

  if (minutes < 10) {
    lcd.print("0");
  }
  lcd.print(minutes);
  lcd.print(":");

  if (seconds < 10) {
    lcd.print("0");
  }
  lcd.print(seconds);

  // Pause d'une seconde
  delay(1000);
}
