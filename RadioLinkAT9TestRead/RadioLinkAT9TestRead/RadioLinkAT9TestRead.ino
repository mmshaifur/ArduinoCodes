
int ch4 = 9;
int ch3 = 10;
int ch2 = 11;
int ch1 = 12;
int ch7 = 3;
int ch8 = 4;
int ch1Read;
int ch2Read;
int ch3Read;
int ch4Read;
int ch7Read;
int ch8Read;


void setup() {
  Serial.begin(115200);
  pinMode(ch1, INPUT);
  pinMode(ch2, INPUT);
  pinMode(ch3, INPUT);
  pinMode(ch4, INPUT);
  pinMode(ch7, INPUT);
  pinMode(ch8, INPUT);
  delay(500);

  Serial.begin(9600);
}
void loop() {
  ch1Read = pulseIn (ch1, HIGH);
  ch2Read = pulseIn (ch2, HIGH);
  ch3Read = pulseIn (ch3, HIGH);
  ch4Read = pulseIn (ch4, HIGH);
  ch7Read = pulseIn (ch7, HIGH);
  ch8Read = pulseIn (ch8, HIGH);
  Serial.print("CH1: ");
  Serial.print(ch1Read);
  Serial.print(" | ");
  Serial.print("CH2: ");
  Serial.print(ch2Read);
  Serial.print(" | ");
  Serial.print("CH3: ");
  Serial.print(ch3Read);
  Serial.print(" | ");
  Serial.print("CH4: ");
  Serial.print(ch4Read);
  Serial.print(" | ");
  Serial.print("CH7: ");
  Serial.print(ch7Read);
  Serial.print(" | ");
  Serial.print("CH8: ");
  Serial.print(ch8Read);
  Serial.println();
}
