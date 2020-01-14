//OLED LIBRARIES AND DEFINITIONS
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1351.h>
#include <SPI.h>

#define sclk 13
#define mosi 11
#define dc   7
#define cs   9
#define rst  8

#define BLACK           0x0000
#define BLUE            0x001F
#define RED             0xF800
#define GREEN           0x07E0
#define CYAN            0x07FF
#define MAGENTA         0xF81F
#define YELLOW          0xFFE0  
#define WHITE           0xFFFF

Adafruit_SSD1351 tft = Adafruit_SSD1351(cs, dc, rst);

//HAPTIC MOTOR LIBRARIES AND DEFINITIONS


//GLOVE VARIABLES
int powerPins[3] = {2,1,0};
int powerValues[3] = {false, false, false};
int sensorPins[4] = {6,7,8,9};
int sensorValues[4];

String state = "Open";
String prevState = "Open";
int storedActiveSensorPinIndex = 0;
int storedActivePowerPinIndex = 0;

float smoothSensorValue = 0;
int smoothingSampleSize = 0;

String message = "";

void setup() {
  Serial.begin(9600);
  Serial.println("Booted.");

  //PREP DISPLAY
  tft.begin();
  tft.fillScreen(BLACK);

  //CONFIGURE OUTPUT PINS
  for(int i=0; i<3; i++) {
    pinMode(powerPins[i], OUTPUT);
    digitalWrite(powerPins[i], HIGH);
  }
}

void loop() {
  readSensorPins();
  readPowerPins();
  updateState();

  if(detectStateChange()) {
    if(state == "Open") {
      writeToMessage();
      drawMediumText(message);
      //drawLargeChar(calculateKey());
      smoothSensorValue = 0;
      smoothingSampleSize = 0;
    }
  }

  if(state == "Touching") {
    updateSmoothSensorValue();
  }

  //debugDrawSensorValues();
  //debugDrawPowerValues();
  //debugDrawSmoothSensorValue();
  //debugDrawStateChange();
  if(detectStateChange()) {
    //debugDrawState();
  }
  
  delay(0);
}

