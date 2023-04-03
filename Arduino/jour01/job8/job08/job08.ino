const int ledPin1 = 8;
const int ledPin2 = 9;
const int delayTime1 = 500;
const int delayTime2 = 750;
unsigned long previousMillis1 = 0;
unsigned long previousMillis2 = 0;

void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis1 >= delayTime1) {
    previousMillis1 = currentMillis;
    digitalWrite(ledPin1, !digitalRead(ledPin1));
  }

  if (currentMillis - previousMillis2 >= delayTime2) {
    previousMillis2 = currentMillis;
    digitalWrite(ledPin2, !digitalRead(ledPin2));
  }
}
