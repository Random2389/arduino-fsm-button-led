enum LedState {
  OFF,
  ON,
  MODE
};

const int led = 7;
const int button = 9;

LedState state = OFF;

// Button handling
bool buttonState = HIGH;
bool lastReading = HIGH;
unsigned long debounceTime = 0;
unsigned long pressStartTime = 0;

const unsigned long debounceDelay = 50;
const unsigned long longPressTime = 500;

// Blink handling
bool ledOutput = LOW;
unsigned long lastBlinkTime = 0;
const unsigned long blinkInterval = 100;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(button, INPUT_PULLUP);
}

void loop() {
  unsigned long now = millis();
  bool reading = digitalRead(button);

  /* ---------- DEBOUNCE ---------- */
  if (reading != lastReading) {
    debounceTime = now;
  }

  if ((now - debounceTime) > debounceDelay) {

    /* ---------- BUTTON EVENT ---------- */
    if (reading != buttonState) {
      buttonState = reading;

      // Button pressed
      if (buttonState == LOW) {
        pressStartTime = now;
      }
      // Button released
      else {
        unsigned long pressDuration = now - pressStartTime;

        // SHORT PRESS
        if (pressDuration < longPressTime) {
          if (state == OFF) state = ON;
          else if (state == ON) state = OFF;
        }

        // LONG PRESS
        else {
          if (state == MODE) state = OFF;
          else state = MODE;
        }
      }
    }
  }

  lastReading = reading;

  /* ---------- FSM OUTPUT LOGIC ---------- */
  if (state == OFF) {
    digitalWrite(led, LOW);
  }

  else if (state == ON) {
    digitalWrite(led, HIGH);
  }

  else if (state == MODE) {
    if (now - lastBlinkTime >= blinkInterval) {
      ledOutput = !ledOutput;
      digitalWrite(led, ledOutput);
      lastBlinkTime = now;
    }
  }
}
