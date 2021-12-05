/**
 * DisplayHandler.cpp
 * Class to show a DMX address on a TM1637 display
 */
#include "TM1637.h"
#include "DisplayHandler.h"


DisplayHandler::DisplayHandler(int clockPin, int dioPin) {
    _tm = new TM1637(clockPin, dioPin);
    _tm->set(BRIGHT_TYPICAL);
    _tm->point(POINT_OFF);
    _tm->clearDisplay();
}

DisplayHandler::~DisplayHandler() {
    delete _tm;
}

void DisplayHandler::showNothing() {
    _tm->point(POINT_OFF);
    _tm->clearDisplay();
}

void DisplayHandler::showAddress(int address) {
    _tm->point(POINT_OFF);
    _tm->display(0, 13);
    _tm->display(1, (int8_t) ((address / 100) % 10));
    _tm->display(2, (int8_t) ((address / 10) % 10));
    _tm->display(3, (int8_t) (address % 10));
}
