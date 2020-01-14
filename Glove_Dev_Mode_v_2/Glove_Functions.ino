//read voltage on each finger
void readRawFingerValues() {
  for(int i=0; i<4; i++) {
    fingerValsTest[i] = analogRead(i);
  }
}

//check for update in readings
void checkUpdated() {
  updated = false;
  for(int i=0; i<4; i++) {
    if(fingerVals[i]!=fingerValsTest[i]) {
      updated = true;
    }
    fingerVals[i]=fingerValsTest[i];
  }
}

//record which fingers are being touched
void biFingerCheck() {
  for(int i=0; i<4; i++) {
    readRawFingerValues();
    checkUpdated();
    fingerTouched[i]=fingerVals[i]>=(maxVal(fingerVals)/2)&&fingerVals[i]>=10;
  }
}

//determine pad used
void padCheck() {
  padsUsed = 0;
  for(int i=5; i>2; i--) {
    pinMode(i, INPUT);
    if(digitalRead(i)==LOW) {
      padsUsed+=(int) pow(2,5-i);
      padsUsed+=(int) (5-i)/2; //corrects palm reading. god knows why I need this.
    }
    pinMode(i, OUTPUT);
    digitalWrite(i, HIGH);
  }
}

void mapFingerValues() {
  for(int i=0; i<4; i++) {
    if(fingerTouched[i]) {
      fingerValsMapped[i] = (float)((float)(fingerVals[i] - fingerCalibrationVals[i][0]) * (3 - 1) / (float)(fingerCalibrationVals[i][1] - fingerCalibrationVals[i][0]) + 1)+0.5;
    } else {
      fingerValsMapped[i] = 0;
      
    }
  }
}

void logFingerValsMapped() {
  for(int i=0; i<4; i++) {
    prevFingerValsMapped[i] = fingerValsMapped[i];
  }
}

void logPadsUsed() {
  prevPadsUsed = padsUsed;
}

void checkReleased() {
  boolean noTouches[4] = {false, false, false, false};
  released = barraysEqual(fingerTouched, noTouches, 4);
}
