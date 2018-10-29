#define trig 2
#define echo 3
int buzz = 9;

void setup() {
  // put your setup code here, to run once:
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(buzz, OUTPUT);
  digitalWrite(buzz, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  int t, d;
  digitalWrite(trig, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig, LOW);
  t = pulseIn(echo, HIGH);
  d = (t / 2) / 29.1;

  if (d <= 10) {
    tone(buzz, 3000, 100);
    delay(200);
  }
  if (d <= 20 && d > 10) {
    tone(buzz, 2000, 100);
    delay(400);
  }
  if (d > 20) {
    tone(buzz, 2000, 100);
    delay(800);
  }
}
