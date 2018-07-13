
const int chA = 7;
const int chC = 6;
int ch1;
int ch3;
int m1_c1 = 12;
int m1_c2 = 11;
int m2_c1 = 10;
int m2_c2 = 9;

void setup() {
  Serial.begin(115200);
  pinMode(chA, INPUT);
  pinMode(chC, INPUT);
  delay(500);
   pinMode(m1_c1, OUTPUT);
  pinMode(m1_c2, OUTPUT);
  pinMode(m2_c1, OUTPUT);
  pinMode(m2_c2, OUTPUT);
  digitalWrite(m1_c1,LOW);
  digitalWrite(m1_c2,LOW);
  digitalWrite(m2_c1,LOW);
  digitalWrite(m2_c2,LOW);
}
void loop() {
  ch1 = pulseIn (chA, HIGH);
  ch3 = pulseIn (chC, HIGH);
  if (ch3 < 1200)
  {
    forward();
    Serial.println("FORWAD");
  }
  else if (ch3 > 1600) {
    back();
    Serial.println("BACK");
  }
  else {
    Stop();
    Serial.println("STOP");
  }
  if (ch1 < 1200) {
    left();
    Serial.println("LEFT");

  }
  else if (ch1 > 1600) {
    right();
    Serial.println("RIGHT");
  }
  else {
    Serial.println("Straight");
  }
}


void forward() {
  digitalWrite(m1_c1, HIGH);
  digitalWrite(m1_c2, LOW);
  digitalWrite(m2_c1, HIGH);
  digitalWrite(m2_c2, LOW);
}
void back() {
  digitalWrite(m1_c1, LOW);
  digitalWrite(m1_c2, HIGH);
  digitalWrite(m2_c1, LOW);
  digitalWrite(m2_c2, HIGH);
}
void left() {
  digitalWrite(m1_c1, LOW);
  digitalWrite(m1_c2, HIGH);
  digitalWrite(m2_c1, HIGH);
  digitalWrite(m2_c2, LOW);
}
void right() {
  digitalWrite(m1_c1, HIGH);
  digitalWrite(m1_c2, LOW);
  digitalWrite(m2_c1, LOW);
  digitalWrite(m2_c2, HIGH);
}
void Stop() {
  digitalWrite(m1_c1, LOW);
  digitalWrite(m1_c2, LOW);
  digitalWrite(m2_c1, LOW);
  digitalWrite(m2_c2, LOW);
}

