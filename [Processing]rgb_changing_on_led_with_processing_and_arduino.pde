// This code is previously needed arduino firmata package(file > example > Firmata > StandardFirmata) on arduino board(compile and upload are needed)
// vertically devided(four rectangle)

import cc.arduino.*;
import org.firmata.*;
import processing.serial.*;
Arduino arduino;

int r=3;
int g=5;
int b=6;

void setup(){
  size(600, 400);
  background(255);
  size(400,400);
  background(0);
  fill(255,0,0);
  noStroke();
  rect(width/4, 0, width/4, height);
  fill(0,255,0);
  noStroke();
  rect(width/4*2, 0, width/4, height);
  fill(0,0,255);
  noStroke();
  rect(width/4*3, 0, width/4, height);
  println(Arduino.list());
  arduino=new Arduino(this, Arduino.list()[0], 57600);
  arduino.pinMode(r, Arduino.OUTPUT);
  arduino.pinMode(g, Arduino.OUTPUT);
  arduino.pinMode(b, Arduino.OUTPUT);
  
  println(Arduino.list());
  arduino=new Arduino(this, Arduino.list()[0],57600);
  arduino.pinMode(pin, Arduino.OUTPUT);
}

void draw(){
  arduino.digitalWrite(pin, Arduino.HIGH);
  delay(1000);
  arduino.digitalWrite(pin, Arduino.LOW);
  delay(1000);
}

void mouseMoved(){
  if(mouseX<width/4){
    arduino.digitalWrite(r, Arduino.LOW);
    arduino.digitalWrite(g, Arduino.LOW);
    arduino.digitalWrite(b, Arduino.LOW);
  }
  else if(mouseX>=width/4 && mouseX<width/4*2){
    arduino.digitalWrite(r, Arduino.HIGH);
    arduino.digitalWrite(g, Arduino.LOW);
    arduino.digitalWrite(b, Arduino.LOW);
  }
  else if(mouseX>=width/4*2 && mouseX<width/4*3){
    arduino.digitalWrite(r, Arduino.LOW);
    arduino.digitalWrite(g, Arduino.HIGH);
    arduino.digitalWrite(b, Arduino.LOW);
  }
  else{
    arduino.digitalWrite(r, Arduino.LOW);
    arduino.digitalWrite(g, Arduino.LOW);
    arduino.digitalWrite(b, Arduino.HIGH);
  }
}
