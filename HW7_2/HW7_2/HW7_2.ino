#include<pitches.h>

int reading = 0;
int mapped = 0;
int speaker_pin = 2;

int nodeDuration = 4;
int i = 0;

int MELODY[] = {0, NOTE_C4, NOTE_D4, NOTE_E4,
  NOTE_F4, NOTE_G4, NOTE_A5, NOTE_B5, NOTE_C5};
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  tone(speaker_pin, MELODY[i % 9], 100);
  i+=1;
}
