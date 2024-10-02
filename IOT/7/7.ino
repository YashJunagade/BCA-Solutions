int pushBtn = 7;
int led = 8;
int pushValue;

void setup()
{
  Serial.print(9600);
  pinMode(pushBtn, INPUT);
  pinMode(led, OUTPUT);
}

void loop()
{
  pushValue = digitalRead(pushBtn);
  Serial.println(pushValue);
  
  if(pushValue == HIGH){
    digitalWrite(led, HIGH);
    Serial.print("Push Button is ON");
  }else{
    digitalWrite(led, LOW);
    Serial.print("Push Button is OFF");
  }

  delay(2000);
}
