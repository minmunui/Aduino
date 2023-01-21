int DIR1 = 39;
int EN1 = 38;
int PWM1 = 9;

void setup() {
  Serial.begin(9600);
  digitalWrite(38, HIGH);
}

void loop() {
  

  int reading = analogRead(A0);
  int speed = map(reading, 0, 1023, -255, 255);
  
  if (speed > 0) {
    digitalWrite(DIR1, HIGH); // 정방향 회전
    int pwm_value = 255 - speed; 
    analogWrite(PWM1, pwm_value); 
    Serial.print(String("Reading : ") + reading); 
    Serial.println(String(", Clockwise : ") + speed);
  }
  else {
    digitalWrite(DIR1, LOW); // 역방향 회전
    int pwm_value = abs(speed);
    analogWrite(PWM1, pwm_value); 
    Serial.print(String("Reading : ") + reading); 
    Serial.println(String(", Anti-clockwise : ") + pwm_value);
  } 
  delay(1000);
}
