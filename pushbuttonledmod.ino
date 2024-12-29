// KODE ARDUINO BY robisptraa
const int buttonPin = A0; 
const int ledPins[] = {2, 3, 4, 5, 6, 7}; 


int currentLed = 0; 
bool lastButtonState = LOW; 
bool buttonPressed = false;

void setup() {
  for (int i = 0; i < 6; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], HIGH); 
  }

  digitalWrite(ledPins[currentLed], LOW);


  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {

  bool buttonState = digitalRead(buttonPin);


  if (buttonState == LOW && lastButtonState == HIGH && !buttonPressed) {
    buttonPressed = true;

    digitalWrite(ledPins[currentLed], HIGH);


    currentLed = (currentLed + 1) % 6;


    digitalWrite(ledPins[currentLed], LOW);
  }

  if (buttonState == HIGH) {
    buttonPressed = false;
  }


  lastButtonState = buttonState;
}
