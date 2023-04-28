// charging controller code



int tempPin = 0;
int countSeconds=0;
int minsToStopAt=80;
boolean timeUpFlag=false;
float tempSetMax = 55.0;
void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN,HIGH);
  Serial.begin(9600);
  delay(3000);
}
void loop()
{

  if(!timeUpFlag){
  int tempReading = analogRead(tempPin);
  double tempK = log(10000.0 * ((1024.0 / tempReading - 1)));
  tempK = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * tempK * tempK )) * tempK );       //  Temp Kelvin
  float tempC = tempK - 273.15;            // Convert Kelvin to Celcius
 
  
  delay(1000);

   countSeconds++;

  if(countSeconds >= minsToStopAt * 60 || tempC >= tempSetMax){
    timeUpFlag=true;
    
  }
   
Serial.print("TIME: ");
Serial.print(countSeconds);
Serial.print(" TEMP: ");
Serial.println(tempC);
  }
  else{
    digitalWrite(LED_BUILTIN,LOW);
  }
  
}
