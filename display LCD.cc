#include<LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int LM35 = A0;
int temperatura;
byte grau[8] = {
  0b00000,
  0b00100,
  0b00100,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};
void setup()
{
  Serial.begin(9600);
 lcd.begin(16, 2);
 lcd.createChar(0, grau);
}
void loop()
{
  int reading = analogRead(LM35); // Lê o valor do sensor
  float voltage = reading * (5.0 / 1023.0); // Converte a leitura em tensão
  float temperatureC = voltage * 100;
  lcd.setCursor(2,0);          
  lcd.print("Temperatura: ");
  lcd.setCursor(4,1);          
  lcd.print(temperatureC);
  lcd.print("C");
  lcd.write(byte(0));
  
  
  }