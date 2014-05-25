//Servo controlado por dado recebido via Serial
//Autor: Otavio Carneiro - 25/05/2014
//Licenca: MIT - use como quiser, nao me responsabilize
#include <Servo.h> 
 
Servo barbie;  
const int LED = 13;
int valorRecebido = 0; //valor vindo de fora
int valorAExibir = 0;  //valor que o servo deve representar
 
void setup() 
{ 
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  barbie.attach(11); 
} 
 
void loop() 
{
  while (Serial.available()) // Wait for characters
  {
      int centena = Serial.read()-48;
      int dezena = Serial.read()-48;
      int inteiro = Serial.read()-48;
      valorRecebido = centena * 100 + dezena * 10 + inteiro;
      Serial.println(valorRecebido);
  }
  if (valorRecebido == 100) {
    digitalWrite(LED, HIGH);
  } else if (valorRecebido == 0) {
    digitalWrite(LED, LOW);
  }
  
  int valorServo = map(valorRecebido, 0, 100, 20, 179);
  barbie.write(valorServo);

  delay(100);  
}  

