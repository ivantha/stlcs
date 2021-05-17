// Lane 1
#define L1S1 22
#define L1S2 23
#define L1S3 24
#define L1S4 25

// Lane 2
#define L2S1 26
#define L2S2 27
#define L2S3 28
#define L2S4 29

// Lane 3
#define L3S1 30
#define L3S2 31
#define L3S3 32
#define L3S4 33

// Lane 4
#define L4S1 34
#define L4S2 35
#define L4S3 36
#define L4S4 37

// Lane 5
#define L5S1 38
#define L5S2 39
#define L5S3 40
#define L5S4 41

// Lane 6
#define L6S1 42
#define L6S2 43
#define L6S3 44
#define L6S4 45

void setup() {
  Serial1.begin(9600);

  // Lane 1
  pinMode(L1S1, INPUT);
  pinMode(L1S2, INPUT);
  pinMode(L1S3, INPUT);
  pinMode(L1S4, INPUT);

  // Lane 2
  pinMode(L2S1, INPUT);
  pinMode(L2S2, INPUT);
  pinMode(L2S3, INPUT);
  pinMode(L2S4, INPUT);

  // Lane 3
  pinMode(L3S1, INPUT);
  pinMode(L3S2, INPUT);
  pinMode(L3S3, INPUT);
  pinMode(L3S4, INPUT);

  // Lane 4
  pinMode(L4S1, INPUT);
  pinMode(L4S2, INPUT);
  pinMode(L4S3, INPUT);
  pinMode(L4S4, INPUT);

  // Lane 5
  pinMode(L5S1, INPUT);
  pinMode(L5S2, INPUT);
  pinMode(L5S3, INPUT);
  pinMode(L5S4, INPUT);

  // Lane 6
  pinMode(L6S1, INPUT);
  pinMode(L6S2, INPUT);
  pinMode(L6S3, INPUT);
  pinMode(L6S4, INPUT);
}

void loop() {
  String data = "";

  // Lane 1
  data = "1";
  data.concat(digitalRead(L1S1));
  data.concat(digitalRead(L1S2));
  data.concat(digitalRead(L1S3));
  data.concat(digitalRead(L1S4));

  data = data + "\n";
  Serial1.print(data);
  delay(100);

  // Lane 2
  data = "2";
  data.concat(digitalRead(L2S1));
  data.concat(digitalRead(L2S2));
  data.concat(digitalRead(L2S3));
  data.concat(digitalRead(L2S4));

  data = data + "\n";
  Serial1.print(data);
  delay(100);

  // Lane 3
  data = "3";
  data.concat(digitalRead(L3S1));
  data.concat(digitalRead(L3S2));
  data.concat(digitalRead(L3S3));
  data.concat(digitalRead(L3S4));

  data = data + "\n";
  Serial1.print(data);
  delay(100);

  // Lane 4
  data = "4";
  data.concat(digitalRead(L4S1));
  data.concat(digitalRead(L4S2));
  data.concat(digitalRead(L4S3));
  data.concat(digitalRead(L4S4));

  data = data + "\n";
  Serial1.print(data);
  delay(100);

  // Lane 5
  data = "5";
  data.concat(digitalRead(L5S1));
  data.concat(digitalRead(L5S2));
  data.concat(digitalRead(L5S3));
  data.concat(digitalRead(L5S4));

  data = data + "\n";
  Serial1.print(data);
  delay(100);

  // Lane 6
  data = "6";
  data.concat(digitalRead(L6S1));
  data.concat(digitalRead(L6S2));
  data.concat(digitalRead(L6S3));
  data.concat(digitalRead(L6S4));

  data = data + "\n";
  Serial1.print(data);
  delay(100);
}
