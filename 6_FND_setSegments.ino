#include <TM1637Display.h>

#define CLK 8
#define DIO 9

TM1637Display disp(CLK, DIO);

// |[2_]F -(_1)A | (_2)B
//        -[4_]G
// |[1_]E -(_8)D | (_4)C :[8_]P (_!__) // Our FND has only one colon where middle of FND. So second digit from left only can use 8_ segment.

uint8_t alphabet[] = {0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71, 0x6f, 0x76, 0x06, 0x0e, 0x79, 0x38, 0x00, 0x37, 0x5c, 0x73, 0x67, 0x50, 0x6d, 0x07, 0x36, 0x1c, 0x00, 0x00, 0x6f, 0x5b}; // M, w, x cannot make.
uint8_t seg_done[] = {SEG_B|SEG_C|SEG_D|SEG_E|SEG_G, SEG_A|SEG_B|SEG_C|SEG_D|SEG_E|SEG_F, SEG_A|SEG_B|SEG_C|SEG_E|SEG_F, SEG_A|SEG_D|SEG_E|SEG_F|SEG_G};
uint8_t seg[4];
uint8_t clr[] = {0, 0, 0, 0};
const char *str = "Nice";

void setup(){
  disp.setBrightness(0);
  disp.setSegments(clr);
}

void loop(){
  for(int i=0; i<strlen(str); i++){
    if(str[i]>96){
      seg[i] = alphabet[str[i]-97];
    }
    else if(str[i]>64){
      seg[i] = alphabet[str[i]-65];
    }
  }
  for(int k=-7; k<8; k++){
    disp.setBrightness(abs(k), true);
    disp.setSegments(seg);
    delay(100);
  }
  disp.setSegments(seg_done);
  delay(1000);
}
