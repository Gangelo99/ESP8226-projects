#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>

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

#endif