import cc.arduino.*;
import org.firmata.*;
import processing.serial.*;
Arduino arduino;

int r=9;
int g=10;
int b=11;
PImage img;

void setup(){
  img = loadImage("Lenna.png");
  surface.setSize(img.width, img.height);
  println(Arduino.list());
  arduino=new Arduino(this, Arduino.list()[0], 57600);
  arduino.pinMode(r, Arduino.OUTPUT);
  arduino.pinMode(g, Arduino.OUTPUT);
  arduino.pinMode(b, Arduino.OUTPUT);
}

void draw(){
  if (img != null) {
    image(img, 0, 0);
  }
}

void mouseDragged(){
  color c = get(mouseX, mouseY);
  arduino.analogWrite(r, int(red(c)));
  arduino.analogWrite(g, int(green(c)));
  arduino.analogWrite(b, int(blue(c)));
}
