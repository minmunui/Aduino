#include<Servo.h>

Servo myServo;
int servoPin = 11;
int angle = 0;
int angle_step = 0;

unsigned long time_current, time_previous;
int interval = 100;

void setup() {
  myServo.attach(servoPin);
  Serial.begin(9600);
}

void loop() {
  time_current = millis();
  if (time_current - time_previous >= interval) {
    time_previous = time_current;
    angle += angle_step; // 현재 각도 조정
    if (angle > 180) { // 180°를 넘어가면 방향 전환
      angle = 180;
      angle_step *= -1; 
    }
    else if (angle < 0) { // 0°를 넘어가면 방향 전환 
      angle = 0;
      angle_step *= -1;
    }
    myServo.write(angle); 
  }
  int reading = analogRead(A0); // 가변저항 값 읽기 
  int new_interval = map(reading, 0, 1023, 5, 20); 
  if (new_interval != interval) {
    interval = new_interval; // 이동 시간 간격 조정
    Serial.print("Currrent Interval : "); 
    Serial.println(interval);
  }
}
