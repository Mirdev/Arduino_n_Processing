#define RIGHT 11
#define LEFT 12
#define MOTOR_RIGHT_F 3 //forward
#define MOTOR_RIGHT_B 5 //backward
#define MOTOR_LEFT_F 6 //forward
#define MOTOR_LEFT_B 9 //backward

int speed_val = 120;

void setup(){
  pinMode(LEFT, INPUT);
  pinMode(RIGHT, INPUT);
  pinMode(MOTOR_RIGHT_F, OUTPUT);
  pinMode(MOTOR_RIGHT_B, OUTPUT);
  pinMode(MOTOR_LEFT_F, OUTPUT);
  pinMode(MOTOR_LEFT_B, OUTPUT);
}

void loop() {
  bool left = digitalRead(LEFT);
  bool right = digitalRead(RIGHT);
  if((left==HIGH) && (right==HIGH)){
    analogWrite(MOTOR_RIGHT_F, speed_val);
    analogWrite(MOTOR_RIGHT_B, 0);
    analogWrite(MOTOR_LEFT_F, speed_val);
    analogWrite(MOTOR_LEFT_B, 0);
  }
  else if((left==LOW) && (right==HIGH)){
    analogWrite(MOTOR_RIGHT_F, speed_val);
    analogWrite(MOTOR_RIGHT_B, 0);
    analogWrite(MOTOR_LEFT_F, 0);
    analogWrite(MOTOR_LEFT_B, speed_val);
  }
  else if((left==HIGH) && (right==LOW)){
    analogWrite(MOTOR_RIGHT_F, 0);
    analogWrite(MOTOR_RIGHT_B, speed_val);
    analogWrite(MOTOR_LEFT_F, speed_val);
    analogWrite(MOTOR_LEFT_B, 0);
  }
  else if((left==LOW) && (right==LOW)){
    analogWrite(MOTOR_RIGHT_F, 0);
    analogWrite(MOTOR_RIGHT_B, 0);
    analogWrite(MOTOR_LEFT_F, 0);
    analogWrite(MOTOR_LEFT_B, 0);
  }
}
