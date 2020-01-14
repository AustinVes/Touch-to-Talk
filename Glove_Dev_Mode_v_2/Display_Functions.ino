void displayRawInput() {
  display.setTextSize(1);
  for(int i=0; i<4; i++) {
    display.println(fingerNames[i]+": "+String(fingerVals[i]));
  }
}

void displayFingersTouched() {
  display.setTextSize(1);
  for(int i=0; i<4; i++) {
    if(fingerTouched[i]) {
      display.println(fingerNames[i]);
    }
  }
}

void displayPadsTouched() {
  display.setTextSize(1);
  int padsUsed_ = padsUsed;
  for(int i=2; i>=0; i--) {
    if(padsUsed_>=pow(2,i)) {
      display.println(padNames[i]);
      padsUsed_-=pow(2,i);
    }
  }
}

void displayCalibrated() {
  display.setTextSize(1);
  display.println(calibrated);
}

void displayMappedInput() {
  display.setTextSize(1);
  for(int i=0; i<4; i++) {
    display.println(fingerNames[i]+": "+String(fingerValsMapped[i]));
  }
}

void drawProgressCircle(int rate, int i) {
  display.fillCircle(width/2, height/2, 40, BLACK);
  display.fillRect(8, 8, 80, 80-rate*i, WHITE);
  display.drawCircle(width/2, height/2, 40, BLACK);
  display.fillCircle(width/2, height/2, 20, WHITE);
  display.drawCircle(width/2, height/2, 20, BLACK);
  display.refresh();
}
