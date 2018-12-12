#include <TimerOne.h>
#define out1 3
#define out2 9

int clk = 10;
int pwmMax = 255;
int pwm1 = 50;
int pwm2 = 200;
volatile int cnt = 0;

void pwm(int p);

void setup() {
  pinMode(out1, OUTPUT);
  pinMode(9, OUTPUT);

  Timer1.initialize(clk);
  Timer1.attachInterrupt(pwm);
}

void loop() {
  
  //digitalWrite(out1, HIGH);
  //delayMicroseconds(val); 
  //digitalWrite(out1, LOW);
  //delayMicroseconds(max - val);
  //analogWrite(9, 126);

  
  
}

void pwm(){
  
  cnt++;  if (cnt >= pwmMax) cnt = 0;
  if(cnt < pwm1){
    digitalWrite(out2, HIGH);
  }  else if(cnt == pwm1) {
    digitalWrite(out2, LOW);
  }

  if(cnt < pwm2){
    digitalWrite(out1, HIGH);
  }  else if(cnt == pwm2) {
    digitalWrite(out1, LOW);
  }
}
