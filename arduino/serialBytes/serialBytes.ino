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
      //byte upper = Serial.read();
      //byte lower = Serial.read();
      //Serial.print("U ");
      //Serial.print(upper);
      //Serial.print("L ");
      //Serial.println(lower);
      //valorRecebido = ((upper-48)<<8) | (lower-48); //Reassemble the number
      valorRecebido = Serial.read()-48;
      Serial.println(valorRecebido);
  }
  if (valorRecebido == 1) {
    digitalWrite(LED, HIGH);
  } else if (valorRecebido == 0) {
    digitalWrite(LED, LOW);
  }
  
  int valorServo = map(valorRecebido, 0, 100, 20, 179);
  barbie.write(valorServo);

  delay(100);  
}  
//  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023) 
//  val = map(val, 0, 1023, 0, 179);     // scale it to use it with the servo (value between 0 and 180) 
//  myservo.write(val);                  // sets the servo position according to the scaled value 
//  delay(15);                           // waits for the servo to get there 
//} 
