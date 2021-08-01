#include <Adafruit_NeoPixel.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h> //A4,A5
// A4: SDA, A5: SCL

#define NEO 3
#define PX_CNT 8
#define LEFT 11
#define RIGHT 12

Adafruit_NeoPixel ring(PX_CNT, NEO, NEO_GRB+NEO_KHZ800);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  ring.begin();
  ring.clear();
  ring.setBrightness(40);
  Serial.begin(9600);
  pinMode(LEFT, INPUT);
  pinMode(RIGHT, INPUT);
  pinMode(NEO, OUTPUT);
  lcd.init();
  lcd.backlight();
  lcd.begin(16,2);
}

void loop() {
  bool left=0, right=0;
  left = digitalRead(LEFT);
  right = digitalRead(RIGHT);
  lcd.setCursor(0,0);
  lcd.print(left);
  lcd.setCursor(15,0);
  lcd.print(right);
  if(left){
    if(right){
      Serial.println("go forward");
      for(int i=0; i<PX_CNT; i++){
        ring.setPixelColor(i, ring.Color(255, 255, 255));
        ring.show();
      }
    }
    else{
      Serial.println("turn right");
      for(int i=0; i<PX_CNT; i++){
        if(i<4)
          ring.setPixelColor(i, ring.Color(255, 255, 255));
        else
          ring.setPixelColor(i, ring.Color(0, 0, 0));
        ring.show();
      }
    }
  }
  else{
    if(!right){
      Serial.println("stop");
      for(int i=0; i<PX_CNT; i++){
        ring.setPixelColor(i, ring.Color(0, 0, 0));
        ring.show();
      }
    }
    else{
      Serial.println("turn left");
      for(int i=0; i<PX_CNT; i++){
        if(i>3)
          ring.setPixelColor(i, ring.Color(255, 255, 255));
        else
          ring.setPixelColor(i, ring.Color(0, 0, 0));
        ring.show();
      }
    }
  }
}
