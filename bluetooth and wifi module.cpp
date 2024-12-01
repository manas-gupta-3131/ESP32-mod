#include "BluetoothSerial.h"
BluetoothSerial SerialBT;
void setup(){
  Serial.begin(115200);
  SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
}

void loop(){
  if (SerialBT.available()){
    Serial.write(SerialBT.read());
  }
  if (Serial.available()){
    SerialBT.write(Serial.read());
  }
  delay(20);
}

//Wifi module 

#include "WiFi.h"
const char* ssid = "BUNZU";
const char* password = "Manas431";

void setup(){
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status()!=WL_CONNECTED){
    delay(1000);
    Serial.println("Connecting to WiFi.."); 
  }
  Serial.println("Connected to the WiFi network");
}
void loop(){
}
