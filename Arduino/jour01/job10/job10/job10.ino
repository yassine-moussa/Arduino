// Programme pour allumer progressivement une LED avec Arduino

// Définir la broche à laquelle la LED est connectée
const int ledPin = 9; // Utilisez une broche PWM (ex: 3, 5, 6, 9, 10, ou 11 sur un Arduino Uno)

// Variables pour la luminosité et la durée de l'incrément
int brightness = 0;
int fadeAmount = 5;
int fadeDelay = 30; // Délai en millisecondes entre chaque incrément

void setup() {
  // Initialise la broche LED en tant que sortie
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Définir la luminosité de la LED
  analogWrite(ledPin, brightness);

  // Changer la luminosité pour la prochaine itération
  brightness = brightness + fadeAmount;

  // Inverser le sens de l'incrément lorsque la luminosité atteint les limites
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }

  // Attendre fadeDelay millisecondes avant la prochaine itération
  delay(fadeDelay);
}
