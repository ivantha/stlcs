void setup() {
  Serial.begin(9600);
  Serial2.begin(9600);
}

String inData;

void loop() {
  while (Serial2.available() > 0)
  {
    char recieved = Serial2.read();
    inData += recieved;

    // Process message when new line character is recieved
    if (recieved == '\n')
    {
      Serial.print("Arduino Received: ");
      Serial.print(inData);

      inData = ""; // Clear recieved buffer
    }
  }
}
