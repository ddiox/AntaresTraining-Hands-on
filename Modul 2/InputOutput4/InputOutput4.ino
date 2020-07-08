void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT_PULLUP);
  pinMode(D4, OUTPUT);
  Serial.println("HALO DUNIA !!!");
}

void loop() {
  int input_A0 = analogRead(A0);
  boolean input_state;

  if(input_A0 > 512) input_state = HIGH;
  else input_state = LOW;
  digitalWrite(D4, input_state);
  
  if(input_state ==LOW) Serial.println("LAMPUT NYALA");
  
  delay(100);
}
