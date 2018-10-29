
int enA = 11;
int in1 = 9;
int in2 = 8;

void setup()
{
  // set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

}

void loop()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  for (int i = 0; i < 256; i++)
  {
    analogWrite(enA, i);
    delay(20);
  }
}
