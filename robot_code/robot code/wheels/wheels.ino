char junk;                
String inputString = "";  

#define M1_a 5
#define M1_b 6
#define M2_a 7
#define M2_b 8
#define front_LED 2
#define drill_LED 14

void setup(){
  pinMode(M1_a, OUTPUT);
  pinMode(M1_b, OUTPUT);
  pinMode(M2_a, OUTPUT);
  pinMode(M2_b, OUTPUT);

   Serial.begin(9600);
}

void loop(){
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
  }

  if (inputString == "a")  { 
      Serial.println("HIT cultvation");
      
      digitalWrite(M1_a,0);
      digitalWrite(M1_b,0);
      digitalWrite(M2_a,0);
      digitalWrite(M2_b,0);
      delay(200);
      //plant();
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