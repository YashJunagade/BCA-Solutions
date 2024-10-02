#include<DHT.h>
#define DHTTYPE DHT11

int dhtSensorPin = 1;
DHT dht(dhtSensorPin, DHTTYPE);
float t, h;

void setup()
{
  Serial.begin(9600);
  dht.begin();
  pinMode(dhtSensorPin, INPUT);
  delay(2000);
}

void loop()
{
  t = dht.readTemperature();
  Serial.print("Temperature = ");
  Serial.println(t);

  h = dht.readHumidity();
  Serial.print("Humidity = ");
  Serial.println(h);

  delay(2000);
}
