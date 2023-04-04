// Broches pour la LED RGB
const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;

// Broche pour le potentiomètre
const int potPin = A0;

// Type de LED RGB (0 pour cathode commune, 1 pour anode commune)
const int rgbType = 0; // Mettez 1 pour une LED RGB à anode commune

void setup() {
  // Configurer les broches de la LED RGB en sortie
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  // Lire la valeur du potentiomètre (0 - 1023)
  int potValue = analogRead(potPin);

  // Convertir la valeur du potentiomètre en une couleur pour la LED RGB
  int red, green, blue;
  if (potValue < 342) {
    red = 255 - (potValue * 3 / 4);
    green = potValue * 3 / 4;
    blue = 0;
  } else if (potValue < 684) {
    red = 0;
    green = 255 - ((potValue - 342) * 3 / 4);
    blue = (potValue - 342) * 3 / 4;
  } else {
    red = (potValue - 684) * 3 / 4;
    green = 0;
    blue = 255 - ((potValue - 684) * 3 / 4);
  }

  // Inverser les couleurs pour une LED RGB à anode commune
  if (rgbType == 1) {
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  }

  // Mettre à jour la couleur de la LED RGB
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);

  // Délai pour rafraîchir la couleur (en ms)
  delay(10);
}
