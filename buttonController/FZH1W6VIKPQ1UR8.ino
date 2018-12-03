#include <PS3BT.h>


USB Usb;
BTD Btd(&Usb);
PS3BT PS3(&Btd);

#define enA 9 //lewy
#define in1 4
#define in2 5
#define enB 3 //prawy
#define in3 6
#define in4 7
int speed = 255;

void setup() {
  Serial.begin(115200);
  if (Usb.Init() == -1) {
    Serial.print(F("\r\nOSC did not start"));
    while (1); //halt
  }
  Serial.print(F("\r\nPS3 Bluetooth Library Started"));
  
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  analogWrite(enA, speed);
  analogWrite(enB, speed);
}

void loop() {
  Usb.Task();


  if (PS3.PS3Connected || PS3.PS3NavigationConnected) {
    
    
    if (PS3.getButtonPress(CROSS)) {
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
    }
    else {
      digitalWrite(in1, LOW);
      digitalWrite(in3, LOW);
    }
    
    if (PS3.getButtonPress(TRIANGLE)) {
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
    }
    else {
      digitalWrite(in2, LOW);
      digitalWrite(in4, LOW);
    } 

    
    
    if (PS3.PS3Connected) {

      if (PS3.getButtonClick(PS)) {
        PS3.disconnect();
      }
    }
  }
     
}
