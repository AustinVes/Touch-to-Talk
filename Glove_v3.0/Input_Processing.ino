void updateSmoothSensorValue() {
  smoothingSampleSize++;
  int newSensorSample = sensorValues[activeSensorPinIndex()];
  smoothSensorValue = (smoothSensorValue*smoothingSampleSize - smoothSensorValue + newSensorSample)/smoothingSampleSize;
}

int activeSensorPin() {
  int activeSensorPin;
  for(int i=0; i<4; i++) {
    if(sensorValues[i]==sensorMax()) {
      activeSensorPin = sensorPins[i];
    }
  }
  return activeSensorPin;
}

int activeSensorPinIndex() {
  int activeSensorPinIndex;
  for(int i=0; i<4; i++) {
    if(sensorValues[i]==sensorMax()) {
      activeSensorPinIndex = i;
    }
  }
  storedActiveSensorPinIndex = activeSensorPinIndex;
  return activeSensorPinIndex;
}

int activePowerPin() {
  int activePowerPin;
  for(int i=0; i<3; i++) {
    if(powerValues[i]) {
      activePowerPin = powerPins[i];
    }
  }
  return activePowerPin;
}

int activePowerPinIndex() {
  int activePowerPinIndex;
  for(int i=0; i<3; i++) {
    if(powerValues[i]) {
      activePowerPinIndex = i;
    }
  }
  storedActivePowerPinIndex = activePowerPinIndex;
  return activePowerPinIndex;
}

