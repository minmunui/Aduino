int light = 0;
int pins_LED[] = {2, 3, 4, 5};
int adc = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  adc = readIlluminance();
  Serial.print("before mapping adc : " + String(adc) + ", ");
  adc = map(adc, 0, 600, 0, 4);
  Serial.println("after mapping adc : " + String(adc) + ", ");
  for ( int i = 0 ; i < 4 ; i ++ ) {
    if ( adc > i ) {
      analogWrite(pins_LED[i], 255);
    }
    else {
      digitalWrite(pins_LED[i], LOW);
    }
  }
}

int readIlluminance() {

  int reading = analogRead(56);
//  Serial.print("ADC : ");
//  Serial.print(reading);

  float voltage = reading * 5.0 / 1024;
//  Serial.print(", Voltage : ");
//  Serial.println(voltage);
  return reading;
}
