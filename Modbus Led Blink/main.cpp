#ifdef ESP8266
 #include <ESP8266WiFi.h>
#else //ESP32
 #include <WiFi.h>
#endif
#include "ModbusIP_ESP8266.h"

//ModBus libray taken from https://github.com/m2m-solutions/library-arduino-modbus-esp8266/tree/master

//Modbus Registers Offsets
const int LED_COIL = 100;
//Used Pins
const int ledPin = D4; 

IPAddress remote(192, 168, 178, 121);  // Address of Modbus Slave device

//ModbusIP object
ModbusIP mb;
  
void setup() {
  Serial.begin(9600);
 
  WiFi.begin("WiFi", "Password");
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
 
  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  mb.server();

  pinMode(ledPin, OUTPUT);
  mb.addCoil(LED_COIL);
}
 
void loop() {
   //Call once inside loop() - all magic here
  if (mb.isConnected(remote)) {   // Check if connection to Modbus Slave is established
    Serial.println("Modbus collegato");
  } else {
    mb.connect(remote);           // Try to connect if no connection
    Serial.print(".");
  }

  mb.task();

  mb.Coil(LED_COIL,digitalRead(ledPin));
  //Attach ledPin to LED_COIL register
  digitalWrite(ledPin, mb.Coil(LED_COIL));
  delay(10);
}