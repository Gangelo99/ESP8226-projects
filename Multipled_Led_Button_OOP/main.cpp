#include <Arduino.h>
#include "Led.h"
#include "Button.h"

#define BLUE_LED_PIN D4
#define BLUE_BUTTON_PIN D3

#define RED_LED_PIN  D6
#define RED_BUTTON_PIN  D2

#define YELLOW_LED_PIN D5
#define YELLOW_BUTTON_PIN D1

Led blue_led(BLUE_LED_PIN);
Button blue_button(BLUE_BUTTON_PIN);

Led red_led(RED_LED_PIN);
Button red_button(RED_BUTTON_PIN);

Led yellow_led(YELLOW_LED_PIN);
Button yellow_button(YELLOW_BUTTON_PIN);

void setup(){
    Serial.begin(9600);
}

void loop(){
    if(blue_button.isPressed())
        blue_led.on();
    else
        blue_led.off();

    if(red_button.isPressed())
        red_led.on();
    else
        red_led.off();

    if(yellow_button.isPressed())
        yellow_led.on();
    else
        yellow_led.off();
}