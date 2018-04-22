/*
  Written by    : Shaifur Rahman
  Date          : 01 April 2018
  Device(s)     : Arduino UNO, TekModules Digital IR 8Array
  Code Version  : 2.0

  Connection Diagram:
  Arduino <-->  Motor Driver
  D2    <--> MotorA1
  D4    <--> MotorA2
  D3    <--> MotorA-PWM
  D5    <--> MotorB1
  D7    <--> MotorB2
  D6    <--> MotorB-PWM
  Description:
  This code will help you to test any L293D or L298N based standard Motor Driver.This default code will drive your motor every possible combination. Use this functions and do further modification to make it work in your real projects.
*/

byte motorA_1 = 2;
byte motorA_2 = 4;
byte motorA_Speed = 3;
byte motorB_1 = 5;
byte motorB_2 = 7;
byte motorB_Speed = 6;

void setup()
{
  Serial.begin(9600);
  //Initialized Motor Driver Pins as Output
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop()
{
  MotorSpeed(); // Set Motor Speed
  Serial.println("Driving Forward");
  drive_forward();
  delay(1000);
  motor_stop();

  Serial.println("Driving Forward");
  drive_backward();
  delay(1000);
  motor_stop();

  Serial.println("Turnning Left");
  turn_left();
  delay(1000);
  motor_stop();

  Serial.println("Turnning Left");
  turn_right();
  delay(1000);
  motor_stop();

  Serial.println("Testing Done !");
  delay(2000);
}

// Motor Driving Functions

// Set Motor Speed 0 is stop & 255 is max speed
void MotorSpeed() {
  analogWrite(motorA_Speed, 255);
  analogWrite(motorB_Speed, 255);
}
//Stop Both Motor
void motor_stop() {
  digitalWrite(motorA_1, LOW);
  digitalWrite(motorA_2, LOW);
  digitalWrite(motorB_1, LOW);
  digitalWrite(motorB_2, LOW);
  delay(5);
}

void drive_forward() {
  digitalWrite(motorA_1, HIGH);
  digitalWrite(motorA_2, LOW);
  digitalWrite(motorB_1, HIGH);
  digitalWrite(motorB_2, LOW);
  delay(5);
}

void drive_backward() {
  digitalWrite(motorA_1, LOW);
  digitalWrite(motorA_2, HIGH);
  digitalWrite(motorB_1, LOW);
  digitalWrite(motorB_2, HIGH);
  delay(5);
}

void turn_left() {
  digitalWrite(motorA_1, LOW);
  digitalWrite(motorA_2, LOW);
  digitalWrite(motorB_1, HIGH);
  digitalWrite(motorB_2, LOW);
  delay(5);
}

void turn_right() {
  digitalWrite(motorA_1, HIGH);
  digitalWrite(motorA_2, LOW);
  digitalWrite(motorB_1, LOW);
  digitalWrite(motorB_2, LOW);
  delay(5);
}
