void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void readTemperature() {
  // put your main code here, to run repeatedly:
  int reading = analogRead(54);

  float voltage = reading * 5.0 / 1024.0;
  Serial.print(voltage);
  Serial.print("V : ");

  float temp_C = voltage * 100;
  Serial.print(temp_C);
  Serial.print(" C, ");

  float temp_F = (temp_C * 9.0/5.0) + 32;
  Serial.print(temp_F);
  Serial.println(" F");
}

void readIlluminance() {

  int reading = analogRead(56);
  Serial.print("ADC : ");
  Serial.print(reading);

  float voltage = reading * 5.0 / 1024;
  Serial.print(", Voltage : ");
  Serial.println(voltage);
}

void loop() {
  readTemperature();
  readIlluminance();
  delay(1000);
}
