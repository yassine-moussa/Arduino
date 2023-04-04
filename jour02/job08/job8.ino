// Inclure la bibliothèque LiquidCrystal
#include <LiquidCrystal.h>

// Initialiser la bibliothèque LiquidCrystal avec les numéros des broches de l'Arduino auxquelles l'écran LCD est connecté
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Variables pour la barre de chargement
const int loadingBarLength = 16;
const unsigned long rectangleInterval = 3000; // 3 secondes
unsigned long previousMillis = 0;
int currentRectangle = 0;

void setup() {
  // Configure la taille de l'écran LCD (nombre de colonnes et de lignes)
  lcd.begin(16, 2);
}

void loop() {
  // Obtenir le temps actuel
  unsigned long currentMillis = millis();

  // Si le temps écoulé depuis le dernier rectangle affiché est supérieur ou égal à l'intervalle de rectangle
  if (currentMillis - previousMillis >= rectangleInterval) {
    // Enregistrer le temps actuel
    previousMillis = currentMillis;

    // Afficher un rectangle sur l'écran LCD
    lcd.setCursor(currentRectangle, 1);
    lcd.write(byte(255));

    // Mettre à jour l'indice du rectangle actuel
    currentRectangle++;

    // Si la barre de chargement est complète, la réinitialiser
    if (currentRectangle >= loadingBarLength) {
      currentRectangle = 0;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Chargement:");
      lcd.setCursor(0, 1);
    }
  }
}
