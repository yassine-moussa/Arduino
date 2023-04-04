// Inclure la bibliothèque LiquidCrystal
#include <LiquidCrystal.h>

// Initialiser la bibliothèque LiquidCrystal avec les numéros des broches de l'Arduino auxquelles l'écran LCD est connecté
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Broche pour le bouton pressoir
const int buttonPin = 8;

// Variables pour le chronomètre
bool isRunning = false;
unsigned long startTime;
unsigned long elapsedTime;

void setup() {
  // Configure la taille de l'écran LCD (nombre de colonnes et de lignes)
  lcd.begin(16, 2);

  // Configure la broche du bouton pressoir comme entrée
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  // Lire l'état du bouton pressoir
  int buttonState = digitalRead(buttonPin);

  // Si le bouton est enfoncé (état LOW avec INPUT_PULLUP), démarrer ou arrêter le chronomètre
  if (buttonState == LOW) {
    isRunning = !isRunning;

    // Si le chronomètre est en cours d'exécution, enregistrer le temps de départ
    if (isRunning) {
      startTime = millis();
    }

    // Attendre un peu pour éviter les rebonds (debouncing)
    delay(200);
  }

  // Si le chronomètre est en cours d'exécution, mettre à jour le temps écoulé
  if (isRunning) {
    elapsedTime = millis() - startTime;
  }

  // Afficher le temps écoulé sur l'écran LCD
  lcd.setCursor(0, 0);
  lcd.print("Chronometre:    ");
  lcd.setCursor(0, 1);
  lcd.print("Temps: ");
  lcd.print(elapsedTime / 1000);
  lcd.print(".");
  lcd.print((elapsedTime % 1000) / 10);
  lcd.print(" s     ");
}
