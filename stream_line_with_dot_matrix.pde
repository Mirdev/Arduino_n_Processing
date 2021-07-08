// stream line with double dot matrix

#include <LedControl.h>

LedControl lc = LedControl(12, 11, 10, 2); //DIN, CLK, CS, #

void setup() {
  lc.shutdown(0, false); // energy saving mode: false
  lc.setIntensity(0, 7); // 0~15
  lc.clearDisplay(0);
  lc.shutdown(1, false); // energy saving mode: false
  lc.setIntensity(1, 7); // 0~15
  lc.clearDisplay(1);
}

void loop() {
  for(int i=0; i<16; i++){
    if(i<8){
      lc.setRow(0, i, B00011000);
      delay(10);}
    else{
      lc.setRow(1, i-8, B00011000);
      delay(10);}
  }
  for(int i=0; i<16; i++){
    if(i<8){
      lc.setRow(0, i, B00000000);
      delay(10);}
    else{
      lc.setRow(1, i-8, B00000000);
      delay(10);}
  }
}
