#define keyboardSize 27

char keyProfiles[keyboardSize][6] = {
  {1,0,0,0,1,65},  //"A"
  {2,0,0,0,1,66},  //"B"
  {3,0,0,0,1,67},  //"C"
  {4,0,0,0,1,68},  //"D"
  {5,0,0,0,1,69},  //"E"
  {0,1,0,0,1,70},  //"F"
  {0,2,0,0,1,71},  //"G"
  {0,3,0,0,1,72},  //"H"
  {0,4,0,0,1,73},  //"I"
  {0,5,0,0,1,74},  //"J"
  {0,0,1,0,1,75},  //"K"
  {0,0,2,0,1,76},  //"L"
  {0,0,3,0,1,77},  //"M"
  {0,0,4,0,1,78},  //"N"
  {0,0,5,0,1,79},  //"O"
  {0,0,0,1,1,80},  //"P"
  {0,0,0,2,1,81},  //"Q"
  {0,0,0,3,1,82},  //"R"
  {2,0,0,0,2,83},  //"S"
  {3,0,0,0,2,84},  //"T"
  {0,2,0,0,2,85},  //"U"
  {0,3,0,0,2,86},  //"V"
  {0,0,2,0,2,87},  //"W"
  {0,0,3,0,2,88},  //"X"
  {0,0,0,2,2,89},  //"Y"
  {0,0,0,3,2,90},  //"Z"
  {0,1,0,0,2,95}   //" "
};

char keyTyped() {
  for(int i=0; i<keyboardSize; i++) {
    int isolatedFingerVals[4];
    for(int j=0; j<4; j++) {
      isolatedFingerVals[j] = (int) keyProfiles[i][j];
    }
    if(arraysEqual(isolatedFingerVals, prevFingerValsMapped, 4) && prevPadsUsed == keyProfiles[i][4]) {
      return(char(keyProfiles[i][5]));
    }
  }
  return(' ');
}
