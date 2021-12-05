#ifndef DMX_SERVO_DIPSWITCHADDRESSPROVIDER_H
#define DMX_SERVO_DIPSWITCHADDRESSPROVIDER_H


#include <AddressProvider.h>

class DipSwitchAddressProvider: public AddressProvider {
    void loop() override;
    int getAddress() override;
};


#endif //DMX_SERVO_DIPSWITCHADDRESSPROVIDER_H
