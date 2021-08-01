#include <LiquidCrystal_I2C.h>
#include <DS1302.h>
#include <Wire.h> //use A4,A5 pins

#define CLK 4 // SCLK
#define DAT 3 // IO
#define RST 2 // CE(Reset)

DS1302 rtc(RST, DAT, CLK);
LiquidCrystal_I2C lcd(0x27, 16, 2);
// A4: SDA, A5: SCL

void setup() {
  rtc.halt(false);
  rtc.writeProtect(false);

  lcd.init();
  lcd.backlight();
  lcd.begin(16,2);

  Serial.begin(9600);

  rtc.setDOW(WEDNESDAY);
  rtc.setTime(19,36,0);
  rtc.setDate(22,07,2021);
}

void loop() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(rtc.getDOWStr());
  lcd.setCursor(8, 0);
  lcd.print(rtc.getTimeStr());
  lcd.setCursor(3, 1);
  lcd.print(rtc.getDateStr());
  delay(500);
}
