#include <Wire.h>
#include <LiquidCrystal_I2C.h> // Biblioteca para LCD I2C
// Definindo os pinos do joystick
const int pinButton = 2; // Pino do botão
// Definindo limites para as direções
const int centerThreshold = 100; // Limite para considerar que está no centro
const int moveThreshold = 100; // Limite para considerar movimento
// Inicializa o display LCD I2C no endereço 0x27 (ou 0x3F, dependendo do seu LCD)
LiquidCrystal_I2C lcd(0x3F, 16, 2); // 16 colunas e 2 linhas
void setup() {
  Serial.begin(9600); // Inicia a comunicação serial (opcional)
  pinMode(pinButton, INPUT_PULLUP); // Configura o pino do botão como entrada com pull-up interno
  lcd.init(); // Inicializa o LCD
  lcd.backlight(); // Ativa a luz de fundo do LCD
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
  if (valueX < 512 - moveThreshold) {
    direction = "Esquerda";
  } else if (valueX > 512 + moveThreshold) {
    direction = "Direita";
  }
  // Verifica a direção do movimento no eixo Y
  if (valueY < 512 - moveThreshold) {
    direction = "Cima";
  } else if (valueY > 512 + moveThreshold) {
    direction = "Baixo";
  }
  // Limpa o display antes de imprimir novas informações
  lcd.clear();
  // Exibe as direções e o estado do botão no display LCD
  lcd.setCursor(0, 0); // Define a posição do cursor na linha 0
  lcd.print("Direcao: ");
  lcd.print(direction); // Mostra a direção no display
  lcd.setCursor(0, 1); // Define a posição do cursor na linha 1
  lcd.print("Botao: ");
  lcd.print(buttonState == LOW ? "Pressionado" : "Solto"); // Mostra o estado do botão
  delay(1000); // Atraso para não sobrecarregar o display
}