#include <Servo.h>
Servo myservo; 

const int button1Pin = 11; 
const int button2Pin = 4;
const int button3Pin = 2;
const int button1LEDPin = 12;   
const int button2LEDPin = 5;
const int button3LEDPin = 3;
const int pulsePin = A0;
const int forcePin = A1;
const int ledPin = 6;
int pulse;
int brightness;
int force;
int message;
int angle = 0;

bool isActive = false;


int button1State = 0;  
int button2State = 0; 
int button3State = 0; 

void setup() {
  pinMode(button1LEDPin, OUTPUT);
  pinMode(button2LEDPin, OUTPUT);
  pinMode(button3LEDPin, OUTPUT);
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
  pinMode(button3Pin, INPUT);
  pinMode (pulsePin, OUTPUT);
  pinMode (forcePin, INPUT);
  pinMode (ledPin, OUTPUT);
  myservo.attach(9);
  Serial.begin(9600);
}

void loop() {
  isActive = false;
if (Serial.available()){
  angle += 0.005;  // rotating the table
    if (angle > 360) {
      angle = 0; // reseting angle after full rotation
    }
    myservo.write(angle); //updating motor position
    delay(1500);
}

  button1State = digitalRead(button1Pin);
  button2State = digitalRead(button2Pin);
  button3State = digitalRead(button3Pin);
  // check if the pushbutton is pressed, then send info to p5
  if (button1State == HIGH) {
    digitalWrite(button1LEDPin, HIGH);
    Serial.println("Button1Kelin");
    isActive = true; // ensures that only one sensor is sending information at a time, either button, force sensor or pulse sensor
  } else {
    digitalWrite(button1LEDPin, LOW);
    isActive = false;
  }

  if (button2State == HIGH) {
    digitalWrite(button2LEDPin, HIGH);
    Serial.println("Button2Mid");
    isActive = true;
  } else {
    digitalWrite(button2LEDPin, LOW);
    isActive = false;
  }

  if (button3State == HIGH) {
    digitalWrite(button3LEDPin, HIGH);
    Serial.println("Button3Tor");
    isActive = true;
  } else {
    digitalWrite(button3LEDPin, LOW);
    isActive = false;
  }

  if (!isActive){
  force = analogRead (forcePin);
  if (force>600){ // if user pushes force sensor enough, send info to p5
    isActive = true;
    Serial.println("video");
  }
  }

  if (!isActive){
    pulse = analogRead (pulsePin);
    if (pulse >=40){ // if there is pulse reading, send info to p5
      Serial.println("pulse");
      isActive = true;
    }
  }
}
