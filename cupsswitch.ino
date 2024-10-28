
void setup() {
  pinMode(11, OUTPUT); // led pin
  pinMode(2, INPUT);  // foil pin
  digitalWrite (2, HIGH);
}

void loop() {
  int cuptouch = digitalRead(2);

  if (cuptouch == LOW) { 
    digitalWrite(11, HIGH); 
  } else {
    digitalWrite(11, LOW);
  }

}
