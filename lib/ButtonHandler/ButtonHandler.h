#ifndef DMX_SERVO_BUTTONHANDLER_H
#define DMX_SERVO_BUTTONHANDLER_H


class ButtonHandler {
public:
    ButtonHandler(int pin, void (*downCallback)());

    void loop();

private:
    int _pin;

    void (*_downCallback)();

    bool _buttonPressed;
    unsigned long _nextDownMillis;
};


#endif //DMX_SERVO_BUTTONHANDLER_H
