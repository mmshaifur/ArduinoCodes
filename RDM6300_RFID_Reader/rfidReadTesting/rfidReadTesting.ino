/*
  Tested by : Shaifur Rahman
  Date      : 01 April 2018
  Device(s) : Arduino UNO, RDM6300 Module, 125KHz RFID Card
  Version   : 1.0
*/
#include "rdm630.h"

rdm630 rfid(6, 0);  //TX-pin of RDM6300 connected to Arduino pin 6

void setup()
{
  Serial.begin(9600);
  rfid.begin();
}

void loop()
{
  byte data[6];
  byte length;
  if (rfid.available())
  {
    rfid.getData(data, length);
    unsigned long result = ((unsigned long int)data[1] << 24) + ((unsigned long int)data[2] << 16) + ((unsigned long int)data[3] << 8) + data[4];
    Serial.print("decimal CardID: ");
    Serial.println(result);
  }
}
