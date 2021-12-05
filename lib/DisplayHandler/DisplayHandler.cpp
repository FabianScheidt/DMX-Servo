/**
 * DisplayHandler.cpp
 * Class to show a DMX address on a TM1637 display
 */
#include "DisplayHandler.h"


DisplayHandler::DisplayHandler(int clockPin, int dioPin) {
    _tm = new TM1637Display(clockPin, dioPin);
    _tm->setBrightness(2);
    showNothing();
}

DisplayHandler::~DisplayHandler() {
    delete _tm;
}

void DisplayHandler::showNothing() {
    uint8_t blank[] = { 0x00, 0x00, 0x00, 0x00 };
    _tm->setSegments(blank);
}

void DisplayHandler::showAddress(int address) {
    uint8_t data[] = { 0xff, 0xff, 0xff, 0xff };
    data[0] = _tm->encodeDigit(13);
    data[1] = _tm->encodeDigit((address / 100) % 10);
    data[2] = _tm->encodeDigit((address / 10) % 10);
    data[3] = _tm->encodeDigit(address % 10);
    _tm->setSegments(data);
}
