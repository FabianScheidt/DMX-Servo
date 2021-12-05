#ifndef DMX_SERVO_DISPLAYANDBUTTONSADDRESSPROVIDER_H
#define DMX_SERVO_DISPLAYANDBUTTONSADDRESSPROVIDER_H


#include <AddressProvider.h>
#include <ButtonHandler.h>
#include <DisplayHandler.h>
#include <AddressStorageHandler.h>

class DisplayAndButtonsAddressProvider: public AddressProvider {
public:
    DisplayAndButtonsAddressProvider(int displayClkPin, int displayDioPin, int upButtonPin, int downButtonPin);
    ~DisplayAndButtonsAddressProvider();

    void loop() override;
    int getAddress() override;
    void handleUpButton();
    void handleDownButton();

protected:
    DisplayHandler* displayHandler;
    ButtonHandler* upButtonHandler;
    ButtonHandlerCallback* upButtonCallback;
    ButtonHandler* downButtonHandler;
    ButtonHandlerCallback* downButtonCallback;
    AddressStorageHandler* addressStorageHandler;
    bool displayOn;
    unsigned long displayOffMillis;

    void turnDisplayOff();
    void printAddress();
};

class UpButtonCallback: public ButtonHandlerCallback {
public:
    explicit UpButtonCallback(DisplayAndButtonsAddressProvider* displayAndButtonsAddressProvider): _displayAndButtonsAddressProvider(displayAndButtonsAddressProvider) {}
    void callback() override;

private:
    DisplayAndButtonsAddressProvider* _displayAndButtonsAddressProvider;
};

class DownButtonCallback: public ButtonHandlerCallback {
public:
    explicit DownButtonCallback(DisplayAndButtonsAddressProvider* displayAndButtonsAddressProvider): _displayAndButtonsAddressProvider(displayAndButtonsAddressProvider) {}
    void callback() override;

private:
    DisplayAndButtonsAddressProvider* _displayAndButtonsAddressProvider;
};


#endif //DMX_SERVO_DISPLAYANDBUTTONSADDRESSPROVIDER_H
