int rotation = 0;

void writeToMessage() {
  if(calculateKey() == "DEL") {
    message.remove(message.length()-1);
  } else if(calculateKey() == "ROTATE") {
    rotation++;
    rotation % 4;
    tft.fillScreen(BLACK);
    tft.setRotation(rotation);
  } else {
    message.concat(calculateKey());
  }
}

String calculateKey() {
  return keyboardKeys[storedActivePowerPinIndex][storedActiveSensorPinIndex][findPositionIndex(storedActivePowerPinIndex, storedActiveSensorPinIndex)];
}

int findPositionIndex(int i, int j) {
  int closestFitIndex = 0;
  for(int k=0; k<5; k++) {
    if(abs(keyboardValues[i][j][k] - smoothSensorValue) < abs(keyboardValues[i][j][closestFitIndex] - smoothSensorValue)) {
      closestFitIndex = k;
    }
  }
  return closestFitIndex;
}

