#include <SPI.h>
#include <PS3BT.h>                                                    //Include the necessary libraries.


USB Usb;

BTD Btd(&Usb);

PS3BT PS3(&Btd);







void setup() {

   Serial.begin(115200);

  

   if (Usb.Init() == -1) {

    Serial.print(F("\r\nOSC did not start"));

    while (1); //halt

  }

  Serial.print(F("\r\nPS3 Bluetooth Library Started"));




}

void loop()

{

  Usb.Task();



  if (PS3.PS3Connected || PS3.PS3NavigationConnected) {

 
    Serial.println("X");
    Serial.println(PS3.getAnalogHat(LeftHatX));

    Serial.println("Y");
    Serial.println(PS3.getAnalogHat(LeftHatY));

  }

  if (PS3.getButtonClick(UP)) {




    Serial.print(F("\r\nUp"));



     if (PS3.PS3Connected) {

      PS3.setLedOff();

      PS3.setLedOn(LED1);



    }

  }

}
