/**
 * DisplayAndButtonsAddressProvider.cpp
 */

#include "DisplayAndButtonsAddressProvider.h"


DisplayAndButtonsAddressProvider::DisplayAndButtonsAddressProvider(
        int displayClkPin,
        int displayDioPin,
        int upButtonPin,
        int downButtonPin
) {
    displayHandler = new DisplayHandler(displayClkPin, displayDioPin);
    upButtonCallback = new UpButtonCallback(this);
    upButtonHandler = new ButtonHandler(upButtonPin, upButtonCallback);
    downButtonCallback = new DownButtonCallback(this);
    downButtonHandler = new ButtonHandler(downButtonPin, downButtonCallback);
    addressStorageHandler = new AddressStorageHandler();
    displayOn = true;
    displayOffMillis = 0;
    printAddress();
}

DisplayAndButtonsAddressProvider::~DisplayAndButtonsAddressProvider() {
    delete displayHandler;
    delete upButtonCallback;
    delete upButtonHandler;
    delete downButtonCallback;
    delete downButtonHandler;
    delete addressStorageHandler;
}

void DisplayAndButtonsAddressProvider::loop() {
    upButtonHandler->loop();
    downButtonHandler->loop();

    if (displayOn && millis() > displayOffMillis) {
        turnDisplayOff();
    }
}

int DisplayAndButtonsAddressProvider::getAddress() {
    return addressStorageHandler->getAddress();
}

void DisplayAndButtonsAddressProvider::turnDisplayOff() {
    displayOn = false;
    displayHandler->showNothing();
}

void DisplayAndButtonsAddressProvider::printAddress() {
    displayOn = true;
    displayOffMillis = millis() + 10000;
    displayHandler->showAddress(getAddress());
}

void DisplayAndButtonsAddressProvider::handleUpButton() {
    if (displayOn) {
        addressStorageHandler->increaseAddress();
    }
    printAddress();
}

void DisplayAndButtonsAddressProvider::handleDownButton() {
    if (displayOn) {
        addressStorageHandler->decreaseAddress();
    }
    printAddress();
}

void UpButtonCallback::callback() {
    _displayAndButtonsAddressProvider->handleUpButton();
}

void DownButtonCallback::callback() {
    _displayAndButtonsAddressProvider->handleDownButton();
}
