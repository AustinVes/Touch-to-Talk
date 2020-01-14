void debugDrawSensorValues() {
  tft.fillRect(0,0,50,64,BLACK);
  tft.setCursor(0,0);
  tft.setTextSize(2);
  tft.setTextWrap(false);
  for(int i=0; i<4; i++) {
    if(sensorValues[i] == sensorMax()) {
      tft.setTextColor(RED);
    } else {
      tft.setTextColor(BLUE);
    }
    tft.println(sensorValues[i]);
  }
}

void debugDrawPowerValues() {
  tft.fillRect(50,0,50,64,BLACK);
  tft.setTextSize(2);
  tft.setTextWrap(false);
  for(int i=0; i<3; i++) {
    tft.setCursor(50,i*20);
    if(powerValues[i]) {
      tft.setTextColor(RED);
    } else {
      tft.setTextColor(BLUE);
    }
    tft.println(powerValues[i]);
  }
}

void debugDrawState() {
  tft.fillRect(0,110,100,18,BLACK);
  tft.setCursor(0,110);
  tft.setTextSize(2);
  tft.setTextWrap(false);
  if(state == "Touching") {
    tft.setTextColor(RED);
  } else {
    tft.setTextColor(BLUE);
  }
  tft.println(state);
}

void debugDrawStateChange() {
  tft.fillRect(118,118,9,9,BLACK);
  if(detectStateChange()) {
    tft.fillCircle(122, 122, 4, RED);
  }
}

void debugDrawSmoothSensorValue() {
  tft.fillRect(0,64,100,20,BLACK);
  tft.setCursor(0,64);
  tft.setTextSize(2);
  tft.setTextWrap(false);
  tft.setTextColor(GREEN);
  tft.println(smoothSensorValue);
}

