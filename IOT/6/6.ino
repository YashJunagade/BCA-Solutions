//Demonstration of interfacing Switch and buzzer 

int pushPin = 2;
int buzzPin = 3;
int pushValue;

void setup()
{
  Serial.begin(9600);
  pinMode(pushPin, INPUT);
  pinMode(buzzPin, OUTPUT);
}

void loop()
{
  pushValue = digitalRead(pushPin);
  Serial.println(pushValue);

  if(pushValue == HIGH){
    digitalWrite(buzzPin, HIGH);
    Serial.println("Push Button Is ON");
  }else{
    digitalWrite(buzzPin, LOW);
    Serial.println("Push button is OFF");  
  }

  delay(500);
}
