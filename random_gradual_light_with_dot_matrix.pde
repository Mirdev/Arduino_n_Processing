// change number or character after each step of led changing

#define REDPIN 3
#define GREENPIN 5
#define BLUEPIN 6
#include <LedControl.h>

LedControl lc = LedControl(12, 11, 10, 1); //DIN, CLK, CS, #

byte digits[11][8] = 
{
  {
    B00111100,
    B01000010,
    B01000010,
    B01000010,
    B01000010,
    B01000010,
    B01000010,
    B00111100
  },
  {
    B00001000,
    B00011000,
    B00101000,
    B00001000,
    B00001000,
    B00001000,
    B00001000,
    B00111110
  },
  {
    B00111100,
    B01000010,
    B00000010,
    B00000100,
    B00011000,
    B00100000,
    B01000000,
    B01111110
  },
  {
    B00111100,
    B01000010,
    B00000010,
    B00111100,
    B00000010,
    B00000010,
    B01000010,
    B00111100
  },
  {
    B00001000,
    B00011000,
    B00101000,
    B01001000,
    B01111110,
    B00001000,
    B00001000,
    B00001000
  },
  {
    B01111110,
    B01000000,
    B01000000,
    B01111100,
    B00000010,
    B00000010,
    B00000010,
    B01111100
  },
  {
    B00111100,
    B01000010,
    B01000000,
    B01111100,
    B01000010,
    B01000010,
    B01000010,
    B00111100
  },
  {
    B01111110,
    B01000010,
    B01000010,
    B00000100,
    B00001000,
    B00001000,
    B00001000,
    B00001000
  },
  {
    B00111100,
    B01000010,
    B01000010,
    B00111100,
    B01000010,
    B01000010,
    B01000010,
    B00111100
  },
  {
    B00111100,
    B01000010,
    B01000010,
    B01000010,
    B00111110,
    B00000010,
    B00000010,
    B00111100
  },
  {
    B01000010,
    B10100101,
    B00000000,
    B00000000,
    B00000000,
    B10000001,
    B01000010,
    B00111100
  }
};

bool led[8][8] = {{0, 1, 1, 0, 0, 1, 1, 0},
                  {1, 0, 0, 1, 1, 0, 0, 1},
                  {1, 0, 0, 0, 0, 0, 0, 1},
                  {1, 0, 0, 0, 0, 0, 0, 1},
                  {1, 0, 0, 0, 0, 0, 0, 1},
                  {0, 1, 0, 0, 0, 0, 1, 0},
                  {0, 0, 1, 0, 0, 1, 0, 0},
                  {0, 0, 0, 1, 1, 0, 0, 0}};

int pins[3] = {REDPIN, GREENPIN, BLUEPIN};
float pre_rgb[3] = {0, 0, 0};

void setColor(int*);
void gradation(float*, int*, int, int);

void setup() {
  for(int i=0; i<3; i++) pinMode(pins[i], OUTPUT);
  randomSeed(analogRead(0));
  lc.shutdown(0, false); // energy saving mode: false
  lc.setIntensity(0, 7); // 0~15
  lc.clearDisplay(0);
}

void loop() {
  int rgb[3] = {random(0, 255), random(0, 255), random(0, 255)};
  
  for(int i=0; i<11 ; i++){
    for(int j=0; j<8; j++){
      lc.setColumn(0, j, digits[i][j]);
    }
    int rgb[3] = {random(0, 255), random(0, 255), random(0, 255)};
    gradation(pre_rgb, rgb, 500, 500);
  }
  for(int row=0; row<8 ; row++){
    for(int col=0; col<8; col++){
      lc.setLed(0,col,row,led[row][col]);
    }
  }
  for(int i=0; i<3; i++) rgb[i] = random(0, 255);
  gradation(pre_rgb, rgb, 500, 500);
  for(int i=0; i<11 ; i++){
    for(int j=0; j<8; j++){
      lc.setColumn(0, j, ~digits[i][j]);
    }
    int rgb[3] = {random(0, 255), random(0, 255), random(0, 255)};
    gradation(pre_rgb, rgb, 500, 500);
  }
  for(int row=0; row<8 ; row++){
    for(int col=0; col<8; col++){
      lc.setLed(0,col,row,!led[row][col]);
    }
  }
  for(int i=0; i<3; i++) rgb[i] = random(0, 255);
  gradation(pre_rgb, rgb, 500, 500);
}

void setColor(int rgb[]){
  for(int i=0; i<3; i++) analogWrite(pins[i], rgb[i]);
}

void gradation(float pre_rgb[], int rgb[], int gd, int d){
  float d_rgb[3];
  for(int i=0; i<3; i++) d_rgb[i] = (rgb[i]-pre_rgb[i])/gd;
  for(int i=0; i<gd+1; i++){
    for(int j=0; j<3; j++) rgb[j] = round(pre_rgb[j]);
    setColor(rgb);
    for(int j=0; j<3; j++) pre_rgb[j] += d_rgb[j];
    delay(1);
  }
  delay(d);
}
