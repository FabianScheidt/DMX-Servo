#include "TM1637.h"

#ifndef DMX_SERVO_DISPLAYHANDLER_H
#define DMX_SERVO_DISPLAYHANDLER_H


class DisplayHandler {
public:
    explicit DisplayHandler(TM1637 tm);

    static DisplayHandler init(int clockPin, int dioPin);
    void setAddress(int address);

private:
    TM1637 _tm;
};


#endif //DMX_SERVO_DISPLAYHANDLER_H
