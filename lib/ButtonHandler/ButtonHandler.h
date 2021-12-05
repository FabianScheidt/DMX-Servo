#ifndef DMX_SERVO_BUTTONHANDLER_H
#define DMX_SERVO_BUTTONHANDLER_H

class ButtonHandlerCallback {
public:
    virtual ~ButtonHandlerCallback() = default;
    virtual void callback() = 0;
};

class ButtonHandler {
public:
    ButtonHandler(int pin, ButtonHandlerCallback* downCallback);

    void loop();

private:
    int _pin;
    ButtonHandlerCallback* _downCallback;

    bool _buttonPressed;
    unsigned long _nextDownMillis;
};


#endif //DMX_SERVO_BUTTONHANDLER_H
