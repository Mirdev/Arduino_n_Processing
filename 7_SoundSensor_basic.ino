#define S A0
#define R 3
#define P 9

void setup(){
  pinMode(R, OUTPUT);
  pinMode(S, INPUT);
  pinMode(P, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  int state = analogRead(S);
  tone(P, 262);
  Serial.println(state, DEC);
  state>50?digitalWrite(R, 1):digitalWrite(R, 0);
}
