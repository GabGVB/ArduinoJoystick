#include <LiquidCrystal.h>

// Initializare LCD
LiquidCrystal lcd(4, 6, 10, 11, 12, 13);  

int JoyStick_X = A0;
int JoyStick_Y = A1;
int JoyStick_Z = 2; // buton joystick

// Poziția jucătorului pe ecran
int x_pos = 0;
int y_pos = 0;

// Definirea caracterului custom
byte playerChar[8] = {
  B01100,
  B01100,
  B00000,
  B01110,
  B11100,
  B01100,
  B11010,
  B10011
};

void setup() {
  lcd.begin(16, 2);
  lcd.createChar(0, playerChar); // salvează caracterul la slotul 0
  lcd.clear();
  pinMode(JoyStick_Z, INPUT_PULLUP);
}

void loop() {
  int x = analogRead(JoyStick_X);
  int y = analogRead(JoyStick_Y);

  // Control pe X (coloane)
  if (x < 300 && x_pos > 0) {
    x_pos--;
  } else if (x > 700 && x_pos < 15) {
    x_pos++;
  }

  // Control pe Y (rânduri)
  if (y < 300 && y_pos > 0) {
    y_pos--;
  } else if (y > 700 && y_pos < 1) {
    y_pos++;
  }

  lcd.clear();
  lcd.setCursor(x_pos, y_pos);
  lcd.write(byte(0)); // afișează caracterul custom

  delay(200); // timp pentru debounce
}
