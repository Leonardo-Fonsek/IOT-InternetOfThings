Potenciometros_1

const int PotenciometroX = A0;
const int PotenciometroY = A1;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int valorX = analogRead(PotenciometroX);
  int valorY = analogRead(PotenciometroY);
  
  Serial.print("Eixo X: ");
  Serial.print(valorX);
  Serial.print("Eixo Y: ");
  Serial.println(valorY);
  
  delay(500);
}