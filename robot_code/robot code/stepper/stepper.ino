#include <Stepper.h>
#include <Servo.h>

#define drill 3
#define drill_LED 14

const int stepsPerRevolution = 230;
Stepper myStepper(stepsPerRevolution, 9, 10, 11, 12);
int cultState = 0;
char data = 0;

Servo Servo1;
int servo_Pos = 0; 
int servo_State = 0;

void setup() {
   myStepper.setSpeed(20);

}

void loop() {
  digitalWrite(drill,1);
  digitalWrite(drill_LED,1);

  
  Serial.println("clockwise");
  myStepper.step(-stepsPerRevolution);
  delay(3000);

  
  Serial.println("counterclockwise");
  myStepper.step(stepsPerRevolution);
  delay(500);

  digitalWrite(drill,0);
  digitalWrite(drill_LED,0);
  delay(1000);

  
  
}


