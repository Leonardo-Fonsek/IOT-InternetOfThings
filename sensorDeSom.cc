#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>
#include <Fonts/FreeMono9pt7b.h>
#include <Fonts/FreeSansBoldOblique9pt7b.h>
#include <Fonts/FreeMonoOblique9pt7b.h>
const int sensorPin = 2; // Pin onde está conectado o OUT
int sensorState = 0; // Variável para guardar o estado do sensor
#define OLED_RESET -1
Adafruit_SH1106 display(OLED_RESET);
void setup() {
  pinMode(sensorPin, INPUT); // Configura o pin como entrada
  Serial.begin(9600); // Inicializa a comunicação serial
  display.begin(SH1106_SWITCHCAPVCC, 0x3C); // Inicialização do display
}
void loop() {
  sensorState = digitalRead(sensorPin); // Lê o estado do sensor
  display.clearDisplay(); // Limpa a tela
  display.setFont(&FreeMonoOblique9pt7b); // Define a fonte
  display.setTextColor(WHITE); // Define a cor do texto
  display.setTextSize(1); // Define o tamanho do texto
  display.setCursor(2, 15); // Define a posição do cursor
  if (sensorState == LOW) {
    display.print("Som detectado!"); // Texto a ser escrito
    Serial.println("Som detectado!");
  } else {
    display.print("Nenhum som detectado."); // Texto a ser escrito
    Serial.println("Nenhum som detectado.");
  }
  display.display(); // Mostrar informações na tela
  delay(1000); // Espera meio segundo antes da próxima leitura
}