// Gradually turn on red, green and blue leds while touch on touch sensor

#define TOUCH 2
#define REDPIN 3
#define GREENPIN 5
#define BLUEPIN 6

int state = 0;
int pins[3] = {REDPIN, GREENPIN, BLUEPIN};
int count = 0;

void setup() {
  Serial.begin(9600);
  pinMode(TOUCH, INPUT);
  for(int i=0; i<3; i++) pinMode(pins[i], OUTPUT);
}

void loop() {
 if(state){
    digitalWrite(REDPIN, HIGH);
    count++;
    if(count>255)
      count = 255;
    Serial.print(count);
    Serial.println("Touched");

    if(count>40){
      digitalWrite(REDPIN, LOW);
      digitalWrite(BLUEPIN, HIGH);
      digitalWrite(GREENPIN, LOW);
    }
    else if(count>20){
      digitalWrite(REDPIN, LOW);
      digitalWrite(GREENPIN, HIGH);
    }
  }
  else{
    count--;
    if(count<0)
      count = 0;
    Serial.print(count);
    Serial.println("Untouched");
    
    if(count<=0){
      digitalWrite(REDPIN, LOW);
    }
    else if(count < 20){
      digitalWrite(REDPIN, HIGH);
      digitalWrite(GREENPIN, LOW);
    }
    else if(count < 40){
      digitalWrite(BLUEPIN, LOW);
      digitalWrite(GREENPIN, HIGH);
    }
  }
  delay(50);
}
