#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

const int thumbtip = 6;
const int thumbfat = 4;
const int palm = 3;
const int index = A0;
const int middle = A1;
const int ring = A2;
const int pinky = A3;

boolean touching = false;

String finger = "";

Adafruit_PCD8544 display = Adafruit_PCD8544(13, 11, 10, 8, 9);

void setup()   {
  pinMode(index, INPUT);
  pinMode(middle, INPUT);
  pinMode(ring, INPUT);
  pinMode(pinky, INPUT);
  pinMode(thumbtip, OUTPUT);
  pinMode(thumbfat, OUTPUT);
  pinMode(palm, OUTPUT);
  
  Serial.begin(9600);
  
  display.begin();
  
  display.setContrast(50);
  analogWrite(5, 255);
  
  digitalWrite(thumbtip, HIGH);
  digitalWrite(thumbfat, HIGH);
  digitalWrite(palm, HIGH);
  
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(0,0);
  display.println("Operating.");
  display.display();
}

void loop() {
  display.clearDisplay();
  
  display.print("Index: ");
  display.println(analogRead(index), 2);
  display.print("Middle: ");
  display.println(analogRead(middle), 2);
  display.print("Ring: ");
  display.println(analogRead(ring), 2);
  display.print("Pinky: ");
  display.println(analogRead(pinky), 2);
  
  pinMode(thumbtip, INPUT);
  if(digitalRead(thumbtip)==LOW) {
    display.println("Thumb Tip");
  }
  pinMode(thumbtip, OUTPUT);
  digitalWrite(thumbtip, HIGH);
  
  pinMode(thumbfat, INPUT);
  if(digitalRead(thumbfat)==LOW) {
    display.println("Thumb Fat");
  }
  pinMode(thumbfat, OUTPUT);
  digitalWrite(thumbfat, HIGH);
  
  pinMode(palm, INPUT);
  if(digitalRead(palm)==LOW) {
    display.println("Palm");
  }
  pinMode(palm, OUTPUT);
  digitalWrite(palm, HIGH);
  
  display.display();
}
