int DIR1 = 39;

int PWM1 = 9;

int mode = 0;
bool button14Flag = true;

enum motorMode { STOP, HALF, FULL };

void setup() {
  Serial.begin(9600);
  digitalWrite(DIR1, HIGH);
  digitalWrite(38, HIGH);
  analogWrite(PWM1, 255);
}

void loop() {
  
  if ( digitalRead(14) == HIGH && button14Flag == true ) {
    Serial.println("14 on");
    button14Flag = false;
    switch(mode) {
      case STOP:
        analogWrite(PWM1, 255);
        mode = HALF;
        break;
      case HALF:
        analogWrite(PWM1, 128);
        mode = FULL;
        break;
      case FULL:
        analogWrite(PWM1, 0);
        mode = STOP;
        break;
      default:
        break;
    }
    
  }
  if ( digitalRead(14) == LOW ) {
    button14Flag = true;
  }
}
