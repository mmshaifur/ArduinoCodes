
const int CH_1 = 7;
const int CH_3 = 6;
int CH_1_read;
int CH_3_read;
int m1_c1 = 12;
int m1_c2 = 11;
int m2_c1 = 10;
int m2_c2 = 9;

void setup() {
  Serial.begin(115200);
  pinMode(CH_1, INPUT);
  pinMode(CH_3, INPUT);
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

