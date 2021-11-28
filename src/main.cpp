#include <Arduino.h>
#include <DMXSerial.h>
#include <Servo.h>
#include <ButtonHandler.h>
#include <DisplayHandler.h>
#include <AddressStorageHandler.h>

void printDmxAddress();
void handleServo();
void handleUpButton();
void handleDownButton();


// Configure Pins
int SERVO_PIN = 3;
int LED_PIN = 6;
int DISPLAY_CLK_PIN = 8;
int DISPLAY_DIO_PIN = 7;
int UP_BUTTON_PIN = 9;
int DOWN_BUTTON_PIN = 10;

// Create references to servo and display
Servo servo;
ButtonHandler upButtonHandler(UP_BUTTON_PIN, &handleUpButton);
ButtonHandler downButtonHandler(DOWN_BUTTON_PIN, &handleDownButton);
DisplayHandler displayHandler(DISPLAY_CLK_PIN, DISPLAY_DIO_PIN);
AddressStorageHandler addressStorageHandler;

void setup() {
    DMXSerial.init(DMXReceiver);
    servo.attach(SERVO_PIN);
    pinMode(LED_PIN, OUTPUT);
    printDmxAddress();
}

void loop() {
    upButtonHandler.loop();
    downButtonHandler.loop();

    handleServo();

    delay(10);
}

void printDmxAddress() {
    int address = addressStorageHandler.getAddress();
    displayHandler.setAddress(address);
}

void handleServo() {
    // Read DMX value
    int address = addressStorageHandler.getAddress();
    int value = DMXSerial.read(address);
    analogWrite(LED_PIN, value);

    // Scale DMX value and write it to servo
    int servoValue = map(value, 0, 255, 0, 180);
    servo.write(servoValue);
}

void handleUpButton() {
    addressStorageHandler.increaseAddress();
    printDmxAddress();
}

void handleDownButton() {
    addressStorageHandler.decreaseAddress();
    printDmxAddress();
}
