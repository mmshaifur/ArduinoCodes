int trigPin = 7;
int echoPin = 6;
int sound = 250;
void setup()
{
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(2, OUTPUT);
}
void loop()
{
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;
  Serial.print(distance);
   Serial.println(" cm");
  if (distance > 15) {
    
   
    digitalWrite(2, HIGH);
    delay(100);
  }
  else
  {
    digitalWrite(2, LOW);
  }
  delay(100);

}

