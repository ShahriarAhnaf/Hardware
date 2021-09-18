//made my Ahnaf Shahriar
//Arduino Temperature Sensor- TMP36

#define a_refV 3.3 // using the analog reference to improve accuracy

int tempPin = 0; //A0 being used therefore pin is 0
int tempReading; //result that will be used

void setup()
{
  Serial.begin(9600); //set bit rate
  analogReference(EXTERNAL);
}

void loop()
{
	tempReading = analogRead(tempPin); //reads the measure at A0
  	
  Serial.print("\nthe raw voltage is");
  Serial.print(tempReading);
  
  float volt = tempReading * a_refV;
  volt /= (2*2*2*2*2*2*2*2*2*2); //converts voltage from the 10 bit reading of the sensor
  
  Serial.print("\nThe actual voltage is ");
  Serial.print(volt);
  
  //To print the temperature
  float tempC = (volt-0.5) * 100;
  float tempF = volt * 100;
  
Serial.print("\nthis is the temperature: ");  Serial.print(tempC); Serial.print(" C");
Serial.print("\nthis is the temperature: ");  Serial.print(tempF); Serial.print(" F");
  
  delay(5000); // every 5 second temp check
}