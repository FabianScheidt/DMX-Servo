#ifndef DMX_SERVO_ADDRESSPROVIDER_H
#define DMX_SERVO_ADDRESSPROVIDER_H


class AddressProvider {
public:
    virtual void loop() = 0;
    virtual int getAddress() = 0;
};


#endif //DMX_SERVO_ADDRESSPROVIDER_H
