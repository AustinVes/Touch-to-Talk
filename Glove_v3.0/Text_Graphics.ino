void drawLargeChar(String key) {
  tft.fillRect(0,0,40,40,BLACK);
  tft.setCursor(0,0);
  tft.setTextSize(5);
  tft.setTextWrap(false);
  tft.setTextColor(GREEN);
  tft.println(key);
}

void drawMediumText(String text) {
  tft.setCursor(0,0);
  tft.setTextSize(4);
  tft.setTextWrap(true);
  tft.setTextColor(GREEN, BLACK);
  tft.println(text.concat(' '));
}

void drawSmallText(String text) {
  tft.setCursor(0,0);
  tft.setTextSize(3);
  tft.setTextWrap(true);
  tft.setTextColor(GREEN, BLACK);
  tft.println(text.concat(' '));
}

