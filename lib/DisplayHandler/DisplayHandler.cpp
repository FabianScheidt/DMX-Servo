/**
 * DisplayHandler.cpp
 * Class to show a DMX address on a TM1637 display
 */
#include "TM1637.h"
#include "DisplayHandler.h"


DisplayHandler::DisplayHandler(int clockPin, int dioPin) {
    _tm = new TM1637(clockPin, dioPin);
    _tm->init();
    _tm->set(2);
    _tm->point(false);
}

DisplayHandler::~DisplayHandler() {
    delete _tm;
}

void DisplayHandler::setAddress(int address) {
    _tm->display(0, 13);
    _tm->display(1, (address / 100) % 10);
    _tm->display(2, (address / 10) % 10);
    _tm->display(3, address % 10);
    _tm->point(false);
}
