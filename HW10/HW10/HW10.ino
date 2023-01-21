void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
}

void loop() {
  while(Serial1.available()) {
    int data = Serial1.read();

    float temp = data * 5.0 * 100.0 / 1024.0;
   
    Serial.println(String("Current temperature : ") + temp);
    }
  }
