void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  String s_str = ">>";
  char c_str[] = ">>";

  Serial.println(s_str+c_str);
  Serial.println(c_str+s_str);
  Serial.println(s_str+3.14);
  Serial.println(s_str+" Hello");
  Serial.println(String(3.14,1)+'='+"pi");

  while(true);
}
