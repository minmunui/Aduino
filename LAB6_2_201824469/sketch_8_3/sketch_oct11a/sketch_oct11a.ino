int pin_LED = 13;
boolean LED_state = false;
unsigned long tiem_previous, time_current;
unsigned long count = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(pin_LED, OUTPUT);
  digitalWrite(pin_LED, LED_state);
  Serial.begin(9600);
  time_previous = millis();  
}

void loop() {
  time_current = millis();
  count ++;
  if ( time_current - time_previous >= 1000) {
    time_previous = time_current;
    LED_state = !LED_state;
    digitalWrite(pin_LED, LED_state);
    Serial.println(count);
    count = 0;
  }
  // put your main code here, to run repeatedly:

}
