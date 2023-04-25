int inputForward=3;
int inputBackward=2;
int inputRight=5;
int inputLeft=4;

int rightClock=9;
int rightAntiClock=10;
int leftClock=11;
int leftAntiClock=12;

void setup() {
pinMode(rightClock,OUTPUT);
pinMode(rightAntiClock,OUTPUT);
pinMode(leftClock,OUTPUT);
pinMode(leftAntiClock,OUTPUT);

pinMode(inputForward,INPUT);
pinMode(inputBackward,INPUT);
pinMode(inputRight,INPUT);
pinMode(inputLeft,INPUT);

digitalWrite(rightClock,LOW);
digitalWrite(rightAntiClock,LOW);
digitalWrite(leftClock,LOW);
digitalWrite(leftAntiClock,LOW);
}

void loop() {

int rightInput = digitalRead(inputRight);
int leftInput = digitalRead(inputLeft);
int forwardInput = digitalRead(inputForward);
int backwardInput = digitalRead(inputBackward);



if(rightInput == HIGH){
  turnRight();
}

if(leftInput == HIGH){
  turnLeft();
}

if(rightInput == LOW && leftInput == LOW && forwardInput == HIGH){
  moveForward();
}
if(rightInput == LOW && leftInput == LOW && backwardInput == HIGH){
  moveBackward();
}


if(rightInput == LOW && leftInput == LOW && forwardInput == LOW && backwardInput == LOW){
  stopCar();
}


delay(5);
}

void turnRight(){
  digitalWrite(rightClock,LOW);
  digitalWrite(rightAntiClock,HIGH);
  digitalWrite(leftClock,HIGH);
  digitalWrite(leftAntiClock,LOW);
}

void turnLeft(){
  digitalWrite(rightClock,HIGH);
  digitalWrite(rightAntiClock,LOW);
  digitalWrite(leftClock,LOW);
  digitalWrite(leftAntiClock,HIGH);
}

void moveForward(){
  digitalWrite(rightClock,HIGH);
  digitalWrite(rightAntiClock,LOW);
  digitalWrite(leftClock,HIGH);
  digitalWrite(leftAntiClock,LOW);
}

void moveBackward(){
  digitalWrite(rightClock,LOW);
  digitalWrite(rightAntiClock,HIGH);
  digitalWrite(leftClock,LOW);
  digitalWrite(leftAntiClock,HIGH);
}

void stopCar(){
  digitalWrite(rightClock,LOW);
  digitalWrite(rightAntiClock,LOW);
  digitalWrite(leftClock,LOW);
  digitalWrite(leftAntiClock,LOW);
}
