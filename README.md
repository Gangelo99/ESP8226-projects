
# ESP8266 Projects
Some littles projects for ESP8266 made with PlatformIO.

## Led_Button.cpp
First _(dumb)_ project in which a led blink when a button is pressed. 

In this project I decided to avoid the use of the `delay()` function to start practicing through `millis()` functions.

```
#define buttonPin D1 // D1 is used for input signal
#define ledPin D2    // D2 is used for output signal
```
D1 is used for input signal, while the D2 is for output.

#### How I used the millis function:

```
unsigned long debounceDelay = 100;   // debounce time in milliseconds
unsigned long lastDebounceTime = 0;  // last time the button state was toggled
int buttonState = LOW;               // current state of the button
int lastButtonState = LOW;           // previous state of the button
```
These variables are used to avoid false positives caused by rebounds of the button signal. `debounceDelay`is the debounce time, `lastDebounceTime` store the value in milliseconds from the last time the `buttonState` was toggled.

```
  if ((millis() - lastDebounceTime) > debounceDelay && reading != buttonState) {
      buttonState = reading; //If the buttonState change state (from ON to OFF or viceversa)
      // get the new state of buttonPin

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
```
`if ((millis() - lastDebounceTime) > debounceDelay && reading != buttonState)` 

This if statement is executed when the difference between `millis()` _(current time of the program's execution)_ and `lastDebounceTime` is greather than `debounceDelay` and the reading state is different of the current button State _`(buttonState)`_.
