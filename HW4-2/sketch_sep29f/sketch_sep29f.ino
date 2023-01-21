int pins_LED[] = {2, 3, 4, 5};
int pins_button[] = {14};
int state = 0;
bool direct = true;

void setup() {
  Serial.begin(9600);
  for ( int i = 0 ; i < 4 ; i ++ ) {
    pinMode(pins_LED[i], OUTPUT);
  }
  pinMode(pins_button[0], INPUT);
}

void loop() {
//  Serial.print(state);
//  Serial.print("\t");
//  Serial.print(direct);
//  Serial.print(digitalRead(pins_button[0]));
//  Serial.print("--");
  for ( int i = 0 ; i < 4 ; i ++ ) {
    if ( state == i ) {
      Serial.print("0 ");
      digitalWrite(pins_LED[i], HIGH);
    }
    else {
      Serial.print("X ");
      digitalWrite(pins_LED[i], LOW);
    }

  }

  if ( digitalRead(pins_button[0]) ) {
    direct = !direct;
  }

  if ( direct ) {
    state = (state + 1) % 4;
  }
  else {
    if ( state == 0 ) {
      state = 3;
    }
    else {
      state = state - 1;
    }
  }
  Serial.println();
  delay(1000);
}
