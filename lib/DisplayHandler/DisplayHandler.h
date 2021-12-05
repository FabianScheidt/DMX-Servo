#include <TM1637Display.h>

#ifndef DMX_SERVO_DISPLAYHANDLER_H
#define DMX_SERVO_DISPLAYHANDLER_H


class DisplayHandler {
public:
    DisplayHandler(int clockPin, int dioPin);
    ~DisplayHandler();

    void showNothing();
    void showAddress(int address);

private:
    TM1637Display* _tm;
};


#endif //DMX_SERVO_DISPLAYHANDLER_H
