#include <Arduino.h>

//Input Button
#define BLUE_BUTTON D3
#define RED_BUTTON D2
#define YELLOW_BUTTON D1

//Output LED
#define BLUE_LED D4
#define RED_LED D6
#define YELLOW_LED D5

short int yellowButtonState = LOW;
short int redButtonState    = LOW;
short int bluButtonState    = LOW;

void setup() {
  Serial.begin(9600);
  pinMode(BLUE_BUTTON, INPUT_PULLUP);
  pinMode(RED_BUTTON, INPUT_PULLUP);
  pinMode(YELLOW_BUTTON, INPUT_PULLUP);

  pinMode(BLUE_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
}

void loop() {
  yellowButtonState = digitalRead(YELLOW_BUTTON);
  redButtonState    = digitalRead(RED_BUTTON);
  bluButtonState    = digitalRead(BLUE_BUTTON);

  if (yellowButtonState != HIGH)
    digitalWrite(YELLOW_LED, HIGH);
  else 
    digitalWrite(YELLOW_LED, LOW);

  if (redButtonState != HIGH)
    digitalWrite(RED_LED, HIGH);
  else 
    digitalWrite(RED_LED, LOW);

  if (bluButtonState != HIGH)
    digitalWrite(BLUE_LED, HIGH);
  else 
    digitalWrite(BLUE_LED, LOW);
    
}
