#include <LiquidCrystal_I2C.h>
#define R 2
#define G 3
#define B 4
#define CLK 8
#define DT 9
#define SW 10

// sda = A20, scl = A21
LiquidCrystal_I2C lcd(0x27, 16, 2);

int count = 0;
int rgb = 0;
bool pre_clk;
bool pre_sw;

void set_lcd(int rgb, int count){
  lcd.clear();
  if(rgb%3 == 2){
    lcd.setCursor(0, 0);
    lcd.print("R:" + String(0));
    lcd.setCursor(5, 0);
    lcd.print("G:" + String(0));
    lcd.setCursor(10, 0);
    lcd.print(">B:" + String(count));
  }
  else if(rgb%3){
    lcd.setCursor(0, 0);
    lcd.print("R:" + String(0));
    lcd.setCursor(5, 0);
    lcd.print(">G:" + String(count));
    lcd.setCursor(11, 0);
    lcd.print("B:" + String(0));
  }
  else{
    lcd.setCursor(0, 0);
    lcd.print(">R:" + String(count));
    lcd.setCursor(6, 0);
    lcd.print("G:" + String(0));
    lcd.setCursor(11, 0);
    lcd.print("B:" + String(0));
  }
}

void set_led(int rgb, int count){
  analogWrite(rgb%3+2, count);
  analogWrite((rgb+1)%3+2, 0);
  analogWrite((rgb+2)%3+2, 0);
}

void setup() {
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(CLK, INPUT);
  pinMode(DT, INPUT);
  pinMode(SW, INPUT_PULLUP);
  lcd.init();
  lcd.backlight();
  lcd.begin(16, 2);
  pre_sw = digitalRead(SW);
  pre_clk = digitalRead(CLK);
  set_lcd(rgb, count);
  set_led(rgb, count);
}

void loop() {
  bool cur_clk = digitalRead(CLK);
  bool cur_sw = digitalRead(SW);
  if(pre_sw^cur_sw){
    if(!cur_sw){
      rgb++;
      set_lcd(rgb, count);
      set_led(rgb, count);
    }
    pre_sw = cur_sw;
    delay(100);
  }
  if(pre_clk^cur_clk){
    if(digitalRead(DT)^cur_clk){
      count+=10;
      if(count>255) count = 255;
    }
    else{
      count-=10;
      if(count<0) count = 0;
    }
    set_lcd(rgb, count);
    set_led(rgb, count);
  }
  pre_clk = cur_clk;
}
