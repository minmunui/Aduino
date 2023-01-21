void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  
  Serial.println("Enter 2 Integers to add");

  int num1 = 0;
  int num2 = 0;

  while ( Serial.available() == 0 ) {
  //  Serial.println("waiting for n1..");
  }
  num1 = Serial.parseInt();
  
  while ( Serial.available() == 0 ) {
  //  Serial.println("waiting for n2..");
  }
  num2 = Serial.parseInt();
  
  Serial.print(num1);
  Serial.print(" + ");
  Serial.print(num2);
  Serial.print(" = ");
  Serial.println(num1 + num2);
}
