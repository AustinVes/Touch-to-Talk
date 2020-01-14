const int pad1pin = 40;
const int pad2pin = 42;
const int finger1pin = 44;
const int finger2pin = 46;
const int pad1ledpin = 52;
const int pad2ledpin = 50;
const int finger1ledpin = 51; 
const int finger2ledpin = 53;
int pad1state = 0;
int pad2state = 0;

void setup() {
  pinMode(finger1pin, INPUT);
  pinMode(finger2pin, INPUT);
  pinMode(pad1ledpin, OUTPUT);
  pinMode(pad2ledpin, OUTPUT);
  pinMode(finger1ledpin, OUTPUT);
  pinMode(finger2ledpin, OUTPUT);
}

void loop() {
  pinMode(pad1pin, OUTPUT);
  pinMode(pad2pin, OUTPUT);
  digitalWrite(pad1pin, HIGH);
  digitalWrite(pad2pin, HIGH);
  digitalWrite(finger1ledpin, digitalRead(finger1pin));
  digitalWrite(finger2ledpin, digitalRead(finger2pin));
  pinMode(pad1pin, INPUT);
  if (digitalRead(pad1pin)==LOW) {
    pad1state = HIGH;
  } else {
    pad1state = LOW;
  }
  pinMode(pad1pin, OUTPUT);
  pinMode(pad2pin, INPUT);
  if (digitalRead(pad2pin)==LOW) {
    pad2state = HIGH;
  } else {
    pad2state = LOW;
  }
  digitalWrite(pad1ledpin, pad1state);
  digitalWrite(pad2ledpin, pad2state);
  pinMode(pad2pin, OUTPUT);
}
