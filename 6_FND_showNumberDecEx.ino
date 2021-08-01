#include <TM1637Display.h>

#define CLK 8
#define DIO 9

TM1637Display disp(CLK, DIO);

void setup(){
  disp.setBrightness(0);
}

void loop(){
//  showNumberDecEx(int num, uint8_t dots = 0, bool leading_zero = false, uint8_t length = 4, uint8_t pos = 0)
//  8421 dot position
//  0.000 <= 0x80, 00.00 <= 0x40, 000.0 <= 0x20, 0000. <= 0x10
//  Our FND has only one dot(actually colon) where 0x40 position
  disp.showNumberDecEx(123, 0x40, false, 3, 0); // 12:3_
  delay(1000);
  disp.showNumberDecEx(34, 0x10, false, 2); // 34__ (colon do not work)
  delay(1000);
  disp.showNumberDecEx(34, 0x40, false, 2); // 34:__  (colon work) <- length value can't affect on dot position
  delay(1000);
  disp.showNumberDecEx(34, 0x80, false, 2, 1); // _3:4_ <- pos value only can affect on dot position
  delay(1000);
}
