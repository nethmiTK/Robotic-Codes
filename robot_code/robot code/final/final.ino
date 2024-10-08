#include <Stepper.h>
#include <Servo.h> 

const int stepsPerRevolution = 230;

Stepper myStepper(stepsPerRevolution, 9, 10, 11, 12);

int cultState = 0;
char data = 0;

#define front_LED  2
#define drill 3
#define drill_LED  14
Servo Servo1;

int servo_Pos = 0; 
int servo_State = 0; 

char junk;                
String inputString = "";  

#define M1_a 5
#define M1_b 6
#define M2_a 7
#define M2_b 8

void setup() {
  pinMode(M1_a, OUTPUT);
  pinMode(M1_b, OUTPUT);
  pinMode(M2_a, OUTPUT);
  pinMode(M2_b, OUTPUT);

  
  myStepper.setSpeed(20);
  
  Serial.begin(9600);

  pinMode(front_LED, OUTPUT);
  pinMode(drill, OUTPUT);

  Servo1.attach(4);
  Servo1.write(0); 

}

void loop() {
  if (Serial.available()) {
    while (Serial.available())
    {
      char inChar = (char)Serial.read(); 
      inputString = inChar;              
    }
    Serial.println(inputString);
    while (Serial.available() > 0)
    {
      junk = Serial.read() ;  
    }


    
    if (inputString == "a")  { 
      Serial.println("HIT cultvation");
      
      digitalWrite(M1_a,0);
      digitalWrite(M1_b,0);
      digitalWrite(M2_a,0);
      digitalWrite(M2_b,0);
      delay(200);
      plant();


    }

    else if (inputString == "b") { 
      digitalWrite(front_LED, 1);
    }

    else if (inputString == "c") { 
      digitalWrite(front_LED,0);
    }

    else if (inputString == "d") { 
      digitalWrite(drill_LED,1);
    }

    else if (inputString == "e") { 
      digitalWrite(drill_LED,0);
    }



    else if (inputString == "1") {      
      Serial.println("HIT Forward");
      
      digitalWrite(M1_a,0);
      digitalWrite(M1_b,1);
      digitalWrite(M2_a,0);
      digitalWrite(M2_b,1);
    }

    else if (inputString == "2") {      
      
      digitalWrite(M1_a,0);
      digitalWrite(M1_b,0);
      digitalWrite(M2_a,0);
      digitalWrite(M2_b,0);
    }

    else if (inputString == "3") { 
  
      digitalWrite(M1_a,0);
      digitalWrite(M1_b,1);
      digitalWrite(M2_a,1);
      digitalWrite(M2_b,0);
    }

    else if (inputString == "4") { 
      
      digitalWrite(M1_a,1);
      digitalWrite(M1_b,0);
      digitalWrite(M2_a,0);
      digitalWrite(M2_b,1);
    }

    inputString = ""; 
    delay(5);
  }

}




void plant() {
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
  servo_Rotate();
}


void servo_Rotate() {

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