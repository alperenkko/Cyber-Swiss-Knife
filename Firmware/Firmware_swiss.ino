#include <Wire.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <RF24.h>
#include <ELECHOUSE_CC1101_SRC_DRV.h>
#include <PN532_I2C.h>
#include <PN532.h>
#include <NFCAdapter.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define PIN_UP 1
#define PIN_DOWN 2
#define PIN_LEFT 3
#define PIN_RIGHT 4
#define PIN_SELECT 5

#define NRF_CE 15
#define NRF_CSN 16
RF24 radio(NRF_CE, NRF_CSN);

#define CC1101_CS 10

PN532_I2C pn532i2c(Wire);
PN532 nfc(pn532i2c);

void setup() {
  Serial.begin(115200);

  pinMode(PIN_UP, INPUT_PULLUP);
  pinMode(PIN_DOWN, INPUT_PULLUP);
  pinMode(PIN_LEFT, INPUT_PULLUP);
  pinMode(PIN_RIGHT, INPUT_PULLUP);
  pinMode(PIN_SELECT, INPUT_PULLUP);

  Wire.begin(8, 9);

  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    while(1);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println(F("Cyber-Swiss-Knife"));
  display.display();

  SPI.begin(12, 13, 11);

  radio.begin();
  
  if (ELECHOUSE_cc1101.getCC1101()) {
    Serial.println("CC1101 Connection OK");
    ELECHOUSE_cc1101.Init();
    ELECHOUSE_cc1101.setMHZ(433.92);
  } else {
    Serial.println("CC1101 Connection Error");
  }

  nfc.begin();
  uint32_t versiondata = nfc.getFirmwareVersion();
  if (!versiondata) {
    Serial.print("Didn't find PN532");
  } else {
    nfc.samConfig();
  }
}

void loop() {
  if (digitalRead(PIN_UP) == LOW) {
    Serial.println("UP pressed");
    delay(200);
  }
  if (digitalRead(PIN_DOWN) == LOW) {
    Serial.println("DOWN pressed");
    delay(200);
  }
  if (digitalRead(PIN_SELECT) == LOW) {
    Serial.println("SELECT pressed");
    delay(200);
  }
}
