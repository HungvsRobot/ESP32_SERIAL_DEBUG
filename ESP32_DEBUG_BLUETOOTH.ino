#include <Wire.h>
#include <string.h> 
#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

uint32_t tsLastReport = 0;
void onBeatDetected(){
    Serial.println("Beat!");
}

void setup(){
    Serial.begin(115200);
    Serial2.begin(115200);
    SerialBT.begin("ROBOT_TRAU_LOE"); 
    pinMode(14, OUTPUT);
    pinMode(2, OUTPUT);
    
}
String data = ""; 
String data1 = "";
void loop(){
  
  if(SerialBT.available()){
    data1 = SerialBT.readStringUntil(':');
    Serial.println(data1); Serial2.println(data1 + '\n');
    digitalWrite(2, 1);
  }else{
    digitalWrite( 2, 0);
  }

 // Serial2.println("=");
  if(Serial2.available()){
    data = Serial2.readStringUntil('\n') + "\n"; 
    Serial.println(data);SerialBT.println(data);
    digitalWrite(18, 1);
  } else{
    digitalWrite(18, 0);
  }

  if(Serial.available()){
    data = Serial.readStringUntil('\n') + "\n"; 
    Serial.println(data);SerialBT.println(data);
    digitalWrite(14, 1);
  } else{
    digitalWrite(14, 0);
  }
}
