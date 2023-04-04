// Inclure la bibliothèque LiquidCrystal
#include <LiquidCrystal.h>

// Initialiser la bibliothèque avec les numéros des broches de l'Arduino auxquelles l'écran LCD est connecté
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Broches pour le bouton pressoir
const int buttonPin = 8;
bool isCounterRunning = true;

// Variables pour le compteur
unsigned long startTime;
unsigned long elapsedTime;

void setup() {
  // Configure la taille de l'écran LCD (nombre de colonnes et de lignes)
  lcd.begin(16, 2);

  // Configure la broche du bouton pressoir comme entrée
  pinMode(buttonPin, INPUT_PULLUP);

  // Initialiser le compteur
  startTime = millis();
}

void loop() {
  // Lire l'état du bouton pressoir
  int buttonState = digitalRead(buttonPin);

  // Si le bouton est enfoncé (état LOW avec INPUT_PULLUP), inversez l'état du compteur
  if (buttonState == LOW) {
    isCounterRunning = !isCounterRunning;

    // Attendre un peu pour éviter les rebonds (debouncing)
    delay(200);
  }

  // Si le compteur est en cours d'exécution, mettre à jour le temps écoulé
  if (isCounterRunning) {
    elapsedTime = millis() - startTime;
  }

  // Afficher le nom du groupe et le compteur sur l'écran LCD
  lcd.setCursor(0, 0);
  lcd.print("Groupe: Okami   ");
  lcd.setCursor(0, 1);
  lcd.print("Temps: ");
  lcd.print(elapsedTime / 1000);
  lcd.print(" s     ");
}
