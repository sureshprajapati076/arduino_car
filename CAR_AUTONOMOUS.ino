
int inputForward=2;
int inputBackward=3;
int inputRight=4;
int inputLeft=5;

int rightClock=10;
int rightAntiClock=9;
int leftClock=12;
int leftAntiClock=11;

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

if(rightInput == HIGH && backwardInput == HIGH || leftInput == HIGH){
  turnLeft();
}
else if(leftInput == HIGH && backwardInput == HIGH || rightInput == HIGH){
  turnRight();
}
else if(forwardInput == HIGH){
  moveForward();
}
else if(backwardInput == HIGH){
  moveBackward();
}
else{
  stopCar();
}

delay(5);
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

void turnLeft(){
  digitalWrite(rightClock,HIGH);
  digitalWrite(rightAntiClock,LOW);
  digitalWrite(leftClock,LOW);
  digitalWrite(leftAntiClock,HIGH);
}

void turnRight(){
  digitalWrite(rightClock,LOW);
  digitalWrite(rightAntiClock,HIGH);
  digitalWrite(leftClock,HIGH);
  digitalWrite(leftAntiClock,LOW);
}

void stopCar(){
  digitalWrite(rightClock,LOW);
  digitalWrite(rightAntiClock,LOW);
  digitalWrite(leftClock,LOW);
  digitalWrite(leftAntiClock,LOW);
}
