// SoundSensor on A0 pin, normal input vol value is around 100

#include <Adafruit_NeoPixel.h>

#define NEO 3
#define PX_CNT 8

int state = 0;
int vol = 0;

Adafruit_NeoPixel ring(PX_CNT, NEO, NEO_GRB+NEO_KHZ800);

void setup() {
  ring.begin();
  ring.clear();
  ring.setBrightness(40);
  Serial.begin(9600);
}

void loop() {
  vol = analogRead(A0);
  Serial.println(vol);
  int map_vol = map(vol, 0, 1023, 0, 255);
  for(int i=0; i<PX_CNT; i++){
    ring.setPixelColor(i, ring.Color(100, map_vol, 100));
    ring.show();
  }
}
