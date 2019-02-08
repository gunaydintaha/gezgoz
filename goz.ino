#include <Servo.h> 
#include <NewPing.h> 

#define TRIGGER_PIN  7
#define ECHO_PIN     6
#define MAX_DISTANCE 150
 
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
 

int servoPin = 4; 
int enkucuk = 300;
int enkucukaci;
Servo Servo1; 

void setup() { 
   Servo1.attach(servoPin); 
   Serial.begin(115200);
}


void loop(){ 
  
for(int i = 0; i < 180 ; i+=15){
  
   Servo1.write(i); 
   delay(100); 
   Serial.println(sonar.ping_cm());
   
   if(enkucuk > sonar.ping_cm() && sonar.ping_cm() > 0){
    enkucuk = sonar.ping_cm();
    enkucukaci = i ;
   }
  }

  Servo1.write(enkucukaci);

  delay(2000);
}


