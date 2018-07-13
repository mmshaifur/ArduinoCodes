

int ch3 = 10;
int ch1 = 12;
int ch8 = 4;
int ch1Read;
int ch3Read;
int ch8Read;
int MotorSpeed = 0;

int MotorA_1_Speed = 5;
int MotorA_2_Speed = 6;
int MotorA_1_EN = 7;
int MotorA_2_EN = 8;


void setup() {
  Serial.begin(115200);
  pinMode(ch1, INPUT);
  pinMode(ch3, INPUT);
  pinMode(ch8, INPUT);
  delay(500);
  pinMode(MotorA_1_Speed, OUTPUT);
  pinMode(MotorA_2_Speed, OUTPUT);
  pinMode(MotorA_1_EN, OUTPUT);
  pinMode(MotorA_2_EN, OUTPUT);
//  digitalWrite(m1_c1, LOW);
//  digitalWrite(m1_c2, LOW);
//  digitalWrite(m2_c1, LOW);
//  digitalWrite(m2_c2, LOW);
}
void loop() {
  ch1Read = pulseIn (ch1, HIGH);
  ch3Read = pulseIn (ch3, HIGH);
  ch8Read = pulseIn (ch8, HIGH);
  MotorSpeed = map(ch8Read, 1055, 1900, 0, 255);
  if (ch3Read < 1200)
  {
    forward();
    Serial.println("FORWAD");
    Serial.println(MotorSpeed);
  }
  else if (ch3Read > 1600) {
    back();
    Serial.println("BACK");
    Serial.println(MotorSpeed);
    
  }
  else {
    Stop();
    Serial.println("STOP");
  }
  if (ch1Read < 1200) {
    left();
    Serial.println("LEFT");

  }
  else if (ch1Read > 1600) {
    right();
    Serial.println("RIGHT");
  }
  else {
    Serial.println("Straight");
  }
}


void forward() {
   digitalWrite(MotorA_2_EN, LOW);
  analogWrite(MotorA_2_Speed, 0);
  digitalWrite(MotorA_1_EN, HIGH);
  analogWrite(MotorA_1_Speed, MotorSpeed);
 
}
void back() {
   digitalWrite(MotorA_1_EN, LOW);
  analogWrite(MotorA_1_Speed, 0);
  delay(100);
   digitalWrite(MotorA_2_EN, HIGH);
  analogWrite(MotorA_2_Speed, MotorSpeed);

}
void left() {
//  digitalWrite(m1_c1, LOW);
//  digitalWrite(m1_c2, HIGH);
  //  digitalWrite(m2_c1, HIGH);
  //  digitalWrite(m2_c2, LOW);
}
void right() {
  //  digitalWrite(m1_c1, HIGH);
  //  digitalWrite(m1_c2, LOW);
  //  digitalWrite(m2_c1, LOW);
  //  digitalWrite(m2_c2, HIGH);
}
void Stop() {
//  digitalWrite(m1_c1, LOW);
//  digitalWrite(m1_c2, LOW);
//  digitalWrite(m2_c1, LOW);
//  digitalWrite(m2_c2, LOW);
}

