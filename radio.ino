#include "pitches.h" 

const int buzzerPin = 8;
const int buttonPin = 7;
const int lightPin = A0;

bool isPlaying = false;
int buttonState = 0;
int lastbuttonstate = 0;

int melody1[] = {NOTE_C4, NOTE_E4, NOTE_G4, NOTE_C5}; //happy melody
int duration1[] = {250, 250, 250, 250}; // its duration
int melody1Length = 4;

int melody2[] = {NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5}; //sad melody
int duration2[] = {300, 300, 300, 300}; // its duration
int melody2Length = 4;

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP); 
  Serial.begin(9600);
}

void loop() {
  int lightValue = analogRead(lightPin);
  buttonState = digitalRead(buttonPin);

// checking if button is pressed
  if (buttonState == LOW && lastbuttonstate == HIGH) { 
    isPlaying = false;
    noTone(buzzerPin); // stop playing when button is pressed
  }
  lastbuttonstate = buttonState;

  if (!isPlaying) {
    if (lightValue > 600) {
      playMelody(melody1, duration1, melody1Length); //playing happy melody when sensor value is higher than 600
    } else {
      playMelody(melody2, duration2, melody2Length); //playing sad melody when sensor value is lower than 600
    }
  }

  delay(100);
}

void playMelody(int melody[], int duration[], int length) {
  isPlaying = true; // setting playing state of the melody
  for (int i = 0; i < length; i++) {
    if (digitalRead(buttonPin) == LOW) { 
      noTone(buzzerPin);
      isPlaying = false;
      return;
    }
    tone(buzzerPin, melody[i], duration[i]);
    delay(duration[i] * 1.3); //adding delay between notes
  }
  isPlaying = false; 
}
