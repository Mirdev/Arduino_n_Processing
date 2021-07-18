import cc.arduino.*;
import org.firmata.*;
import processing.serial.*;
Arduino arduino;

int r=9;
int g=10;
int b=11;

void setup(){
  size(400,400);
  background(0);
  noStroke();
  randomSeed(second());
  for(int i=0; i<20; i++){
    for(int j=0; j<20; j++){
      fill(random(0,255),random(0,255),random(0,255));
      // rect(left top point of x, left top point of y, width of rect, height of rect)
      rect(width/20*j, height/20*i, width/20, height/20);
      // ellipse(center point of x, center point of y, width of ellipse, height of ellipse)
      // ellipse(width/20*j+10, height/20*i+10, width/20, height/20);
    }
  }
  println(Arduino.list());
  arduino=new Arduino(this, Arduino.list()[0], 57600);
  arduino.pinMode(r, Arduino.OUTPUT);
  arduino.pinMode(g, Arduino.OUTPUT);
  arduino.pinMode(b, Arduino.OUTPUT);
}

void mouseDragged(){
  color c = get(mouseX, mouseY);
  arduino.analogWrite(r, int(red(c)));
  arduino.analogWrite(g, int(green(c)));
  arduino.analogWrite(b, int(blue(c)));
}
