void step1X()
{
  digitalWrite(apin, LOW);
  digitalWrite(napin, HIGH);
  digitalWrite(bpin, HIGH);
  digitalWrite(nbpin, LOW);
  delay(stepDelay);
}
void step2X()
{
  digitalWrite(apin, LOW);
  digitalWrite(napin, HIGH);
  digitalWrite(bpin, LOW);
  digitalWrite(nbpin, HIGH);
  delay(stepDelay);
}
void step3X()
{
  digitalWrite(apin, HIGH);
  digitalWrite(napin, LOW);
  digitalWrite(bpin, LOW);
  digitalWrite(nbpin, HIGH);
  delay(stepDelay);
}
void step4X()
{
  digitalWrite(apin, HIGH);
  digitalWrite(napin, LOW);
  digitalWrite(bpin, HIGH);
  digitalWrite(nbpin, LOW);
  delay(stepDelay);
}
void stopMotorX()
{
  digitalWrite(apin, LOW);
  digitalWrite(napin, LOW);
  digitalWrite(bpin, LOW);
  digitalWrite(nbpin, LOW);
}
void clockwiseX()
{
  step1X();
  step2X();
  step3X();
  step4X();
}
void cclockwiseX()
{
  step3X();
  step2X();
  step1X();
  step4X();
}
void step1Y()
{
  digitalWrite(apin2, LOW);
  digitalWrite(napin2, HIGH);
  digitalWrite(bpin2, HIGH);
  digitalWrite(nbpin2, LOW);
  delay(stepDelay);
}
void step2Y()
{
  digitalWrite(apin2, LOW);
  digitalWrite(napin2, HIGH);
  digitalWrite(bpin2, LOW);
  digitalWrite(nbpin2, HIGH);
  delay(stepDelay);
}
void step3Y()
{
  digitalWrite(apin2, HIGH);
  digitalWrite(napin2, LOW);
  digitalWrite(bpin2, LOW);
  digitalWrite(nbpin2, HIGH);
  delay(stepDelay);
}
void step4Y()
{
  digitalWrite(apin2, HIGH);
  digitalWrite(napin2, LOW);
  digitalWrite(bpin2, HIGH);
  digitalWrite(nbpin2, LOW);
  delay(stepDelay);
}
void stopMotorY()
{
  digitalWrite(apin2, LOW);
  digitalWrite(napin2, LOW);
  digitalWrite(bpin2, LOW);
  digitalWrite(nbpin2, LOW);
}
void clockwiseY()
{
  step1Y();
  step2Y();
  step3Y();
  step4Y();
}
void cclockwiseY()
{
  step3Y();
  step2Y();
  step1Y();
  step4Y();
}
