#include <TM1637Display.h>

#define CLK 8
#define DIO 9

TM1637Display disp(CLK, DIO);

void setup(){
  //! @param brightness A number from 0 (lowes brightness) to 7 (highest brightness)
  //! @param on Turn display on or off
  //setBrightness(uint8_t brightness, bool on = true)
  disp.setBrightness(0);
}

void loop(){
//  showNumberDec(int num, bool leading_zero = false, uint8_t length = 4, uint8_t pos = 0)
//  both length and pos are from left, diffrent in numbers (1~4), (0~3)
  disp.showNumberDec(7777); // 7777
  delay(1000);
  disp.showNumberDec(234, false, 3, 1); // 7 234
  delay(1000);
  disp.showNumberDec(23, true, 3); // 023 4
  delay(1000);
  disp.showNumberDec(2, false, 3); // 02 2 4
  delay(1000);
}
