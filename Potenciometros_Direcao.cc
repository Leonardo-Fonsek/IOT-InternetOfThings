const int pot1Pin = A0;
const int pot2Pin = A1;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int pot1Value = analogRead(pot1Pin);
  int pot2Value = analogRead(pot2Pin);

  float pot1Power = pot1Value * (5.0 / 1023.0);
  float pot2Power = pot2Value * (5.0 / 1023.0);

  if (pot1Power < 2.00){
  	Serial.println("Para direita");
  } else {
  	Serial.println("Para esquerda");
  }
  if (pot2Power < 2.00){
  	Serial.println("Para cima");
  } else {
  	Serial.println("Para baixo");
  }
  
  delay(500);
}
