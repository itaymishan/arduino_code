/**
 * AnalogReadSerial
 * Reads an analog input pin 0 and prints the result to the serial monitor
 * Click on the serial monitor button to open it.
 */
int thisPin = 3;

void setup()
{
  pinMode(thisPin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  //int sensorValue = analogRead(0);
  digitalWrite(thisPin, HIGH);
  delay(1000);
  digitalWrite(thisPin, LOW);
  
}
