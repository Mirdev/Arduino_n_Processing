#define R 2
#define G 3
#define B 4
#define SE 5
#define BZ 11

bool pre_se;
int time_delta = 0;
unsigned long start_time = 0;

void setup() {
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(BZ, OUTPUT);
  pinMode(SE, INPUT_PULLUP);
  pre_se = digitalRead(SE);
  pre_clk = digitalRead(CLK);
}

void loop() {
  bool cur_se = digitalRead(SE);
  if(pre_se^cur_se){
    start_time = millis();
    pre_se = cur_se;
  }
  if(cur_se){
    digitalWrite(R, 0);
    digitalWrite(G, 1);
    digitalWrite(B, 0);
    digitalWrite(BZ, 0);
  }
  else{
    time_delta = millis()-start_time;
    if(time_delta%1500 < 500){
      digitalWrite(R, 1);
      digitalWrite(G, 0);
      digitalWrite(B, 0);
    }
    else if(time_delta%1500 < 1000){
      digitalWrite(R, 0);
      digitalWrite(G, 1);
      digitalWrite(B, 0);
    }
    else{
      digitalWrite(R, 0);
      digitalWrite(G, 0);
      digitalWrite(B, 1);
    }
    if(time_delta < 1000*5){
      if(time_delta%1000 < 500)
        digitalWrite(BZ, 1);
      else
        digitalWrite(BZ, 0);
    }
  }
}
