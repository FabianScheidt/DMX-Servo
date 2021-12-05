/**
 * ButtonHandler.cpp
 * Class to handle down events of a button that is emitted multiple times during long-press.
 */

#include "Arduino.h"
#include "ButtonHandler.h"

ButtonHandler::ButtonHandler(int pin, ButtonHandlerCallback* downCallback) {
    pinMode(pin, INPUT);
    _pin = pin;
    _downCallback = downCallback;
    _buttonPressed = false;
    _nextDownMillis = 0;
}

void ButtonHandler::loop() {
    bool buttonState = !digitalRead(_pin);
    unsigned long now = millis();
    if (buttonState) {
        if (!_buttonPressed) {
            _nextDownMillis = now + 1000;
            _downCallback->callback();
        } else if (now >= _nextDownMillis) {
            _nextDownMillis = now + 70;
            _downCallback->callback();
        }
    }
    _buttonPressed = buttonState;
}
