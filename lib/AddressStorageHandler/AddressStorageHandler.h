#ifndef DMX_SERVO_ADDRESSSTORAGEHANDLER_H
#define DMX_SERVO_ADDRESSSTORAGEHANDLER_H


class AddressStorageHandler {
public:
    AddressStorageHandler();
    AddressStorageHandler(int eepromIdx1, int eepromIdx2);

    int getAddress();
    void setAddress(int address);
    void increaseAddress();
    void decreaseAddress();

private:
    int _eepromIdx1;
    int _eepromIdx2;
};


#endif //DMX_SERVO_ADDRESSSTORAGEHANDLER_H
