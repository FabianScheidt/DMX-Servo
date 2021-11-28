#include <DMXSerial.h>
#include <Servo.h>
#include <TM1637.h>
#include <EEPROM.h>
#include <ButtonHandler.h>


void handleButtons();
void printDmxAddress();
void handleServo();
int getDmxAddress();
void setDmxAddress(int address);
void increaseDmxAddress();
void decreaseDmxAddress();


// Configure Pins
int SERVO_PIN = 3;
int LED_PIN = 6;
int DISPLAY_CLK_PIN = 8;
int DISPLAY_DIO_PIN = 7;
int UP_BUTTON_PIN = 9;
int DOWN_BUTTON_PIN = 10;

// Create references to servo and display
Servo servo;
TM1637 tm(DISPLAY_CLK_PIN, DISPLAY_DIO_PIN);
ButtonHandler upButtonHandler(UP_BUTTON_PIN, &increaseDmxAddress);
ButtonHandler downButtonHandler(DOWN_BUTTON_PIN, &decreaseDmxAddress);

void setup() {
    DMXSerial.init(DMXReceiver);

    servo.attach(SERVO_PIN);

    tm.init();
    tm.set(2);

    pinMode(LED_PIN, OUTPUT);
    pinMode(UP_BUTTON_PIN, INPUT);
    pinMode(DOWN_BUTTON_PIN, INPUT);
}

void loop() {
    handleButtons();
    printDmxAddress();
    handleServo();
    delay(10);
}

void handleButtons() {
    upButtonHandler.loop();
    downButtonHandler.loop();
}

void printDmxAddress() {
    int address = getDmxAddress();
    tm.display(0, 13);
    tm.display(1, (address / 100) % 10);
    tm.display(2, (address / 10) % 10);
    tm.display(3, address % 10);
}

void handleServo() {
    // Read DMX value
    int address = getDmxAddress();
    int value = DMXSerial.read(address);
    analogWrite(LED_PIN, value);

    // Scale DMX value and write it to servo
    int servoValue = map(value, 0, 255, 0, 180);
    servo.write(servoValue);
}

int getDmxAddress() {
    int address = EEPROM.read(0) | (EEPROM.read(1) << 8);

    if (address < 1 || address > 512) {
        return 1;
    }
    return address;
}

void setDmxAddress(int address) {
    EEPROM.write(0, address & 0xff);
    EEPROM.write(1, address >> 8);
}

void increaseDmxAddress() {
    int address = getDmxAddress();
    address++;
    if (address > 512) {
        address = 1;
    }
    setDmxAddress(address);
}

void decreaseDmxAddress() {
    int address = getDmxAddress();
    address--;
    if (address < 1) {
        address = 512;
    }
    setDmxAddress(address);
}