//Servo controlado por dado recebido via Serial
//Autor: Otavio Carneiro - 25/05/2014
//Licenca: MIT - use como quiser, nao me responsabilize
#include <Servo.h> 
 
Servo barbie;  
const int LED = 13;
int valorAExibir = 0; // valor que o servo deve representar

unsigned int integerValue=0;  // Max value is 65535
char incomingByte;

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  barbie.attach(11);   
}

void loop() {
  if (Serial.available() > 0) {   // something came across serial
    integerValue = 0;         // throw away previous integerValue
    while(1) {            // force into a loop until 'n' is received
      incomingByte = Serial.read();
      if (incomingByte == '\n') break;   // exit the while(1), we're done receiving
      if (incomingByte == -1) continue;  // if no characters are in the buffer read() returns -1
      integerValue *= 10;  // shift left 1 decimal place
      // convert ASCII to integer, add, and shift left 1 decimal place
      integerValue = ((incomingByte - 48) + integerValue);
    }
    Serial.println(integerValue);   // Do something with the value
  }
}

void other_loop() 
{
  char buffer[] = {' ', ' ', ' ', ' ', ' ', ' ', ' '}; //pode receber ateh 7 caracteres
  while (!Serial.available()); // Wait for characters
  Serial.readBytesUntil('x', buffer, 7);
  int valorRecebido = atoi(buffer);
  if (valorRecebido == 1) {
    digitalWrite(LED, HIGH);
  } else if (valorRecebido == 0) {
    digitalWrite(LED, LOW);
  }
  Serial.println(valorRecebido);
  
  int valorServo = map(valorRecebido, 0, 100, 20, 179);
  barbie.write(valorServo);
}  

