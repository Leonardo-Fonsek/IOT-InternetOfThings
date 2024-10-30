const int pinButton = 2; // Pino do botão
// Definindo limites para as direções
const int centerThreshold = 100; // Limite para considerar que está no centro
const int moveThreshold = 100; // Limite para considerar movimento
void setup() {
  Serial.begin(9600); // Inicia a comunicação serial (opcional)
  pinMode(pinButton, INPUT_PULLUP); // Configura o pino do botão como entrada com pull-up interno
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
}
void loop() {
  // Lê os valores dos eixos X e Y
  int valueX = analogRead(A0); // Pino X do joystick
  int valueY = analogRead(A1); // Pino Y do joystick
  // Lê o estado do botão
  int buttonState = digitalRead(pinButton);
  // Determina a direção com base nos valores dos eixos
  String direction = "Centro"; // Direção inicial
  // Verifica a direção do movimento no eixo X
  
  
  if (buttonState == LOW){
     digitalWrite(11, HIGH);
     digitalWrite(10, HIGH);
  } else{
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
  }
  
  if (valueX < 512 - moveThreshold) {
    direction = "Esquerda";
     digitalWrite(11, HIGH);
  } else if (valueX > 512 + moveThreshold) {
    direction = "Direita";
     digitalWrite(11, HIGH);
  }
  // Verifica a direção do movimento no eixo Y
  if (valueY < 512 - moveThreshold) {
    direction = "Cima";
     digitalWrite(10, HIGH);
  } else if (valueY > 512 + moveThreshold) {
    direction = "Baixo";
     digitalWrite(10, HIGH);
  }
}