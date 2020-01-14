void readSensorPins() {
  for(int i=0; i<4; i++) {
    sensorValues[i] = analogRead(sensorPins[i]);
  }
}

void readPowerPins() {
  if(sensorMax() != 10) {
    for(int i=0; i<3; i++) {
      pinMode(powerPins[i], INPUT);
      if(digitalRead(powerPins[i])==LOW) {
        powerValues[i] = true;
      } else {
        powerValues[i] = false;
      }
      pinMode(powerPins[i], OUTPUT);
      digitalWrite(powerPins[i], HIGH);
    }
  } else {
    for(int i=0; i<3; i++) {
      powerValues[i] = false;
    }
  }
}

int sensorMax() {
  int maxValue = 10;
  for(int i=0; i<4; i++) {
    if(sensorValues[i] > maxValue) {
      maxValue = sensorValues[i];
    }
  }
  return maxValue;
}

