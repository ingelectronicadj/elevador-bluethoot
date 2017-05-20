/*
 ***********************************************************************
 *              LIBRERIAS y CONSTANTES
 ***********************************************************************
 */
#include <Stepper.h>

/****** Pines de control ******/
const int in1Pin = 12;
const int in2Pin = 11;
const int in3Pin = 10;
const int in4Pin = 9;


#define STEPS 512  // Define el numero de pasos del motor. 512 para 28BYJ-48

Stepper motor(STEPS, in1Pin, in2Pin, in3Pin, in4Pin);
/*
 ***********************************************************************
 *              SETUP CONFIGURACIÓN INICIAL
 ***********************************************************************
 */
void setup()
{
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(in3Pin, OUTPUT);
  pinMode(in4Pin, OUTPUT);

  Serial.begin(9600);
  motor.setSpeed(25);     // Fijar la velocidad en rpms
}
/*
 ***********************************************************************
 *              LOOP BUCLE PRINCIPAL
 ***********************************************************************
 */
void loop()
{
  if (Serial.available())
  {
    int pasos = Serial.parseInt();
    Serial.print("Giro en pasos de: ");
    Serial.println(pasos);
    motor.step(pasos);
    delay(500);
    //Aprovechar la logica para invertir giros ;)
    //motor.step(-200); giro en sentido anti-horario
    //motor.step(200); giro en sentido horario
  }
}
