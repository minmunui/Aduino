int pin_LED = 13;
unsigned long time_previous, time_current;
unsigned long interval = 1000;
boolean LED_state = false;


void setup() {
  // put your setup code here, to run once:
  pinMode(A0, INPUT);
  pinMode(pin_LED, OUTPUT);
  digitalWrite(pin_LED, LED_state);
  Serial.begin(9600);
  time_previous = millis();
}

void loop() {
  // put your main code here, to run repeatedly:
  time_current = millis();
//  Serial.println("Hello World");
  if ( time_current - time_previous >= interval) {
    Serial.print("Current interval is ");
    Serial.print(interval);
    Serial.println(" ms. ");
    time_previous = time_current;
    LED_state = !LED_state;
    digitalWrite(pin_LED, LED_state);
  }
  int adc = analogRead(A0);
  interval = map(adc, 0, 1023, 500, 1500);
}
