#include <Arduino.h>
#include <DMXSerial.h>
#include <Servo.h>
#include <AddressProvider.h>
#include <DisplayAndButtonsAddressProvider.h>

void handleServo();

// Configure Pins
int SERVO_PIN = 3;
int LED_PIN = 6;
int DISPLAY_CLK_PIN = 8;
int DISPLAY_DIO_PIN = 7;
int UP_BUTTON_PIN = 9;
int DOWN_BUTTON_PIN = 10;

// Create references to servo and display
Servo servo;
AddressProvider* addressProvider = new DisplayAndButtonsAddressProvider(DISPLAY_CLK_PIN, DISPLAY_DIO_PIN, UP_BUTTON_PIN, DOWN_BUTTON_PIN);

void setup() {
    DMXSerial.init(DMXReceiver);
    servo.attach(SERVO_PIN);
    pinMode(LED_PIN, OUTPUT);
}

void loop() {
    addressProvider->loop();
    handleServo();
    delay(10);
}

void handleServo() {
    // Read DMX value
    int address = addressProvider->getAddress();
    int value = DMXSerial.read(address);
    analogWrite(LED_PIN, value);

    // Scale DMX value and write it to servo
    int servoMicrosecondsValue = map(value, 0, 255, 2400, 544);
    servo.writeMicroseconds(servoMicrosecondsValue);
}
