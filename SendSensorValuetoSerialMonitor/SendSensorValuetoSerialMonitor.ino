  int ledPin13 = 13;
  int ledPin10 = 10;
  int sensorVal = 0;  

  void setup() {
 // Setup Serial communication with computer
    Serial.begin(9600);
    
  // init pins as outputs
  pinMode(ledPin13,OUTPUT);
  pinMode(ledPin10,OUTPUT);
  }

  void loop() {
 // Read the value from the sensor
    sensorVal = analogRead(A0);
 
 //Send the value to the Serial Monitor
    Serial.print("Sensor Value=");
    Serial.println(sensorVal);
    if(sensorVal < 50 )
    {
        digitalWrite(ledPin13,HIGH);
    }
    else
    {
        digitalWrite(ledPin13,LOW);
    }

 // Interval between readings = 1 sec
    delay(1000);                
  }
