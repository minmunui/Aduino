byte patterns[] = {
  0xFC, 0x60, 0xDA, 0xF2, 0x66, 0xB6, 0xBE, 0xE4, 0xFE, 0xE6
};
int digit_select_pin[] = {66, 67, 68, 69}; // 자릿수 선택 핀
int segment_pin[] = {58, 59, 60, 61, 62, 63, 64, 65};
int count = 0;
int SEGMENT_DELAY = 5; // 숫자 표시 사이의 시간 간격
unsigned long time_previous, time_current;

void setup() {
  for (int i = 1; i < 4; i++) { // 자릿수 선택 핀을 출력으로 설정
    pinMode(digit_select_pin[i], OUTPUT);
  }
  for (int i = 0; i < 8; i++) { // 세그먼트 제어 핀을 출력으로 설정
    pinMode(segment_pin[i], OUTPUT);
  }
  time_previous = millis();
}

// 해당 자리에 숫자 하나를 표시하는 함수
void show_digit(int pos, int number) { // (위치, 출력할 숫자)
  for (int i = 0; i < 4; i++) {
    if (i + 1 == pos) // 해당 자릿수의 선택 핀만 LOW로 설정
      digitalWrite(digit_select_pin[i], LOW);
    else // 나머지 자리는 HIGH로 설정
      digitalWrite(digit_select_pin[i], HIGH);
  }
  for (int i = 0; i < 8; i++) {
    boolean on_off = bitRead(patterns[number], 7 - i);
    digitalWrite(segment_pin[i], on_off);
  }
}

void show_3_digit(int number) {
  number = number % 1000; // 3자리로 제한
  int hundreads = number / 100; // 백 자리
  number = number % 100;
  int tens = number / 10; // 십 자리
  int ones = number % 10; // 일 자리
  delay(SEGMENT_DELAY);
  show_digit(2, hundreads);
  delay(SEGMENT_DELAY);
  show_digit(3, tens);
  delay(SEGMENT_DELAY);
  show_digit(4, ones);
  delay(SEGMENT_DELAY);
}

bool up_flag = true;
unsigned long button_time_prev;

bool isButtonPushed() {
  if ( digitalRead(14) != LOW && time_current - button_time_prev >= 500 ) {
    return true;
  }
  return false;
}

int count_down() {
  if (count != 0) {
    count--;
  }
  else {
    count = 999;
  }
}

int count_up() {
  if ( count != 999 ) {
    count++; 
  }
  else {
    count = 0;
  }
}
void loop() {
  time_current = millis();
  if (time_current - time_previous >= 1000) {
    time_previous = time_current;
    if ( up_flag ) {
      count_up();
    }
    else { 
      count_down();
    }
  }
  show_3_digit(count);
  if ( isButtonPushed() ) {
      up_flag = !up_flag; 
      button_time_prev = time_current;
  }
}
