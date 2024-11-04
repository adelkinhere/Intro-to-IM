int switchPin = 12;
int ledPin = 6;
int ledPin2 = 8;
int ledPin3 = 2;
int ledPin4 = 4;
int switchState = 0;
int brightness = 0;
int brightness1 = 0;
int brightness2 = 0;

void setup() {
  pinMode (switchPin, INPUT);
  pinMode (ledPin, OUTPUT);
  pinMode (ledPin2, OUTPUT);
  Serial.begin (9600);
}

void loop() {
  switchState = digitalRead (switchPin);
  if (switchState == HIGH){
    digitalWrite (ledPin, HIGH);
  }
  else {
    digitalWrite (ledPin, LOW);
  }

  int sensorValue = analogRead (A0);
  Serial.println (sensorValue);
  sensorValue = constrain (sensorValue, 10,200);
  brightness = map (sensorValue, 15, 140, 0, 255);
  analogWrite (ledPin2, brightness);
  delay (10);

  int sensorValue2 = analogRead (A1);
  sensorValue2 = constrain (sensorValue2, 10,200);
  brightness1 = map (sensorValue2, 15, 140, 0, 255);
  analogWrite (ledPin3, brightness1);
  delay (10);

  int sensorValue3 = analogRead (A2);
  sensorValue3 = constrain (sensorValue3, 10,200);
  brightness2 = map (sensorValue3, 15, 140, 0, 255);
  analogWrite (ledPin4, brightness2);
  delay (10);


}
