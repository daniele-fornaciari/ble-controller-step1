#include "EB_Bluetooth_4_0.h"
#include <SoftwareSerial.h>
#include <WString.h>
 
#define LED 4
#define RX 11
#define TX 10
 
EB_Bluetooth_4_0 myBluetooth(RX,TX);
 
void setup(){
  Serial.begin(9600);
  pinMode(LED,OUTPUT);
  digitalWrite(LED,LOW);
  myBluetooth.begin();
  Serial.println("Waiting to be connected");
}
 
void loop(){
  String command = "";
  while(myBluetooth.available()){
    command += (char)myBluetooth.read();
  }
  switch(command.charAt(1)){
    case '0':
      digitalWrite(LED,LOW);
    break;
    case '1':
      digitalWrite(LED,HIGH);
    break;
  }
}

