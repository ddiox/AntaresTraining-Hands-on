void setup() {
  Serial.begin(9600);
  pinMode(A0,INPUT_PULLUP);
}

void loop() {
  int input_A0 = analogRead(A0);
  Serial.println(input_A0);
  delay(100);
}
