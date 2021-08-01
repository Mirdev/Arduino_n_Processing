#include <Adafruit_NeoPixel.h>

#define NEO 3 // NeoPixel contol pin
#define PX_CNT 8 // led number of neopixel

Adafruit_NeoPixel ring(PX_CNT, NEO, NEO_GRB+NEO_KHZ800);

uint32_t colors[] = {ring.Color(255,0,0), ring.Color(255,127,0), ring.Color(255,255,0), ring.Color(0,255,0), ring.Color(0,0,255), ring.Color(46,43,95), ring.Color(139,0,255)};
int k=0;

void setup() {
  ring.begin();
  ring.clear();
}

void loop() {
  for(int j=-255;j<256;j+=5, k++){
    ring.setBrightness(255-abs(j));
    for(int i=0; i<PX_CNT; i++){
      ring.setPixelColor(PX_CNT-i-1, colors[(i+k)%7]);
      ring.show();
      delay(5);
    }
  }
}
