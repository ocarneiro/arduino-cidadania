//3 Servos controlados por dado recebido via Serial
//Autor: Otavio Carneiro - 25/05/2014
//Licenca: MIT - use como quiser, nao me responsabilize
#include <Servo.h> 
 
const int MIN_ENTRADA = 0;
const int MAX_ENTRADA = 100;
const int MIN_SERVO = 5;
const int MAX_SERVO = 175;

Servo servo1;  
Servo servo2;  
Servo servo3;  
int valorRecebido1 = MIN_SERVO;
int valorRecebido2 = MIN_SERVO;
int valorRecebido3 = MIN_SERVO;
 
void setup() 
{ 
  Serial.begin(9600);
  servo1.attach(9); 
  servo2.attach(10); 
  servo3.attach(11); 
} 
 
void loop() 
{
    
  servo1.write(map(valorRecebido1, MIN_ENTRADA, MAX_ENTRADA, MAX_SERVO, MIN_SERVO));
  servo2.write(map(valorRecebido2, MIN_ENTRADA, MAX_ENTRADA, MAX_SERVO, MIN_SERVO));
  servo3.write(map(valorRecebido3, MIN_ENTRADA, MAX_ENTRADA, MAX_SERVO, MIN_SERVO));
  
  delay(100);  
  
  while (Serial.available()) // Wait for characters
  {
      int centena = Serial.read()-48;
      int dezena = Serial.read()-48;
      int inteiro = Serial.read()-48;
      valorRecebido1 = centena * 100 + dezena * 10 + inteiro;
      Serial.println(valorRecebido1);
      Serial.read(); //le o separador (virgula ou outro qualquer) e nao faz nada
      centena = Serial.read()-48;
      dezena = Serial.read()-48;
      inteiro = Serial.read()-48;
      valorRecebido2 = centena * 100 + dezena * 10 + inteiro;
      Serial.println(valorRecebido2);
      Serial.read(); //le o separador (virgula ou outro qualquer) e nao faz nada
      centena = Serial.read()-48;
      dezena = Serial.read()-48;
      inteiro = Serial.read()-48;
      valorRecebido3 = centena * 100 + dezena * 10 + inteiro;
      Serial.println(valorRecebido3);
      Serial.read(); //le o separador (virgula ou outro qualquer) e nao faz nada
  }

}  

