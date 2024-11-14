#include "pitches.h"

const int buzzerPin = 9;
const int button1Pin = A4;
const int button2Pin = A5;

int button1State = 0;
int button2State = 0;
int currentMelody = 0;

int melody1[] = {NOTE_E4,4,  NOTE_E4,4,  NOTE_F4,4,  NOTE_G4,4,//1
  NOTE_G4,4,  NOTE_F4,4,  NOTE_E4,4,  NOTE_D4,4,
  NOTE_C4,4,  NOTE_C4,4,  NOTE_D4,4,  NOTE_E4,4,
  NOTE_E4,-4, NOTE_D4,8,  NOTE_D4,2,

  NOTE_E4,4,  NOTE_E4,4,  NOTE_F4,4,  NOTE_G4,4,//4
  NOTE_G4,4,  NOTE_F4,4,  NOTE_E4,4,  NOTE_D4,4,
  NOTE_C4,4,  NOTE_C4,4,  NOTE_D4,4,  NOTE_E4,4,
  NOTE_D4,-4,  NOTE_C4,8,  NOTE_C4,2,

  NOTE_D4,4,  NOTE_D4,4,  NOTE_E4,4,  NOTE_C4,4,//8
  NOTE_D4,4,  NOTE_E4,8,  NOTE_F4,8,  NOTE_E4,4, NOTE_C4,4,
  NOTE_D4,4,  NOTE_E4,8,  NOTE_F4,8,  NOTE_E4,4, NOTE_D4,4,
  NOTE_C4,4,  NOTE_D4,4,  NOTE_G3,2,

  NOTE_E4,4,  NOTE_E4,4,  NOTE_F4,4,  NOTE_G4,4,//12
  NOTE_G4,4,  NOTE_F4,4,  NOTE_E4,4,  NOTE_D4,4,
  NOTE_C4,4,  NOTE_C4,4,  NOTE_D4,4,  NOTE_E4,4,
  NOTE_D4,-4,  NOTE_C4,8,  NOTE_C4,2}; 

int melody2[] = {NOTE_B5,-8, NOTE_D6,16, NOTE_B5,16,
  NOTE_FS5,-8, NOTE_B5,16, NOTE_FS5,16, NOTE_D5,-8, NOTE_FS5,16, NOTE_D5,16,
  NOTE_B4,4,NOTE_F4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,
  NOTE_CS5,16, NOTE_B4,16, NOTE_CS5,16, NOTE_B4,16, NOTE_AS4,16, NOTE_CS5,16, NOTE_E5,16, NOTE_CS5,16,
  NOTE_D5,8, NOTE_B4,8, NOTE_B5,-8, NOTE_D6,16, NOTE_B5,16,
  NOTE_FS5,-8, NOTE_B5,16, NOTE_FS5,16, NOTE_D5,-8, NOTE_FS5,16, NOTE_D5,16,
  //6
  NOTE_B4,4, NOTE_D5,16, NOTE_CS5,-16, NOTE_D5,-8,
  NOTE_D5,16, NOTE_CS5,-16, NOTE_D5,-8, NOTE_B5,-8, NOTE_D5,-8,
  NOTE_D5,8, NOTE_CS5,-8, NOTE_FS5,-16, /*MI#*/ NOTE_F5,16, NOTE_FS5,-8,
  NOTE_FS5,-16, /* MI#??*/NOTE_F5,16, NOTE_FS5,-8, NOTE_D6,-8, NOTE_FS5,-8,
  NOTE_FS5,8, /*MI#*/ NOTE_F5,8, NOTE_CS5,16, NOTE_FS5,16, NOTE_A5,16, NOTE_FS5,16,
  NOTE_GS5,16, NOTE_FS5,16, NOTE_GS5,16, NOTE_FS5,16, NOTE_F5,16, NOTE_G5,16, NOTE_B5,16, NOTE_G5,16}; // Melody 2

int melody3[] = {NOTE_E5, 16, NOTE_DS5, 16, //1
  NOTE_E5, 16, NOTE_DS5, 16, NOTE_E5, 16, NOTE_B4, 16, NOTE_D5, 16, NOTE_C5, 16,
  NOTE_A4, -8, NOTE_C4, 16, NOTE_E4, 16, NOTE_A4, 16,
  NOTE_B4, -8, NOTE_E4, 16, NOTE_GS4, 16, NOTE_B4, 16,
  NOTE_C5, 8,  REST, 16, NOTE_E4, 16, NOTE_E5, 16,  NOTE_DS5, 16,
  
  NOTE_E5, 16, NOTE_DS5, 16, NOTE_E5, 16, NOTE_B4, 16, NOTE_D5, 16, NOTE_C5, 16,//6
  NOTE_A4, -8, NOTE_C4, 16, NOTE_E4, 16, NOTE_A4, 16, 
  NOTE_B4, -8, NOTE_E4, 16, NOTE_C5, 16, NOTE_B4, 16, 
  NOTE_A4 , 4, REST, 8, //9 - 1st ending

  NOTE_E5, 16, NOTE_DS5, 16, //1
  NOTE_E5, 16, NOTE_DS5, 16, NOTE_E5, 16, NOTE_B4, 16, NOTE_D5, 16, NOTE_C5, 16,
  NOTE_A4, -8, NOTE_C4, 16, NOTE_E4, 16, NOTE_A4, 16,
  NOTE_B4, -8, NOTE_E4, 16, NOTE_GS4, 16, NOTE_B4, 16,
  NOTE_C5, 8,  REST, 16, NOTE_E4, 16, NOTE_E5, 16,  NOTE_DS5, 16,
  
  NOTE_E5, 16, NOTE_DS5, 16, NOTE_E5, 16, NOTE_B4, 16, NOTE_D5, 16, NOTE_C5, 16,//6
  NOTE_A4, -8, NOTE_C4, 16, NOTE_E4, 16, NOTE_A4, 16, 
  NOTE_B4, -8, NOTE_E4, 16, NOTE_C5, 16, NOTE_B4, 16, 
  NOTE_A4, 8, REST, 16, NOTE_B4, 16, NOTE_C5, 16, NOTE_D5, 16, //10 - 2nd ending

  NOTE_E5, -8, NOTE_G4, 16, NOTE_F5, 16, NOTE_E5, 16, 
  NOTE_D5, -8, NOTE_F4, 16, NOTE_E5, 16, NOTE_D5, 16,}; // Melody 3

void setup() {
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
}

void loop() {
  button1State = digitalRead(button1Pin);
  button2State = digitalRead(button2Pin);
  Serial.println(button1State);
  Serial.println(button2State);


  if (button1State == HIGH) {
    currentMelody = (currentMelody + 1) % 3; 
    delay(200); 
  } else if (button2State == HIGH) {
    currentMelody = (currentMelody - 1 + 3) % 3; 
    delay(200); 
  }

  playMelody(currentMelody);
}

void playMelody(int melodyIndex) {
  switch (melodyIndex) {
    case 0:
      playNotes(melody1, sizeof(melody1) / sizeof(melody1[0]));
      break;
    case 1:
      playNotes(melody2, sizeof(melody2) / sizeof(melody2[0]));
      break;
    case 2:
      playNotes(melody3, sizeof(melody3) / sizeof(melody3[0]));
      break;
  }

}

void playNotes(int melody, int length) {
  for (int i = 0; i < length; i += 2) {
    int note = melody[i];
    int duration = melody[i + 1];
    tone(buzzerPin, note, duration);
    delay(duration * 1.3); 
    noTone(buzzerPin);
  }
}
