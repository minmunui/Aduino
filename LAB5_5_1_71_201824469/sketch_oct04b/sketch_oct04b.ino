int vResistor = A0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(vResistor, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(analogRead(vResistor));
  delay(1000);
}
