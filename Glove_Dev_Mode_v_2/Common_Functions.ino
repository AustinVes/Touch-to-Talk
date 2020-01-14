int arrayLength(int array[]) {
  return (sizeof(array)/sizeof(int))-1;
}

int farrayLength(float array[]) {
  return (sizeof(array)/sizeof(float))-1;
}

int maxVal(int array[]) {
  int highestVal = array[0];
  for(int i=0; i<arrayLength(array); i++) {
    if(array[i]>highestVal) {
      highestVal=array[i];
    }
  }
  return highestVal;
}

boolean arraysEqual(int arrayOne[], int arrayTwo[], int arrayLengths) {
  if(sizeof(arrayOne)==sizeof(arrayTwo)) {
    boolean equal = true;
    for(int i=0; i<arrayLengths; i++) {
      if(arrayOne[i]!=arrayTwo[i]) {
        equal = false;
      }
    }
    return equal;
  } else {
    return false;
  }
}

boolean barraysEqual(boolean arrayOne[], boolean arrayTwo[], int arrayLengths) {
  if(sizeof(arrayOne)==sizeof(arrayTwo)) {
    boolean equal = true;
    for(int i=0; i<arrayLengths; i++) {
      if(arrayOne[i]!=arrayTwo[i]) {
        equal = false;
      }
    }
    return equal;
  } else {
    return false;
  }
}

int arrayMean(int array[], int arrayLength) {
  int sum = 0;
  for(int i=0; i<arrayLength; i++) {
    sum+=array[i];
  }
  return sum/arrayLength;
}
