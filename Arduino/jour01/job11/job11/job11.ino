// Programme pour contrôler une LED avec un bouton

const int ledPin = 13; // Broche de la LED
const int buttonPin = 2; // Broche du bouton

int buttonState = 0;
int previousButtonState = 0;
unsigned long buttonPressTime = 0;
unsigned long debounceTime = 50;
int pressCounter = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState != previousButtonState) {
    delay(debounceTime);
    if (buttonState == LOW) {
      pressCounter++;
      buttonPressTime = millis();
    }
  }

  if (buttonState == HIGH && (millis() - buttonPressTime) > 1000) {
    pressCounter = 0;
    digitalWrite(ledPin, LOW);
  }

  switch (pressCounter) {
    case 1: // LED allumée
      digitalWrite(ledPin, HIGH);
      break;
    case 2: // LED reste allumée
      digitalWrite(ledPin, HIGH);
      break;
    case 3: // LED clignote
      digitalWrite(ledPin, HIGH);
      delay(500);
      digitalWrite(ledPin, LOW);
      delay(500);
      break;
    default: // LED éteinte
      digitalWrite(ledPin, LOW);
      break;
  }
  previousButtonState = buttonState;

// Réinitialiser le compteur si on atteint 4 ou plus
if (pressCounter >= 4) {
pressCounter = 0;
}
}

 
