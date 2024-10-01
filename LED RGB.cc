int pinoVermelho = 7;
int pinoVerde = 6;  
int pinoAzul = 5;  

void setup() {
  pinMode(pinoVermelho, OUTPUT);
  pinMode(pinoVerde, OUTPUT);
  pinMode(pinoAzul, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  setColor(255, 0, 0); 
  Serial.println("Cor: Vermelho");
  delay(500);
  
  setColor(0, 255, 0);  
  Serial.println("Cor: Azul");
  delay(500);
  
  setColor(0, 0, 255); 
  Serial.println("Cor: Verde");
  delay(500);

  setColor(255, 255, 0);  
  Serial.println("Cor: Magenta");
  delay(500);

  setColor(0, 255, 255);  
  Serial.println("Cor: Ciano");
  delay(500);
  
  setColor(255, 0, 255);  
  Serial.println("Cor: Amarelo");
  delay(1500);
}

void setColor(int vermelho, int verde, int azul) {
  analogWrite(pinoVermelho, vermelho);
  analogWrite(pinoVerde, verde);
  analogWrite(pinoAzul, azul);
}