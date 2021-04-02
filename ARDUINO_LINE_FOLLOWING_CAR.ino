
#include <AFMotor.h>

#define right A5
#define left A0

float sterowanie=56;

AF_DCMotor motor1(1); 
AF_DCMotor motor2(2);


void setup() {

  pinMode(left,INPUT);
  pinMode(right,INPUT);
  Serial.begin(9600);
 
}

void loop(){
  sterowanie=analogRead(A2)*(255.0/1024.0);


  if(digitalRead(left)==HIGH && digitalRead(right)==HIGH){
    //Forward
    motor1.run(FORWARD);
    motor1.setSpeed(sterowanie);
    motor2.run(FORWARD);
    motor2.setSpeed(sterowanie);

  }
  else if(digitalRead(left)==HIGH && digitalRead(right)==LOW){
    motor1.run(RELEASE);
    motor1.setSpeed(180);
    motor2.run(FORWARD);
    motor2.setSpeed(sterowanie);

  }
  else if(digitalRead(left)==LOW && digitalRead(right)==HIGH){
    //turn right
    motor1.run(FORWARD);
    motor1.setSpeed(sterowanie);
    motor2.run(RELEASE);
    motor2.setSpeed(180);

  }
  else if(digitalRead(left)==LOW && digitalRead(right)==LOW){
    //stop
    motor1.run(RELEASE);
    motor1.setSpeed(0);
    motor2.run(RELEASE);
    motor2.setSpeed(0);

   
  }
  
}
