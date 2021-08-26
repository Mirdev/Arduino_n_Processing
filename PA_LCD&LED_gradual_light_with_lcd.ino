#include <LiquidCrystal_I2C.h>
#define R 2
#define G 3
#define B 4

// sda = A20, scl = A21

LiquidCrystal_I2C lcd(0x27, 16, 2);
int pins[3] = {R, G, B};
float pre_rgb[3] = {0, 0, 0};

void gradation(int*, int, int);

void setup() {
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
  randomSeed(analogRead(0));
  lcd.init();
  lcd.backlight();
  lcd.begin(16, 2);
}

void loop() {
  int rgb[3] = {random(0, 255), random(0, 255), random(0, 255)};
  gradation(rgb, 10, 1000);
}

void gradation(int rgb[], int gd, int d){
  float d_rgb[3];
  for(int i=0; i<3; i++) d_rgb[i] = (rgb[i]-pre_rgb[i])/gd;
  for(int i=0; i<gd; i++){
    for(int j=0; j<3; j++) pre_rgb[j] += d_rgb[j];
    for(int j=0; j<3; j++) analogWrite(pins[j], round(pre_rgb[j]));
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("R:" + String(rgb[0]));
    lcd.setCursor(5, 0);
    lcd.print("G:" + String(rgb[1]));
    lcd.setCursor(10, 0);
    lcd.print("B:" + String(rgb[2]));
    lcd.setCursor(0, 1);
    lcd.print("R:" + String(pre_rgb[0]));
    lcd.setCursor(5, 1);
    lcd.print("G:" + String(pre_rgb[1]));
    lcd.setCursor(10, 1);
    lcd.print("B:" + String(pre_rgb[2]));
    delay(100);
  }
  delay(d);
}
