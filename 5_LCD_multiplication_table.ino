// SDA A4, SCL A5
#include <LiquidCrystal_I2C.h>

// arguments: uint8_t lcd_addr, uint8_t lcd_cols, uint8_t lcd_rows(, uint8_t charsize)
// lcd_addr: 0x27 or 0x3F
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup(){
  lcd.init();
  lcd.begin(16, 2);
  lcd.backlight();
}

void loop(){
  for(int i=2; i<10; i++){
    for(int j=1; j<10; j++){
      lcd.setCursor(0, 0);
      lcd.print(i);
      lcd.print("x");	// put char next position if already exist
      lcd.print(j);
      lcd.print("=");
      lcd.print(i*j);
      delay(1000);
    }
    lcd.clear();
  }
}
