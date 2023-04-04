// Inclure la bibliothèque LiquidCrystal
#include <LiquidCrystal.h>

// Initialiser la bibliothèque avec les numéros des broches de l'Arduino auxquelles l'écran LCD est connecté
// En fonction de votre écran LCD, vous devrez peut-être modifier les numéros de broche
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Caractère personnalisé pour le smiley
byte smiley[8] = {
  B00000,
  B10001,
  B00000,
  B00000,
  B10001,
  B01110,
  B00000,
};

void setup() {
  // Configure la taille de l'écran LCD (nombre de colonnes et de lignes)
  lcd.begin(16, 2);

  // Créer le caractère personnalisé du smiley
  lcd.createChar(0, smiley);

  // Afficher le smiley sur l'écran LCD
  lcd.setCursor(7, 0); // Position du curseur au centre de l'écran (ajustez en fonction de la taille de votre écran LCD)
  lcd.write(byte(0)); // Écrire le caractère personnalisé (smiley)
}

void loop() {
  // Aucun code n'est nécessaire ici, car nous voulons simplement afficher le smiley sans le changer
}
