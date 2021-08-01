#include <Adafruit_NeoPixel.h>

#define SW 2
#define NEO 3
#define PX_CNT 8
#define BZ 6
#define c 262
#define d 294
#define e 330
#define f 349
#define g 392
#define a 440
#define b 494
#define C 523

Adafruit_NeoPixel ring(PX_CNT, NEO, NEO_GRB+NEO_KHZ800);

int note[] = {c, d, e, f, g, a, b, C};

void setup() {
  ring.begin();
  ring.clear();
  ring.setBrightness(40);
  pinMode(SW, INPUT);
  pinMode(BZ, OUTPUT);
  randomSeed(A0);
}

void loop() {
  if(digitalRead(SW)){
    for(int i=0;i<3;i++){
      for(int i=0; i<PX_CNT; i++){
        ring.setPixelColor(i, ring.Color(random(255),random(255),random(255)));
        ring.show();
        tone(BZ, note[i], 100);
        delay(100);
        ring.setPixelColor(i, ring.Color(0,0,0));
        ring.show();
      }
    }
    ring.setPixelColor(random(PX_CNT), ring.Color(64,0,0));
    ring.show();
    delay(3000);
    ring.clear();
    ring.show();
  }
}
