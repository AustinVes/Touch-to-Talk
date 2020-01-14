boolean customGesture(boolean fingerSig[4], int padSig) {
  return (padsUsed==padSig) && barraysEqual(fingerTouched, fingerSig, 4);
}

boolean notGesturing() {
  boolean fingerSig[4] = {false,false,false,false};
  int padSig = 0;
  return (padsUsed==padSig) && barraysEqual(fingerTouched, fingerSig, 4);
}

boolean calibrationGesture() {
  boolean fingerSig[4] = {true,true,false,false};
  int padSig = 2;
  return (padsUsed==padSig) && barraysEqual(fingerTouched, fingerSig, 4);
}

boolean messageModeGesture() {
  boolean fingerSig[4] = {true, false, false, true};
  int padSig = 1;
  return (padsUsed==padSig) && barraysEqual(fingerTouched, fingerSig, 4);
}
