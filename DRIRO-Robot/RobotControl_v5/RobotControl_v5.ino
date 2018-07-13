
const int CH_1 = 7;
const int CH_3 = 6;
int CH_1_read;
int CH_3_read;
int leftMotor_c1 = 12;
int leftMotor_c2 = 11;
int rightMotor_c1 = 10;
int rightMotor_c2 = 9;

void setup() {
  Serial.begin(115200);
  pinMode(CH_1, INPUT);
  pinMode(CH_3, INPUT);
  delay(500);
  pinMode(leftMotor_c1, OUTPUT);
  pinMode(leftMotor_c2, OUTPUT);
  pinMode(rightMotor_c1, OUTPUT);
  pinMode(rightMotor_c2, OUTPUT);
  digitalWrite(leftMotor_c1, LOW);
  digitalWrite(leftMotor_c2, LOW);
  digitalWrite(rightMotor_c1, LOW);
  digitalWrite(rightMotor_c2, LOW);
}
void loop() {
  CH_1_read = pulseIn (CH_1, HIGH);
  CH_3_read = pulseIn (CH_3, HIGH);
  if (CH_3_read < 1200)
  {
    forward();
    Serial.println("FORWAD");
  }
  else if (CH_3_read > 1600) {
    back();
    Serial.println("BACK");
  }
  else {
    Stop();
    Serial.println("STOP");
  }
  if (CH_1_read < 1200) {
    left();
    Serial.println("LEFT");

  }
  else if (CH_1_read > 1600) {
    right();
    Serial.println("RIGHT");
  }
  else {
    Serial.println("Straight");
  }
}


void forward() {
  digitalWrite(leftMotor_c1, HIGH);
  digitalWrite(leftMotor_c2, LOW);
  digitalWrite(rightMotor_c1, HIGH);
  digitalWrite(rightMotor_c2, LOW);
  delay(25);
}
void back() {
  digitalWrite(leftMotor_c1, LOW);
  digitalWrite(leftMotor_c2, HIGH);
  digitalWrite(rightMotor_c1, LOW);
  digitalWrite(rightMotor_c2, HIGH);
  delay(25);
}
void left() {
  digitalWrite(leftMotor_c1, LOW);
  digitalWrite(leftMotor_c2, HIGH);
  delay(50);
   digitalWrite(leftMotor_c2, LOW);
   delay(25);
  digitalWrite(rightMotor_c1, HIGH);
  digitalWrite(rightMotor_c2, LOW);
  delay(100);
}
void right() {
  digitalWrite(leftMotor_c1, HIGH);
  digitalWrite(leftMotor_c2, LOW);
  digitalWrite(rightMotor_c1, LOW);
  digitalWrite(rightMotor_c2, HIGH);
}
void Stop() {
  digitalWrite(leftMotor_c1, LOW);
  digitalWrite(leftMotor_c2, LOW);
  digitalWrite(rightMotor_c1, LOW);
  digitalWrite(rightMotor_c2, LOW);
}

