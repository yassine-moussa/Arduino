#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Broches pour le capteur à ultrasons HC-SR04
const int triggerPin = 9;
const int echoPin = 10;

void setup() {
  // Configure la taille de l'écran LCD (nombre de colonnes et de lignes)
  lcd.begin(16, 2);

  // Configurer les broches du capteur à ultrasons
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // Envoyer une impulsion de 10 µs au capteur à ultrasons
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  // Lire le temps que met l'écho pour revenir
  unsigned long duration = pulseIn(echoPin, HIGH);

  // Calculer la distance (en cm) en utilisant la vitesse du son (343 m/s)
  float distance = (duration * 0.0343) / 2;

  lcd.setCursor(0, 0);
  lcd.print("Distance:       ");
  lcd.setCursor(0, 1);
  lcd.print(distance);
  lcd.print(" cm      ");

  delay(200);
}
