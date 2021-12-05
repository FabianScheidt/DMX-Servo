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
}

int DisplayAndButtonsAddressProvider::getAddress() {
    return addressStorageHandler->getAddress();
}

void DisplayAndButtonsAddressProvider::printAddress() {
    displayHandler->setAddress(getAddress());
}

void DisplayAndButtonsAddressProvider::handleUpButton() {
    addressStorageHandler->increaseAddress();
    printAddress();
}

void DisplayAndButtonsAddressProvider::handleDownButton() {
    addressStorageHandler->decreaseAddress();
    printAddress();
}

void UpButtonCallback::callback() {
    _displayAndButtonsAddressProvider->handleUpButton();
}

void DownButtonCallback::callback() {
    _displayAndButtonsAddressProvider->handleDownButton();
}
