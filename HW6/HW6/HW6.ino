int vResistor = A0;
int adc;
int pin_LED1 = 2, pin_LED2 = 3;
unsigned long time_previous1, time_current1, interval1;
unsigned long time_previous2, time_current2, interval2;

boolean LED_state1 = false;
boolean LED_state2 = false;

void setup() {
  pinMode(vResistor, INPUT);
  pinMode(pin_LED1, OUTPUT);
  digitalWrite(pin_LED1, LED_state1);
  pinMode(pin_LED2, OUTPUT);
  digitalWrite(pin_LED2, LED_state2);
  time_previous1 = millis();
  time_previous2 = millis();
  Serial.begin(9600);
}

void loop() {
  time_current1 = millis();
  time_current2 = millis();
  if ( time_current1 - time_previous1 >= interval1 ){
    Serial.print("Current interval1 is ");
    Serial.print(interval1);
    Serial.println(" ms.");
    
    time_previous1 = time_current1;
    LED_state1 = !LED_state1;
    digitalWrite(pin_LED1, LED_state1);
  }

  if ( time_current2 - time_previous2 >= interval2 ){
    Serial.print("Current interval2 is ");
    Serial.print(interval2);
    Serial.println(" ms.");
    
    time_previous2 = time_current2;
    LED_state2 = !LED_state2;
    digitalWrite(pin_LED2, LED_state2);
  }
  adc = analogRead(vResistor);
  interval2 = map(adc, 0, 1023, 500, 1500);
  interval1 = 2000 - interval2;
}
