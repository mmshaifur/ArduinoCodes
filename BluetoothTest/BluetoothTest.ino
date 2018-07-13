#include <SoftwareSerial.h>
SoftwareSerial bluetooth(7, 8); // Connection pins for bluetooth RX & TX.
//I used software serial so that you can upload the code even with the bluetooth module connected.
int recieved;
void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  bluetooth.begin(9600);
  digitalWrite(13, 0);
}
void loop()
{
  while (bluetooth.available())
  {
    recieved = bluetooth.read();
    Serial.println(recieved);
    delay(50);
  }
}
