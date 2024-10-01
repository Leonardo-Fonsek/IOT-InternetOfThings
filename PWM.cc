void setup()
{
  Serial.begin(9600);
}

void loop()
{
  for(int digitalInput = 0; digitalInput<255; digitalInput++){
  	Serial.println("Digital input:");
    Serial.println(digitalInput);
    analogWrite(11, digitalInput);
    analogWrite(10, digitalInput);
    analogWrite(3, digitalInput);
  }
}