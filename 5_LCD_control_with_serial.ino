// SDA A4, SCL A5
#include <LiquidCrystal_I2C.h>

// arguments: uint8_t lcd_addr, uint8_t lcd_cols, uint8_t lcd_rows(, uint8_t charsize)
// lcd_addr: 0x27 or 0x3F
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup(){
  lcd.init();
  lcd.begin(16, 2);
  lcd.backlight();
  Serial.begin(9600);
}

void loop(){
  if(Serial.available()){
    char data = Serial.read();
    switch(data){
      case '1':
        lcd.clear();
        lcd.print("num 1");
        lcd.scrollDisplayLeft();
        break;
      case '2':
        lcd.clear();
        lcd.setCursor(0,1);	// setCursor(cols=position of x axis, rows=position of first or second line);
        lcd.print("num 2");
        break;
    }
  }
}
