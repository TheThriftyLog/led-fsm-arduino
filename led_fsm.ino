// LED Finite State Machine with Pushbutton
// States: 0 = OFF, 1 = ON, 2 = BLINK

int pushButton = 2; // digital pin 2 has a push button attached to it
int led = 4; // digital pin 4 has an LED attached to it
int state = 0; // initial state of finite state machine - OFF
int lastButtonState = 0; // last button state starts at zero
unsigned long lastBlinkTime = 0; // tracks the last time the LED was toggled
int ledState = LOW; // tracks the current LED state for blinking

// the setup routine runs once when you press reset
void setup () {

  Serial.begin(9600); // initialize serial comm. at 9600 bits per second

  pinMode (pushButton, INPUT); // make the push button's pin an input

  pinMode (led, OUTPUT); // Make the LED's pin an output
}

// the loop routine runs over and over again forever
void loop() {

  int buttonState = digitalRead(pushButton); // read the input pin

  if (buttonState == 1 && buttonState != lastButtonState) {
    state = (state + 1) % 3; // Go to next state with each button push- OFF, ON, BLINK
    if (state == 2) { // If the new state is BLINK (2) after a button press,
      ledState = LOW; // reset the LED to off so BLINK always starts from a known state and
      lastBlinkTime = millis(); // reset the blink timer to now so the first toggle is a full 500ms away
    }
    Serial.println(state); // Print out the state of the button
    delay(50); // delay to wait for bounce to settle
  }

  if (state == 0) {
    digitalWrite(led, LOW); // LED is off if the state equals zero
  }
  else if (state == 1) {
    digitalWrite(led, HIGH); // LED is on if the state equals one
  }
  else if (state == 2) {
    unsigned long currentTime = millis(); // Get the current elapsed time in milliseconds
    if (currentTime - lastBlinkTime >= 500) { // Check if 500ms has passed since last toggle
      lastBlinkTime = currentTime; // Reset the timer to now
      ledState = !ledState; // Flip the LED state - HIGH becomes LOW, LOW becomes HIGH
      digitalWrite(led, ledState); // Write the new state to the LED pin
    }
  }

  delay(1); // delay in between reads for stability
  
  lastButtonState = buttonState; // save current button state for edge detection next cycle
}
