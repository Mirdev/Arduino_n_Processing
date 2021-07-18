// SDA A4, SCL A5
#include <LiquidCrystal_I2C.h>

// arguments: uint8_t lcd_addr, uint8_t lcd_cols, uint8_t lcd_rows(, uint8_t charsize)
// lcd_addr: 0x27 or 0x3F
LiquidCrystal_I2C lcd(0x27, 16, 2);
const char* s = "Hello World";

void setup(){
  lcd.init();
  lcd.begin(16, 2);
  lcd.backlight();
  for(int i=0; i<strlen(s); i++){
    lcd.scrollDisplayLeft();
    delay(150);
  }
}

void loop(){
  for(int i=0; i<16+strlen(s); i++){
    lcd.scrollDisplayRight();
    delay(150);
  }
  for(int i=0; i<16+strlen(s); i++){
    lcd.scrollDisplayLeft();
    delay(150);
  }
}
