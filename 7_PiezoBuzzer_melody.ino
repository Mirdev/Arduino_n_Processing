#define P 9
#define c 262
#define d 294
#define e 330
#define f 349
#define g 392
#define a 440
#define b 494
#define C 523

int melody_1[] = {g, g, a, a, g, g, e, g, g, e, e, d, g, g, a, a, g, g, e, g, e, d, e, c};
int duration_1[] = {500, 500, 500, 500, 500, 500, 1000, 500, 500, 500, 500, 2000, 500, 500, 500, 500, 500, 500, 1000, 500, 500, 500, 500, 2000};

void setup(){
  pinMode(P, OUTPUT);
}
void loop(){
  for(int i=0; i<sizeof(melody)/sizeof(int); i++){
    tone(P, melody_1[i]);
    delay(duration_1[i]);
    noTone(P);
  }
}
