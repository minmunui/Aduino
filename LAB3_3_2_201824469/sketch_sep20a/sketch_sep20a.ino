int pins[] = {2, 3, 4, 5};
int state = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for ( int i = 0 ; i < 4 ; i ++ ) {
    pinMode(pins[i], OUTPUT);
    digitalWrite(pins[1], LOW);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for ( int i = 0 ; i < 4 ; i ++ ) {
    if ( i == state ) {
      Serial.print("O ");
      digitalWrite(pins[i], HIGH);
    }
    else {
      Serial.print("X ");
      digitalWrite(pins[i], LOW);
    }
  }
  Serial.println();
  state = (state + 1) % 4;
  delay(1000);
}
