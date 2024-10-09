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

  if (pot1Power < 1.25){
  	Serial.println("Para direita");
  } else if (pot1Power < 2.50){
  	Serial.println("Para esquerda");
  } else if (pot1Power < 3.75){
  	Serial.println("Para cima");
  } else if (pot1Power < 4.00){
  	Serial.print("Para baixo");
  }
  delay(500);
}
