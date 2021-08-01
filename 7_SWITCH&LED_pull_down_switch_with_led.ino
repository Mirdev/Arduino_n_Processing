#define R 3
#define G 5
#define B 6
#define SW 2

bool state = 0;
int count = 0;

void setup(){
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(SW, INPUT);
}

void loop(){
  bool in = digitalRead(SW);
  if(in){
    if(!state){
      delay(10);
      count++;
      state = 1;
      Serial.println(count);
      if(count%3==1){
        digitalWrite(R, HIGH);
        digitalWrite(G, LOW);
        digitalWrite(B, LOW);
      }
      else if(count%3==2){
        digitalWrite(R, LOW);
        digitalWrite(G, HIGH);
        digitalWrite(B, LOW);
      }
      else if(count%3==0){
        digitalWrite(R, LOW);
        digitalWrite(G, LOW);
        digitalWrite(B, HIGH);
      }
    }
  }
  else{
    state=0;
  }
}
