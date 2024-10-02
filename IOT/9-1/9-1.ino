int ldrPin = A0;
int relayPin = 7;
int threshold = 300;

void setup()
{
  Serial.begin(9600);
  pinMode(relayPin, OUTPUT);
}

void loop()
{
  int ldrValue = analogRead(ldrPin);

  if(ldrValue < threshold){
    digitalWrite(relayPin, HIGH);
    Serial.println("Light ON");
  }else{
    digitalWrite(relayPin, LOW);
    Serial.println("Light OFF");
  }

  delay(1000);
}
