#include <Arduino.h>
/*
Mira el tutorial en 
Programador Novato: https://www.programadornovato.com/esp32-con-servo-girar-servomotor/
Youtube: https://www.youtube.com/watch?v=8f_nba1umlA&list=PLCTD_CpMeEKTvjzabAvLGHakg-ql6t0q6&index=8

En este tutorial trabajaremos en el Esp32 con 
servo y haremos que un servomotor gire 180 grados 
y después regrese a 0 grados.
*/
/* ewdit edit*/

#define DMAX 25
#define DISTANCIA  00
#define pinLedOn   16
#define pinLedOff  17
#define pinEco     12
#define pinGatillo 13


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
  //Si la distancia es menor a 20 encendemos el led
  if (DISTANCIA < DMAX) {
    digitalWrite(pinLedOn, HIGH);
    digitalWrite(pinLedOff, LOW);
  } 
  //Si la distancia es mayor a 20 apagamos el led
  else {
    digitalWrite(pinLedOn, LOW);
    digitalWrite(pinLedOff, HIGH);
  }
  delay(10);
}
