#include <Adafruit_GFX.h>
#include <Adafruit_SharpMem.h>
#include <MemoryFree.h>

//Definitions for glove
int fingerVals[] = {0,0,0,0};
int fingerValsTest[4];
boolean fingerTouched[4];
int fingerCalibrationVals[4][2];
int fingerValsMapped[4];
int prevFingerValsMapped[4];
boolean calibrated = false;
// Index A0
// Middle A1
// Ring A2
// Pinky A3
String fingerNames[] = {
  "index", 
  "middle",
  "ring",
  "pinky"
};
// THUMBTIP 5
// THUMBFAT 4
// PALM 3
String padNames[] = {
  "Thumbtip",
  "Thumbfat",
  "Palm"
};
int padsUsed;
int prevPadsUsed;
boolean updated = true;
boolean released = false;

//Definitions for display
#define SCK 10
#define MOSI 11
#define SS 13
#define BLACK 0
#define WHITE 1
#define width 96
#define height 96
Adafruit_SharpMem display(SCK, MOSI, SS);

void setup() {
  //Initialize pad pins
  for(int i=5; i>2; i--) {
    pinMode(i, OUTPUT);
    digitalWrite(i, HIGH);
  }
  
  display.begin();
  display.clearDisplay();
  display.setTextColor(BLACK);
}

void loop() {
  readRawFingerValues();
  
  checkUpdated();
  
  if(updated) {
    biFingerCheck();
    
    if(calibrated) {
      mapFingerValues();
    }
    
    padCheck();
    
    //write to the display
    display.setCursor(0,0);
    if(calibrated) {
      //displayMappedInput();
      //display.println(released);
    } else {
      display.clearDisplay();
      displayRawInput();
      display.println(freeMemory());
    }
    //displayFingersTouched();
    //displayPadsTouched();
    //displayCalibrated();
    display.refresh();
    
    //calibrate
    if(calibrationGesture()) {
      boolean gestureHeld = true;
      display.clearDisplay();
      for(int i=0; i<6 && gestureHeld; i++) {
        drawProgressCircle(16,i);
        biFingerCheck();
        padCheck();
        gestureHeld = calibrationGesture();
        delay(100);
      }
      if(gestureHeld) {
        gestureHeld = false;
        display.clearDisplay();
        display.setCursor(0,0);
        display.setTextSize(2);
        display.setTextWrap(true);
        display.println("CALIB.\nMODE");
        display.refresh();
        delay(1000);
        for(int i=0; i<4; i++) {
          String positionNames[2] = {"base", "tip"};
          for(int j=0; j<2; j++) {
            boolean pointCalibrated = false;
            while(!pointCalibrated) {
              display.clearDisplay();
              display.setCursor(0,0);
              display.setTextSize(1);
              display.println("Thumbtip\nto\n"+fingerNames[i]+" "+positionNames[j]);
              display.refresh();
              boolean fingerSig[4] = {false, false, false, false};
              fingerSig[i] = true;
              while(!customGesture(fingerSig, 1)) {
                biFingerCheck();
                padCheck();
              }
              gestureHeld = true;
              int calibrationReadings[4];
              display.clearDisplay();
              for(int k=0; k<5 && gestureHeld; k++) {
                if(k>0) {
                  calibrationReadings[k-1] = analogRead(i);
                }
                drawProgressCircle(20,k);
                biFingerCheck();
                padCheck();
                gestureHeld = customGesture(fingerSig, 1);
                delay(100);
              }
              if(gestureHeld) {
                pointCalibrated = true;
                fingerCalibrationVals[i][j] = arrayMean(calibrationReadings, 4);
                display.clearDisplay();
                display.setCursor(0,0);
                display.setTextSize(1);
                display.println("Remove Finger");
                display.println(fingerCalibrationVals[i][0]);
                display.println(fingerCalibrationVals[i][1]);
                display.refresh();
                while(!notGesturing()) {
                  biFingerCheck();
                  padCheck();
                }
              }
            }
          }
        }
        calibrated = true;
        display.clearDisplay();
        display.setCursor(0,0);
        display.setTextSize(2);
        display.println("Calib.\nComplete");
        display.refresh();
      }
    }
    
    if(calibrated) {
      checkReleased();
      if(released) {
        display.clearDisplay();
        display.setCursor(18,6);
        display.setTextSize(12);
        display.println(keyTyped());
        display.refresh();
      } else {
        logFingerValsMapped();
        logPadsUsed();
      }
    }
  }
}
