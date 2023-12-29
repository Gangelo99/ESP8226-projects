
# ESP8266 Projects
Some littles projects for ESP8266 made with PlatformIO.


## Appendix

Table of contents:
- [Led Button](https://github.com/Gangelo99/ESP8266-projects#led_buttoncpp)
- [Multiple_Led_Button.cpp](https://github.com/Gangelo99/ESP8266-projects#multipled_led_buttoncpp)


## Led_Button.cpp
First project in which a led blink when a button is pressed. 

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
## Multiple_Led_Button.cpp
Project in which buttons of certain color light the LED of that specific color.
<img src="https://github.com/Gangelo99/ESP8266-projects/blob/main/gif/Multiple_Led_Button.gif" width="35%" height="35%"/>
## Multipled Led Button OOP
Improved version of the multiple_led_button.cpp with the OOP (Object Oriented Programming). 

### Button.h
```
class Button{
    private:
        byte pin;
        byte state;
        byte lastReading;
        unsigned long debounceDelay = 100;   // debounce time in milliseconds
        unsigned long lastDebounceTime = 0;  // last time the button state was toggled

    public:
        Button(byte pin);

        void init();
        void update();

        byte getState();
        bool isPressed();
};
```
In the Button class I used the `millis()` function and the two variables `debounceDelay` & `lastDebounceTime` to avoid false positives caused by rebounds of the button(s) signal. 
```
void Button::update(){
    byte newReading = digitalRead(pin);
    if(newReading != lastReading)
        lastDebounceTime = millis();
    
    if(millis() - lastDebounceTime > debounceDelay)
        state = newReading;
    
    lastReading = newReading;
}
```
