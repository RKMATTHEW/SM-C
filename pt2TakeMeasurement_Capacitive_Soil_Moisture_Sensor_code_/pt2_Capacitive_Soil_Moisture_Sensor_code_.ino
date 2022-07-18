const int dry = 580; // value for dry sensor
const int wet = 270; // value for wet sensor



void setup()
{ 
  Serial.begin(9600);
}

void loop()
{
  int sensorVal = analogRead(A0);

  int percentageHumididy = map(sensorVal, wet, dry, 100, 0); 

  Serial.print(percentageHumididy);
  Serial.println("%");
  
   delay(100);
 }
