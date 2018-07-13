
#include <SoftwareSerial.h>
SoftwareSerial bluetooth(6, 7); 
#define m1_c1 11 
#define m1_c2 12
#define m2_c1 10
#define m2_c2 9

int command; //Int to store app command state.
int Speedsec;
int buttonState = 0;
int lastButtonState = 0;
int Turnradius = 0; //Set the radius of a turn, 0 - 255 Note:the robot will malfunction if this is higher than int Speed.
int brakeTime = 45;
int brkonoff = 1; //1 for the electronic braking system, 0 for normal.
void setup() {
  pinMode(m1_c1, OUTPUT);
  pinMode(m1_c2, OUTPUT);
  pinMode(m2_c1, OUTPUT);
  pinMode(m2_c2, OUTPUT);
  bluetooth.begin(9600);
  Serial.begin(9600); 
}
void loop() {
  while (bluetooth.available()) 
  {
    command = bluetooth.read();
    Stop(); //Initialize with motors stoped.
    switch (command) 
    {
      case 70:
        forward();
        Serial.println("FWD");
        break;
      case 66:
        back();
         Serial.println("BCK");
        break;
      case 76:
        left();
         Serial.println("LFT");
        break;
      case 82:
        right();
        Serial.println("RGT");
        break;
             case 83:
       Stop();
        Serial.println("STP");
        break;
      case 'G':
        forwardleft();
        break;
      case 'I':
        forwardright();
        break;
      case 'H':
        backleft();
        break;
      case 'J':
        backright();
        break;
    }
    Speedsec = Turnradius;
    if (brkonoff == 1) {
      brakeOn();
    } else 
    {
      brakeOff();
    }
  }
}
void forward() {
  digitalWrite(m1_c1, HIGH);
  digitalWrite(m1_c2,LOW);
  digitalWrite(m2_c1, HIGH);
  digitalWrite(m2_c2,LOW);
}
void back() {
  digitalWrite(m1_c1, LOW);
  digitalWrite(m1_c2,HIGH);
  digitalWrite(m2_c1, LOW);
  digitalWrite(m2_c2,HIGH);
}
void left() {
  digitalWrite(m1_c1, LOW);
  digitalWrite(m1_c2,HIGH);
   digitalWrite(m2_c1, HIGH);
  digitalWrite(m2_c2,LOW);
}
void right() {
   digitalWrite(m1_c1, HIGH);
  digitalWrite(m1_c2,LOW);
  digitalWrite(m2_c1, LOW);
  digitalWrite(m2_c2,HIGH);
}
void forwardleft() {
//  digitalWrite(m1_c1, Speedsec);
//  digitalWrite(m2_c1, Speed);
}
void forwardright() {
//  digitalWrite(m1_c1, Speed);
//  digitalWrite(m2_c1, Speedsec);
}
void backright() {
//  digitalWrite(m1_c2, Speed);
//  digitalWrite(m2_c2, Speedsec);
}
void backleft() {
//  digitalWrite(m1_c2, Speedsec);
//  digitalWrite(m2_c2, Speed);
}
void Stop() {
  digitalWrite(m1_c1, LOW);
  digitalWrite(m1_c2, LOW);
  digitalWrite(m2_c1, LOW);
  digitalWrite(m2_c2, LOW);
}
void brakeOn() {
  //Here's the future use: an electronic braking system!
  // read the pushbutton input pin:
  buttonState = command;
  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == 'S') {
      if (lastButtonState != buttonState) {
        digitalWrite(m1_c1, HIGH);
        digitalWrite(m1_c2, HIGH);
        digitalWrite(m2_c1, HIGH);
        digitalWrite(m2_c2, HIGH);
        delay(brakeTime);
        Stop();
      }
    }
    // save the current state as the last state,
    //for next time through the loop
    lastButtonState = buttonState;
  }
}
void brakeOff() {
}
