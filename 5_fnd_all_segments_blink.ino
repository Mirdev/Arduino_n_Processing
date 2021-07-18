#include <TM1637Display.h>

#define CLK 2
#define DIO 3

TM1637Display disp(CLK, DIO);

void setup(){
  disp.setBrightness(0);
}

void loop(){
//  FND.showNumberDecEx(1234, 0b01000000);	// 12:34(this FND has :)
//  disp.showNumberDec(4);	// ___4 (_ is blank)
//  disp.showNumberDec(4, true);	// 0004
  uint8_t data[] = {0xff, 0xff, 0xff, 0xff};
  for(int i=0; i<4; i++){	// all segments turn on and off
    disp.setBrightness(0);
    disp.setSegments(data);
    delay(100);
    disp.setBrightness(0,false);
    disp.setSegments(data);
    delay(100);
  }
}
