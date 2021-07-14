#define TOUCH 2
#define REDPIN 3
#define GREENPIN 5
#define BLUEPIN 6

int state = 0;
int last_state = 0;
int pins[3] = {REDPIN, GREENPIN, BLUEPIN};
int count = 0;

void setColor(int r, int g, int b){
  analogWrite(REDPIN, r);
  analogWrite(GREENPIN, g);
  analogWrite(BLUEPIN, b);
}

void setup() {
  Serial.begin(9600);
  pinMode(TOUCH, INPUT);
  for(int i=0; i<3; i++) pinMode(pins[i], OUTPUT);
}

void loop() {
  state = digitalRead(TOUCH);

  if(state != last_state){
    if(state && !last_state){
      count++;
      last_state = state;
      if(!(count % 8)){
        setColor(0, 0, 0);
        Serial.println("OFF");
      }
      else if(count % 8 == 1){
        setColor(255, 0, 0);
        Serial.println("RED");
      }
      else if(count % 8 == 2){
        setColor(255, 50, 0);
        Serial.println("ORANGE");
      }
      else if(count % 8 == 3){
        setColor(255, 255, 0);
        Serial.println("YELLOW");
      }
      else if(count % 8 == 4){
        setColor(0, 255, 0);
        Serial.println("GREEN");
      }
      else if(count % 8 == 5){
        setColor(0, 0, 255);
        Serial.println("BLUE");
      }
      else if(count % 8 == 6){
        setColor(0, 0, 139);
        Serial.println("INDIGO");
      }
      else if(count % 8 == 7){
        setColor(128, 0, 128);
        Serial.println("PURPLE");
      }
    }
  }
  else{
    Serial.println("not touched");
  }
  last_state = state;
}
