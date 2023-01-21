int LED[] = {2, 3, 4, 5};
int pin_power[] = {0, 63, 127, 191};

void setup() {
  // put your setup code here, to run once:
  for ( int i = 0 ; i < 4 ; i ++ ) {
    pinMode(LED[i], OUTPUT);
    analogWrite(LED[i], pin_power[i]);
  }
}

void loop() {

  for(int i = 0 ; i < 4 ; i ++ ) {
    pin_power[i]++;
    pin_power[i] %= 256;
    analogWrite(LED[i], pin_power[i]);
  }
  delay(10);
}
