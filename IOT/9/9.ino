//Demonstration of LDR Base light Controller system

int potPin = A1;
int potValue;

void setup()
{
  Serial.begin(9600);
  pinMode(potPin, INPUT);
}

void loop()
{
  potValue = analogRead(potPin);
  Serial.print("Pot Value : ");
  Serial.println(potValue);
  delay(2000);
}
