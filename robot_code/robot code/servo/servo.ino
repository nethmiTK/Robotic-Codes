#include <Servo.h>
#define drill  3

Servo Servo1;
int servo_Pos = 0; 
int servo_State = 0;

void setup() {
  Serial.begin(9600);
  pinMode(drill,1);
  Servo1.attach(4);
  Servo1.write(0);

}

void loop() 
{
  if (servo_State == 4) {
        Servo1.write(165);
        delay(2000);
        Servo1.write(0);
        Serial.println(servo_State);
        servo_State = 0;
        Serial.println("0 set");
     }

     else if (servo_State == 3) {
        Servo1.write(125);
        delay(1000);
        servo_State++;
        Serial.println(servo_State);
        Serial.println("4 set");
      }

      else if (servo_State == 2) {
        Servo1.write(90);
        delay(1000);
        servo_State++;
        Serial.println(servo_State);
        Serial.println("3 set");
      }
     
      else if (servo_State == 1) {
        servo_State++;
        Servo1.write(45);
        delay(1000);
        Serial.println(servo_State);
        Serial.println("2 set");
      }

      else if (servo_State == 0) {
        Servo1.write(15);
        delay(1000);
        servo_State++;
        Serial.println(servo_State);
        Serial.println("1 set");

      }
  
}


