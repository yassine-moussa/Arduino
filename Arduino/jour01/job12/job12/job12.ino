// Programme pour contrôler l'intensité de deux LEDs avec un potentiomètre

const int ledPin1 = 9; // Broche de la première LED (PWM)
const int ledPin2 = 10; // Broche de la deuxième LED (PWM)
const int potPin = A0; // Broche du potentiomètre

void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}

void loop() {
  int potValue = analogRead(potPin); // Lire la valeur du potentiomètre (0 - 1023)
  
  // Convertir la valeur du potentiomètre en une valeur de luminosité pour les LEDs (0 - 255)
  int brightness1 = map(potValue, 0, 1023, 0, 255);
  int brightness2 = map(potValue, 0, 1023, 255, 0);

  // Appliquer les nouvelles valeurs de luminosité aux LEDs
  analogWrite(ledPin1, brightness1);
  analogWrite(ledPin2, brightness2);
  delay(10); // Ajouter un court délai pour la stabilité du programme
}

 
