#include <LiquidCrystal_I2C.h>

#define R 4
#define G 5
#define B 6
#define BZ 7
#define DR 8
#define ST 9

#define DT 2
#define CLK 3
#define SW 18
#define NE 10

#define STEP 200

LiquidCrystal_I2C lcd(0x27, 16, 2);

int output_pins[] = {R, G, B, BZ, DR, ST};
int input_pins[] = {DT, CLK, SW, NE};

bool pre_clk = 0;
bool pre_sw = 0;
unsigned long debounce = 0;

int stack = 0;
int pre_index = 0;
bool pre_position = 0;
int index = 0;
bool index_position = 0;

String menu[] = {" EXIT", " MOTOR TEST", " HEATING BED", " EMERGENCY SET"};
int menu_size[] = {1, 4, 2, 2};

float angle = 0;

void display_menu(String str1, String str2){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(str1);
  lcd.setCursor(0, 1);
  lcd.print(str2);
  if(stack){
    lcd.setCursor(0, index_position);
    lcd.print(">");
  }
}

void update_menu(){
  switch(stack){
    case 0:
      display_menu("X:   Y:     A001", "3D PRINTER READY");
      break;
    case 1:
      display_menu(menu[index-index_position], menu[index-index_position+1]);
      pre_index = index;
      pre_position = index_position;
      break;
    case 2:
      switch(pre_index){
        case 0:
          stack -= 2;
          update_menu();
          break;
        case 1:
          display_menu(String(" ANGLE:")+angle<0?””:”+”+angle, " RETURN");
          break;
        case 2:
          display_menu(" HEATING:", " RETURN");
          break;
        case 3:
          display_menu(" STATE:", " RETURN");
          break;
      }
      break;
    case 3:
      switch(index){
        case 0:
          switch(pre_index){
            case 1:
              break;
            case 2:
              break;
            case 3:
              break;
          }
          break;
        case 1:
          index = pre_index;
          index_position = pre_position;
          stack -= 2;
          update_menu();
          break;
      }
      break;
  }
}

void setup() {
  for(int i=0; i<sizeof(output_pins)/sizeof(int); i++) pinMode(output_pins[i], OUTPUT);
  for(int i=0; i<sizeof(input_pins)/sizeof(int); i++) pinMode(input_pins[i], INPUT_PULLUP);
  Serial.begin(9600);
  pre_clk = digitalRead(CLK);
  pre_sw = digitalRead(SW);
  lcd.init();
  lcd.begin(16, 2);
  lcd.backlight();
  display_menu("3D PRINTER  A001", "READY TO DRIVE");
  delay(5000);
  update_menu();
  debounce = millis();
}

void loop() {
  bool cur_sw = digitalRead(SW);
  if(pre_sw^cur_sw){
    if(!cur_sw){
      stack++;
      index = 0;
      index_position = 0;
      update_menu();
      delay(500);
    }
    pre_sw = cur_sw;
  }
  if(stack){
    bool cur_clk = digitalRead(CLK);
    if(pre_clk^cur_clk){
      if(debounce - millis() > 1000){
        if(cur_clk^digitalRead(DT)){
          index++;
          index_position = 1;
          Serial.println(index);
          if(index>menu_size[stack]-1){
            index=0;
            index_position = 0;
          }
          update_menu();
        }
        else{
          index--;
          index_position = 0;
          if(index<0){
            index=menu_size[stack]-1;
            index_position = 1;
          }
          update_menu();
        }
      }
      debounce = millis();
      pre_clk = cur_clk;
    }
  }
}
