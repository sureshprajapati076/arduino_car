#include <Servo.h>

const int trig = 12;
const int eho = 11;

long dist;
long duration;

Servo myservo; 

int potAnalogInput=A3;

int leftMotor = 5;
int leftClockWiseDirection = 6;
int leftAntiClockWiseDirection = 7;
int rightClockWiseDirection = 8;
int rightAntiClockWiseDirection = 9;
int rightMotor = 10;


long a;
long maxDistanceValue=30;
int pos = 0; 
int steps=90;

boolean flag=false;

int motorPwm = 255; //map(sensorValue,0,1023,120,255);

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN,LOW);
  myservo.attach(3);
  pinMode(leftClockWiseDirection,OUTPUT);
  pinMode(leftAntiClockWiseDirection,OUTPUT);
  pinMode(rightClockWiseDirection,OUTPUT);
  pinMode(rightAntiClockWiseDirection,OUTPUT);

  
  digitalWrite(leftClockWiseDirection,HIGH);
  digitalWrite(leftAntiClockWiseDirection,LOW);
  digitalWrite(rightClockWiseDirection,HIGH);
  digitalWrite(rightAntiClockWiseDirection,LOW);
pinMode(trig,OUTPUT);
pinMode(eho,INPUT);
Serial.begin(9600);
delay(5000);
  analogWrite(leftMotor,motorPwm);
  analogWrite(rightMotor,motorPwm);
  
}


void loop() {

  digitalWrite(leftClockWiseDirection,HIGH);
  digitalWrite(leftAntiClockWiseDirection,LOW);
  digitalWrite(rightClockWiseDirection,HIGH);
  digitalWrite(rightAntiClockWiseDirection,LOW);
  
  calculateForwardDistance();

  if(flag){
    calculateRightDistance();
    long rightAngleDistance = dist; 
    calculateLeftDistance();
    long leftAngleDistance = dist;

    myservo.write(90);
    delay(100);
    startCar();
    
   // moveBackward();
    
    if(rightAngleDistance > leftAngleDistance){
      turnRight();
    }
    else{
      turnLeft();
    }
  }

  
}

void calculateDistanceNow(){
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
   delayMicroseconds(10);
   digitalWrite(trig,LOW);

   duration = pulseIn(eho,HIGH);
   dist = duration * 0.034/2;

   Serial.println(dist);
}



void calculateForwardDistance(){
  Serial.print("FORWARD DISTANCE AT 90 DEGREE: ");
  myservo.write(90);
  int delayMillis = 280;
  delay(delayMillis);

  calculateDistanceNow();
  



  
  if (dist < maxDistanceValue) {
    stopCar();
//    delay(500);
//    startCar();
//    moveBackward();
    flag=true;
    digitalWrite(LED_BUILTIN,HIGH);
  }else {
    flag=false;
    digitalWrite(LED_BUILTIN,LOW);
  }

 
   
}

void calculateFDistance(){
//  myservo.write(90);
//  int delayMillis = 80;
//  delay(delayMillis);
//  int fDistance = sr04.Distance();
//  delay(delayMillis);
//  return fDistance;
   
}

void calculateLeftDistance(){
  Serial.print("LEFT ANGLE DISTANCE AT 180 DEGREE: ");
  myservo.write(180);
  delay(1000);
  calculateDistanceNow();
 
   
}


void calculateRightDistance(){
  Serial.print("RIGHT ANGLE DISTANCE AT 0 DEGREE: ");
  myservo.write(0);
  delay(1000);
  calculateDistanceNow(); 
}




void stopCar(){
  analogWrite(leftMotor,0);
  analogWrite(rightMotor,0);
  
}

void startCar(){
  analogWrite(leftMotor,motorPwm);
  analogWrite(rightMotor,motorPwm);
}



void moveBackward(){

  digitalWrite(leftClockWiseDirection,LOW);
  digitalWrite(leftAntiClockWiseDirection,HIGH);
  digitalWrite(rightClockWiseDirection,LOW);
  digitalWrite(rightAntiClockWiseDirection,HIGH);
  delay(900);

 
}

void turnRight(){
  moveBackward();
  digitalWrite(leftClockWiseDirection,HIGH);
  digitalWrite(leftAntiClockWiseDirection,LOW);
  digitalWrite(rightClockWiseDirection,LOW);
  digitalWrite(rightAntiClockWiseDirection,HIGH);

  delay(1200);
}

void turnLeft(){
  moveBackward();
  digitalWrite(leftClockWiseDirection,LOW);
  digitalWrite(leftAntiClockWiseDirection,HIGH);
  digitalWrite(rightClockWiseDirection,HIGH);
  digitalWrite(rightAntiClockWiseDirection,LOW);

  delay(1200);
}
