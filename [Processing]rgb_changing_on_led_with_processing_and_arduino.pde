// This code is previously needed arduino firmata package(file > example > Firmata > StandardFirmata) on arduino board(compile and upload are needed)

import cc.arduino.*;
import org.firmata.*;
import processing.serial.*;
Arduino arduino;

int r=3;
int g=5;
int b=6;

void setup(){
  size(400,400);
  background(0);
  fill(255,0,0);
  noStroke();
  rect(width/2, 0, width/2, height/2);
  fill(0,255,0);
  noStroke();
  rect(0, height/2, width/2, height/2);
  fill(0,0,255);
  noStroke();
  rect(width/2, height/2, width/2, height/2);
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
}

void mouseMoved(){
  if(mouseX<width/2 && mouseY<height/2){
    arduino.digitalWrite(r, Arduino.LOW);
    arduino.digitalWrite(g, Arduino.LOW);
    arduino.digitalWrite(b, Arduino.LOW);
  }
  else if(mouseX>=width/2 && mouseY<height/2){
    arduino.digitalWrite(r, Arduino.HIGH);
    arduino.digitalWrite(g, Arduino.LOW);
    arduino.digitalWrite(b, Arduino.LOW);
  }
  else if(mouseX<width/2 && mouseY>=height/2){
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
