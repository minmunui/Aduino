#include <Servo.h>

Servo myServo;
int servoPin = 11;
int servoAngle = 0;
bool button14Flag = true;
bool button15Flag = true;

void setup() {
  myServo.attach(servoPin);
  myServo.write(servoAngle);
  Serial.begin(9600);
}

void loop() {
  if ( digitalRead(14) == HIGH && button14Flag == true ) {
    Serial.println("14 on");
    button14Flag = false;
    if (isUpperable()) {
      servoAngle += 10;
      myServo.write(servoAngle);
    }
  }
  if ( digitalRead(14) == LOW ) {
    button14Flag = true;
  }
  if ( digitalRead(15) == HIGH && button15Flag == true ) {
    Serial.println("15 on");
    button15Flag = false;
    if (isDownable()) {
      servoAngle -= 10;
      myServo.write(servoAngle);
    }
  }
  if ( digitalRead(15) == LOW ) {
    button15Flag = true;
  }
}

bool isUpperable() {
  return servoAngle >= 0 && servoAngle <= 170;
}

bool isDownable() {
  return servoAngle >= 10 && servoAngle <= 180;
}
