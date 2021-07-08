// with arduino board and RGB LED

#define REDPIN 3  // for using "define"
const int greenpin = 5; // for using "const"
int bluepin = 6;
int pins[3] = {REDPIN, greenpin, bluepin};
float pre_rgb[3] = {0, 0, 0};

void setColor(int*);
void gradation(int*, int, int);

void setup(){
  for(int i=0; i<3; i++) pinMode(pins[i], OUTPUT);
  randomSeed(analogRead(0)); // This line returns from 0 to 1023 value when read the disconnected analog port
}

void loop(){
  int rgb[3] = {random(0, 255), random(0, 255), random(0, 255)};
  gradation(rgb, 1000, 1000);
}

void setColor(int rgb[]){
  for(int i=0; i<3; i++) analogWrite(pins[i], rgb[i]);
}

void gradation(int rgb[], int gd, int d){
  float d_rgb[3];
  for(int i=0; i<3; i++) d_rgb[i] = (rgb[i]-pre_rgb[i])/gd;
  for(int i=0; i<gd; i++){
    for(int j=0; j<3; j++) rgb[j] = round(pre_rgb[j]);
    setColor(rgb);
    for(int j=0; j<3; j++) pre_rgb[j] += d_rgb[j];
    delay(1);
  }
  delay(d);
}
