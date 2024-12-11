#include <Servo.h>
Servo myservo; 

const int button1Pin = 11;  // the number of the pushbutton pin
const int button2Pin = 4;
const int button3Pin = 2;
const int button1LEDPin = 12;    // the number of the LED pin
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


int button1State = 0;  // variable for reading the pushbutton status
int button2State = 0; 
int button3State = 0; 

void setup() {
  // initialize the LED pin as an output:
  pinMode(button1LEDPin, OUTPUT);
  pinMode(button2LEDPin, OUTPUT);
  pinMode(button3LEDPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
  pinMode(button3Pin, INPUT);
  pinMode (pulsePin, OUTPUT);
  pinMode (forcePin, INPUT);
  pinMode (ledPin, OUTPUT);
  myservo.attach(9);
  Serial.begin(9600);
  // myservo.write (angle);
}

void loop() {
  // read the state of the pushbutton value:

  isActive = false;
// if (Serial.available()){
//   angle += 0.005; // Increment the angle
//     if (angle > 360) {
//       angle = 0; // Reset angle after a full rotation
//     }
//     myservo.write(angle); // Update the servo position
//     delay(1500);
// }

  button1State = digitalRead(button1Pin);
  button2State = digitalRead(button2Pin);
  button3State = digitalRead(button3Pin);
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (button1State == HIGH) {
    // turn LED on:
    digitalWrite(button1LEDPin, HIGH);
    Serial.println("Button1Kelin");
    isActive = true;
    // delay(100);
  } else {
    // turn LED off:
    digitalWrite(button1LEDPin, LOW);
    isActive = false;
  }

  if (button2State == HIGH) {
    // turn LED on:
    digitalWrite(button2LEDPin, HIGH);
    Serial.println("Button2Mid");
    isActive = true;
    // delay(100);
  } else {
    // turn LED off:
    digitalWrite(button2LEDPin, LOW);
    isActive = false;
  }

  if (button3State == HIGH) {
    // turn LED on:
    digitalWrite(button3LEDPin, HIGH);
    Serial.println("Button3Tor");
    isActive = true;
    // delay(100);
  } else {
    // turn LED off:
    digitalWrite(button3LEDPin, LOW);
    isActive = false;
  }

  if (!isActive){
  force = analogRead (forcePin);
  // brightness = map(force, 0, 1023, 0, 255);
  if (force>600){
    isActive = true;
    Serial.println("video");
  }
  }

  if (!isActive){
    pulse = analogRead (pulsePin);
    if (pulse >=40){
      Serial.println("pulse");
      isActive = true;
    }
  }

  // if (!buttonActive && !pulseActive && !forceActive){
  // while (Serial.available()){
  //   message = Serial.parseInt(); 
  //   if (Serial.read() == '\n'){
  //   if (message == "1"){
  //     // myservo.write(180); // Move servo to 90 degrees
  //     delay(100);       // Allow time for the servo to move
  //     // myservo.write(0);  // Reset servo to 0 degrees
  //     // delay(100); 
  //   }

  //   if (message == "2"){
  //     // myservo.write (360);
  //     delay (100);
  //   }
  //   }
  //   }
  //   }
}
