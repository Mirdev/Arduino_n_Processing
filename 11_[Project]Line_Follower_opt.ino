#define RIGHT 11
#define LEFT 12
#define MOTOR_RIGHT_F 3 //forward
#define MOTOR_RIGHT_B 5 //backward
#define MOTOR_LEFT_F 6 //forward
#define MOTOR_LEFT_B 9 //backward

int motor_pins[] = {MOTOR_RIGHT_F, MOTOR_RIGHT_B, MOTOR_LEFT_F, MOTOR_LEFT_B};
int l_speed = 160, r_speed = 150;

void setup(){
  pinMode(LEFT, INPUT), pinMode(RIGHT, INPUT);
  for(int i=0; i<sizeof(motor_pins)/sizeof(int); i++) pinMode(motor_pins[i], OUTPUT);
}

void loop() {
  bool lr[] = {digitalRead(LEFT), digitalRead(RIGHT)};
  if(lr[0]){
    if(lr[1]) analogWrite(MOTOR_RIGHT_F, r_speed), analogWrite(MOTOR_LEFT_F, l_speed);
    else analogWrite(MOTOR_RIGHT_F, 0), analogWrite(MOTOR_LEFT_F, l_speed);
  }
  else{
    if(lr[1]) analogWrite(MOTOR_RIGHT_F, r_speed), analogWrite(MOTOR_LEFT_F, 0);
    else analogWrite(MOTOR_RIGHT_F, 0), analogWrite(MOTOR_LEFT_F, 0);
  }
}
