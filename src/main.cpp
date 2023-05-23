#include <Arduino.h>
/*

*/

#define DMAX 25
#define DISTANCIA  00
#define pinLedOn   16
#define pinLedOff  17
#define pinEco     26
#define pinGatillo 27

#define R1  33
#define R2  32
#define R3  34
#define R4  35


long readUltrasonicDistance(int triggerPin, int echoPin)
{
  //Iniciamos el pin del emisor de reuido en salida
  pinMode(triggerPin, OUTPUT);
  //Apagamos el emisor de sonido
  digitalWrite(triggerPin, LOW);
  //Retrasamos la emision de sonido por 2 milesismas de segundo
  delayMicroseconds(2);
  // Comenzamos a emitir sonido
  digitalWrite(triggerPin, HIGH);
  //Retrasamos la emision de sonido por 2 milesismas de segundo
  delayMicroseconds(10);
  //Apagamos el emisor de sonido
  digitalWrite(triggerPin, LOW);
  //Comenzamos a escuchar el sonido
  pinMode(echoPin, INPUT);
  // Calculamos el tiempo que tardo en regresar el sonido
  return pulseIn(echoPin, HIGH);
}

void relay(int d)
{
  if( d < DMAX)
  {
    digitalWrite(R1, HIGH);
    
    digitalWrite(pinLedOn, HIGH);
    digitalWrite(pinLedOff, LOW); 
  } 
  else
  {
    digitalWrite(R1, LOW);

    digitalWrite(pinLedOn, LOW);
    digitalWrite(pinLedOff, HIGH);
  }
}

void setup() {
  Serial.begin(115200);
  //Configuramos el pin del led como salida
  pinMode(pinLedOn, OUTPUT);
  pinMode(pinLedOff, OUTPUT);
  digitalWrite(pinLedOn, LOW);
  digitalWrite(pinLedOff, LOW);
}

void loop() {
  //Calculamos la distancia en cm
  DISTANCIA = 0.01723 * readUltrasonicDistance(pinGatillo, pinEco);
  //Mostramos la disstancia
  Serial.println(DISTANCIA);

  relay(DISTANCIA);
  delay(10);
}
