const int LED = 13;

void setup()
{
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop()
{
  char recebido = Serial.read();
  if (recebido == '1') {
    digitalWrite(LED, HIGH);
    Serial.write("Recebi 1\n");
  } else if (recebido == '0') {
    digitalWrite(LED, LOW);
    Serial.write("Recebi 0\n");
  }
}

  
