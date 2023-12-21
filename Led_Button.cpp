#include "Arduino.h"

#define buttonPin D1 // D1 is used for input signal
#define ledPin D2    // D2 is used for output signal

unsigned long debounceDelay = 100;   // debounce time in milliseconds
unsigned long lastDebounceTime = 0;  // last time the button state was toggled
int buttonState = LOW;               // current state of the button
int lastButtonState = LOW;           // previous state of the button

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int reading = digitalRead(buttonPin);

  // Check the last state of the button
  if (reading != lastButtonState) { 
    lastDebounceTime = millis(); // Reset the debounce timer if the state is different than the last state
  }

  if ((millis() - lastDebounceTime) > debounceDelay && reading != buttonState) {
      buttonState = reading; //If the buttonState change state (from ON to OFF or viceversa), get the new state of buttonPin

      if (buttonState == HIGH) { //If button is pressed
        digitalWrite(ledPin, HIGH);
        Serial.println("Bottone ON");
      } 
      else {                     //If button is not pressed
        digitalWrite(ledPin, LOW);
        Serial.println("Bottone OFF");
      }
  }

  lastButtonState = reading;
}
