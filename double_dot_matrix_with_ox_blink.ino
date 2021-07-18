#include <LedControl.h>

LedControl lc = LedControl(12, 11, 10, 2); //DIN, CLK, CS, #

byte shape1[] = {
  B00111100,
  B01000010,
  B01000010,
  B01000010,
  B01000010,
  B01000010,
  B01000010,
  B00111100
};

byte shape2[] = {
  B01000010,
  B01000010,
  B00100100,
  B00011000,
  B00011000,
  B00100100,
  B01000010,
  B01000010
};

void setup() {
  lc.shutdown(0, false); // energy saving mode: false
  lc.setIntensity(0, 7); // 0~15
  lc.clearDisplay(0);
  lc.shutdown(1, false); // energy saving mode: false
  lc.setIntensity(1, 7); // 0~15
  lc.clearDisplay(1);
  display_shape(0, 0);
  display_shape(1, 0);
}

void display_shape(int module, int type){
  if(type == 0){
    for(int i=0; i<8; i++){
      lc.setColumn(module, i, B00000000);
    }
  }
  else if(type == 1){
    for(int i=0; i<8; i++){
      lc.setColumn(module, i, shape1[i]);
    }
  }
  else if(type == 2){
    for(int i=0; i<8; i++){
      lc.setColumn(module, i, shape2[i]);
    }
  }
}

void loop() {
  display_shape(1, 1);
  display_shape(0, 0);
  delay(500);
  display_shape(1, 0);
  display_shape(0, 2);
  delay(500);
}
