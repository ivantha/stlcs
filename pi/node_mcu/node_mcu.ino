#include <ESP8266WiFi.h>
#include <MQTTClient.h>

#include <SoftwareSerial.h>
SoftwareSerial s(12, 14); // D6, D5
#include <ArduinoJson.h>

String ssid = "MyBatCave";
String password = "thewayhome";

WiFiClient WiFiclient;
MQTTClient client;

unsigned long lastMillis = 0;

void setup() {
  Serial.begin(9600);
  s.begin(9600);
  delay(10);
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  delay(2000);

  Serial.print("connecting to MQTT broker...");
  client.begin("IvanthaMacBookPro.local", WiFiclient);
  client.onMessage(messageReceived);
  connect();
}

void connect() {
  while (!client.connect("nodemcu", "try", "try")) {
    Serial.print(".");
  }

  Serial.println("\nconnected!");
  client.subscribe("local/0/cmd");
}

void messageReceived(String &topic, String &payload) {
  Serial.print("incoming: ");
  Serial.print(topic);
  Serial.print(" - ");
  Serial.print(payload);
  Serial.println();
}

void loop() {
  client.loop();
  if (!client.connected()) {
    connect();
  }

  if (s.available() > 0)
  {
    DynamicJsonDocument receiveDoc(1024);
    DeserializationError error = deserializeJson(receiveDoc, s);
    if (error) {
      return;
    }

    client.publish("local/0/data", "xx");
  }
}
