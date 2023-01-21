int pins[] = {2, 3, 4, 5};
int pattern = 1;
bool isRight = false;



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
  int temp = pattern;
  for ( int i = 0 ; i < 4 ; i ++ ) {
    if ( temp % 2 == 1 ) {
      Serial.print("O ");
      digitalWrite(pins[i], HIGH);
    }
    else {
      Serial.print("X ");
      digitalWrite(pins[i], LOW);
    }
    temp = temp >> 1;
  }
  if ( pattern == 15 ) {
    isRight = true;
  }
  if ( pattern == 1 ) {
    isRight = false;
  }
  pattern = shift(pattern);
  Serial.println();
  delay(1000);
}

int shift(int pat) {
  if ( isRight ) {
    pat = pat >> 1;
  }
  else {
    pat = pat << 1 | 0x01;
  }
  return pat;
}
