const int pinVRx = A0;   // axa X
const int pinVRy = A1;   // axa Y
/*
const int ledLeft = 4;
const int ledRight = 5;
const int ledUp = 2;
const int ledDown = 3;
*/
const int ledLeft = 3;
const int ledRight = 2;
const int ledUp = 4;
const int ledDown = 5;


const int deadZone = 100;
void setup() {
  pinMode(ledLeft, OUTPUT);
  pinMode(ledRight, OUTPUT);
  pinMode(ledUp, OUTPUT);
  pinMode(ledDown, OUTPUT);


}

void loop() {
  int x = analogRead(pinVRx);  // 0 - 1023
  int y = analogRead(pinVRy);  // 0 - 1023

 int intensityLeft = 0;
  int intensityRight = 0;
  int intensityUp = 0;
  int intensityDown = 0;

  // Direcție orizontală
  if (x < 512 - deadZone) {
    intensityLeft = map(x, 0, 512 - deadZone, 255, 0);  // invers pentru fade
  } else if (x > 512 + deadZone) {
    intensityRight = map(x, 512 + deadZone, 1023, 0, 255);
  }

  // Direcție verticală
  if (y < 512 - deadZone) {
    intensityUp = map(y, 0, 512 - deadZone, 255, 0);
  } else if (y > 512 + deadZone) {
    intensityDown = map(y, 512 + deadZone, 1023, 0, 255);
  }
    analogWrite(ledLeft, constrain(intensityLeft, 0, 255));
  analogWrite(ledRight, constrain(intensityRight, 0, 255));
  analogWrite(ledUp, constrain(intensityUp, 0, 255));
  analogWrite(ledDown, constrain(intensityDown, 0, 255));

  delay(10); // pentru stabilitate
}
