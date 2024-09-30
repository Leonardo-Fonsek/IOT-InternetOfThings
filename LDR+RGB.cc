int LDR = 0;
int vermelho = 7;
int azul = 6;
int verde = 5;
void setup()
{
  	pinMode(A0, INPUT);
  	pinMode(vermelho, OUTPUT);
  	pinMode(verde, OUTPUT);
  	pinMode(azul, OUTPUT);
	Serial.begin(9600);
}

void loop()
{
 	int LDR = analogRead(A0);
  	
  	Serial.println(LDR);
  
  if(LDR < 100){
  	analogWrite(verde, 0);
    analogWrite(vermelho, 255);
    analogWrite(azul, 255);
    Serial.println();
    
  }
  else if(LDR >= 10 && LDR < 20){
  	analogWrite(verde, 255);
    analogWrite(vermelho, 255);
    analogWrite(azul, 0);
    Serial.println();
  }
  else if(LDR >= 20 && LDR < 20){
  	analogWrite(verde, 69);
    analogWrite(vermelho, 255);
    analogWrite(azul, 19);
    Serial.println();
  }
    else if(LDR >= 30 && LDR < 40){
  	analogWrite(verde, 215);
    analogWrite(vermelho, 255);
    analogWrite(azul, 0);
    Serial.println();
  }
    else if(LDR >= 40 && LDR < 50){
  	analogWrite(verde, 180);
    analogWrite(vermelho, 210);
    analogWrite(azul, 140);
    Serial.println();
  }
    else if(LDR >= 60 && LDR < 70){
  	analogWrite(verde, 100);
    analogWrite(vermelho, 255);
    analogWrite(azul, 100);
    Serial.println();
  }
}