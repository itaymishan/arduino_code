int ledPin12= 12;
int ledPin10 = 10;

void setup()
{
  // init pin as outputs
  pinMode(ledPin12,OUTPUT);
  pinMode(ledPin10,OUTPUT);
  
}

void loop()
{
  digitalWrite(ledPin12,HIGH);
  digitalWrite(ledPin10,HIGH);
  delay(10000);
  digitalWrite(ledPin12,LOW);
  digitalWrite(ledPin10,LOW);
   delay(10000);
}
