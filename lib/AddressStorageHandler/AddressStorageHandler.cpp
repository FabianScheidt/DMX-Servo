/**
 * AddressStorageHandler.cpp
 */
#include "Arduino.h"
#include "EEPROM.h"
#include "AddressStorageHandler.h"

int MIN_ADDRESS = 1;
int MAX_ADDRESS = 512;

AddressStorageHandler::AddressStorageHandler(int eepromIdx1, int eepromIdx2) {
    _eepromIdx1 = eepromIdx1;
    _eepromIdx2 = eepromIdx2;
}

AddressStorageHandler::AddressStorageHandler() : AddressStorageHandler(0, 1) {
}


int AddressStorageHandler::getAddress() {
    int address = EEPROM.read(_eepromIdx1) | (EEPROM.read(_eepromIdx2) << 8);

    if (address < MIN_ADDRESS || address > MAX_ADDRESS) {
        return 1;
    }
    return address;
}

void AddressStorageHandler::setAddress(int address) {
    address = constrain(address, MIN_ADDRESS, MAX_ADDRESS);
    EEPROM.write(_eepromIdx1, address & 0xff);
    EEPROM.write(_eepromIdx2, address >> 8);
}

void AddressStorageHandler::increaseAddress() {
    int address = getAddress();
    address++;
    if (address > MAX_ADDRESS) {
        address = MIN_ADDRESS;
    }
    setAddress(address);
}

void AddressStorageHandler::decreaseAddress() {
    int address = getAddress();
    address--;
    if (address < MIN_ADDRESS) {
        address = MAX_ADDRESS;
    }
    setAddress(address);
}
