 void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  String str[5];

  int str_num = 0;
  int len = 0;
  int state = 1;
  char buffer[128];
  
  while(str_num < 5){
    if ( state == 1 ) {
      Serial.print("Enter the " + String(str_num+1) + "th Word -->");
      state = 2;
    }
    while ( Serial.available()==0 ) {
      int len = Serial.readBytesUntil('\n', buffer, 127);
      if ( len > 0) {
        buffer[len] = '\0';
        String in_str = buffer;
        Serial.println(in_str);
        str[str_num] = String(in_str);
        state = 1;
        break;
      }
    }
    str_num++;
  }

  for ( int i = 0 ; i < 4 ; i ++ ) {
    for ( int j = i + 1 ; j < 5 ; j ++ ) {
      int compare = str[i].compareTo(str[j]);
      if ( compare > 0 ) {
        String temp = str[i];
        str[i] = str[j];
        str[j] = temp;
      }
    }
  }

  for ( int i = 0 ; i < 5 ; i ++ ) {
    Serial.println(str[i]);
  }
  str_num = 0;
}
