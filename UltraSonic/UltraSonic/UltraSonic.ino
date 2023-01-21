int trig = 58;
int echo = 59;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trig, HIGH);
  int value_echo = analogRead(echo);

  Serial.print("Echo : ");
  Serial.println(value_echo);

  
  
  delay(10);
  
}
