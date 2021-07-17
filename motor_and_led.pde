#define MOTOR1_A 3
#define MOTOR1_B 5
#define MOTOR2_A 6
#define MOTOR2_B 9
#define RPN 12
#define GPN 11
#define BPN 10
#define TOUCH 2

int output_pins[] = {MOTOR1_A, MOTOR1_B, MOTOR2_A, MOTOR2_B, RPN, GPN, BPN};
int input_pins[] = {TOUCH};
int len_output_pins = sizeof(output_pins)/sizeof(int);
int len_input_pins = sizeof(input_pins)/sizeof(int);

int speed_value = 0;
int brightness = -3;

void setColor(bool, int, int);
void setBrightness(int, bool);
void setMotor(int);

void setup() {
  for(int i=0; i<len_output_pins; i++) pinMode(output_pins[i], OUTPUT);
  for(int i=0; i<len_input_pins; i++) pinMode(input_pins[i], INPUT);
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(TOUCH)){
    if(++speed_value>255) speed_value=255;
    Serial.println(speed_value);
    setMotors(speed_value);
    setBrightness(speed_value);
  }
  else{
    if(--speed_value<0) speed_value = 0;
    Serial.println(speed_value);
    setMotors(speed_value);
    setBrightness(speed_value, 1);
  }
}

void setColor(bool r, int g, int b){
  digitalWrite(RPN, r);
  analogWrite(GPN, g);
  analogWrite(BPN, b);
}

void setBrightness(int speed_value, bool acc=0){
  acc?int s=-1:int s=1;
  if(speed_value<86){
    setColor(0, 0, brightness+=s*3);
    if(speed_value>84) brightness = 255*acc;
  }
  else if(speed_value<171){
    setColor(0, brightness+=s*3, 0);
    if(speed_value>169) brightness = 255*acc;
  }
  else{
    setColor(1, 0, 0);
  }
}

void setMotors(int speed_value){
  analogWrite(MOTOR1_A, speed_value);
  analogWrite(MOTOR1_B, 0);
  analogWrite(MOTOR2_A, speed_value);
  analogWrite(MOTOR2_B, 0);
}
