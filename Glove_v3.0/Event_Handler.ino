String getCurrentState() {
  if(sensorMax() == 10) {
    return "Open";
  } else {
    return "Touching";
  }
}

void updateState() {
  prevState = state;
  state = getCurrentState();
}

boolean detectStateChange() {
  if(state != prevState) {
    return true;
  } else {
    return false;
  }
}
