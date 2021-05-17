#include <SoftwareSerial.h>
#include <ArduinoJson.h>

SoftwareSerial s(15, 14); 

void setup() {
  Serial.begin(9600);
  s.begin(9600);

  pinMode(22, INPUT_PULLUP);
  pinMode(23, INPUT_PULLUP);
  pinMode(24, INPUT_PULLUP);
  pinMode(25, INPUT_PULLUP);
  pinMode(26, INPUT_PULLUP);
  
  pinMode(27, INPUT_PULLUP);
  pinMode(28, INPUT_PULLUP);
  pinMode(29, INPUT_PULLUP);
  pinMode(30, INPUT_PULLUP);
  pinMode(31, INPUT_PULLUP);
  
  pinMode(32, INPUT_PULLUP);
  pinMode(33, INPUT_PULLUP);
  pinMode(34, INPUT_PULLUP);
  pinMode(35, INPUT_PULLUP);
  pinMode(36, INPUT_PULLUP);

  pinMode(37, INPUT_PULLUP);
  pinMode(38, INPUT_PULLUP);
  pinMode(39, INPUT_PULLUP);
  pinMode(40, INPUT_PULLUP);
  pinMode(41, INPUT_PULLUP);

  pinMode(42, INPUT_PULLUP);
  pinMode(43, INPUT_PULLUP);
  pinMode(44, INPUT_PULLUP);
  pinMode(45, INPUT_PULLUP);
  pinMode(46, INPUT_PULLUP);

  pinMode(47, INPUT_PULLUP);
  pinMode(48, INPUT_PULLUP);
  pinMode(49, INPUT_PULLUP);
  pinMode(50, INPUT_PULLUP);
  pinMode(51, INPUT_PULLUP);
}

void loop() {
  // if commands are available
  if (s.available() > 0)
  {
    // get commands
    DynamicJsonDocument receiveDoc(1024);
    DeserializationError error = deserializeJson(receiveDoc, s);
    if (!error) {
      String cmd = receiveDoc["cmd"];
    }
  }

  DynamicJsonDocument sendDoc(1024);
  
  // update sensor data
  sendDoc["r1l1s1"] = digitalRead(22);
  sendDoc["r1l1s2"] = digitalRead(23);
  sendDoc["r1l1s3"] = digitalRead(24);
  sendDoc["r1l1s4"] = digitalRead(25);
  sendDoc["r1l1s5"] = digitalRead(26);

  sendDoc["r1l2s1"] = digitalRead(27);
  sendDoc["r1l2s2"] = digitalRead(28);
  sendDoc["r1l2s3"] = digitalRead(29);
  sendDoc["r1l2s4"] = digitalRead(30);
  sendDoc["r1l2s5"] = digitalRead(31);

  sendDoc["r1l3s1"] = digitalRead(32);
  sendDoc["r1l3s2"] = digitalRead(33);
  sendDoc["r1l3s3"] = digitalRead(34);
  sendDoc["r1l3s4"] = digitalRead(35);
  sendDoc["r1l3s5"] = digitalRead(36);

  sendDoc["r1l4s1"] = digitalRead(37);
  sendDoc["r1l4s2"] = digitalRead(38);
  sendDoc["r1l4s3"] = digitalRead(39);
  sendDoc["r1l4s4"] = digitalRead(40);
  sendDoc["r1l4s5"] = digitalRead(41);

  sendDoc["r1l5s1"] = digitalRead(42);
  sendDoc["r1l5s2"] = digitalRead(43);
  sendDoc["r1l5s3"] = digitalRead(44);
  sendDoc["r1l5s4"] = digitalRead(45);
  sendDoc["r1l5s5"] = digitalRead(46);

  sendDoc["r1l6s1"] = digitalRead(47);
  sendDoc["r1l6s2"] = digitalRead(48);
  sendDoc["r1l6s3"] = digitalRead(49);
  sendDoc["r1l6s4"] = digitalRead(50);
  sendDoc["r1l6s5"] = digitalRead(51);

  // send sensor data
  serializeJson(sendDoc, s);
}
