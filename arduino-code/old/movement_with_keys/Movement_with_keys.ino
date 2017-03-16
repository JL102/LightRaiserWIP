#include <Servo.h>
Servo myservo;  
int apin, napin, bpin, nbpin;
int apin2, napin2, bpin2, nbpin2;
int apin3, napin3, bpin3, nbpin3;
int stop1, stop2, stop3, stop4, stop5;
int stepSize;
String command;
String readString;
void setup() 
{
  Serial.begin(9600);
  Serial.println("Initializing...");

// a,Blue
//na,Black
//b,Red
//nb,Yellow 

  apin = 2;
  napin = 3;
  bpin = 4;
  nbpin = 5;
  apin2 = 6;
  napin2 = 7;
  bpin2 = 8;
  nbpin2 = 9;
  apin3 = 10;
  napin3 = 11;
  bpin3 = 12;
  nbpin3 = 13;
  stop1 = 22;
  stop2 = 23;
  stop3 = 24;
  stop4 = 25;
  stop5 = 26;
  stepSize = 32;
  myservo.attach(27);
  
  pinMode(apin, OUTPUT);
  pinMode(napin, OUTPUT);
  pinMode(bpin, OUTPUT);
  pinMode(nbpin, OUTPUT);
  pinMode(apin2, OUTPUT);
  pinMode(napin2, OUTPUT);
  pinMode(bpin2, OUTPUT);
  pinMode(nbpin2, OUTPUT);
  pinMode(apin3, OUTPUT);
  pinMode(napin3, OUTPUT);
  pinMode(bpin3, OUTPUT);
  pinMode(nbpin3, OUTPUT);
  pinMode(stop1, INPUT);
  pinMode(stop2, INPUT);
  pinMode(stop3, INPUT);
  pinMode(stop4, INPUT);
  pinMode(stop5, INPUT);

  Serial.println("ready");
}
void step1X()
{
  digitalWrite(apin, LOW);
  digitalWrite(napin, HIGH);
  digitalWrite(bpin, HIGH);
  digitalWrite(nbpin, LOW);
  delay(stepSize);
}
void step2X()
{
  digitalWrite(apin, LOW);
  digitalWrite(napin, HIGH);
  digitalWrite(bpin, LOW);
  digitalWrite(nbpin, HIGH);
  delay(stepSize);
}
void step3X()
{
  digitalWrite(apin, HIGH);
  digitalWrite(napin, LOW);
  digitalWrite(bpin, LOW);
  digitalWrite(nbpin, HIGH);
  delay(stepSize);
}
void step4X()
{
  digitalWrite(apin, HIGH);
  digitalWrite(napin, LOW);
  digitalWrite(bpin, HIGH);
  digitalWrite(nbpin, LOW);
  delay(stepSize);
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
  delay(stepSize);
}
void step2Y()
{
  digitalWrite(apin2, LOW);
  digitalWrite(napin2, HIGH);
  digitalWrite(bpin2, LOW);
  digitalWrite(nbpin2, HIGH);
  delay(stepSize);
}
void step3Y()
{
  digitalWrite(apin2, HIGH);
  digitalWrite(napin2, LOW);
  digitalWrite(bpin2, LOW);
  digitalWrite(nbpin2, HIGH);
  delay(stepSize);
}
void step4Y()
{
  digitalWrite(apin2, HIGH);
  digitalWrite(napin2, LOW);
  digitalWrite(bpin2, HIGH);
  digitalWrite(nbpin2, LOW);
  delay(stepSize);
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
void step1Z()
{
  digitalWrite(apin3, LOW);
  digitalWrite(napin3, HIGH);
  digitalWrite(bpin3, HIGH);
  digitalWrite(nbpin3, LOW);
  delay(stepSize);
}
void step2Z()
{
  digitalWrite(apin3, LOW);
  digitalWrite(napin3, HIGH);
  digitalWrite(bpin3, LOW);
  digitalWrite(nbpin3, HIGH);
  delay(stepSize);
}
void step3Z()
{
  digitalWrite(apin3, HIGH);
  digitalWrite(napin3, LOW);
  digitalWrite(bpin3, LOW);
  digitalWrite(nbpin3, HIGH);
  delay(stepSize);
}
void step4Z()
{
  digitalWrite(apin3, HIGH);
  digitalWrite(napin3, LOW);
  digitalWrite(bpin3, HIGH);
  digitalWrite(nbpin3, LOW);
  delay(stepSize);
}
void stopMotorZ()
{
  digitalWrite(apin3, LOW);
  digitalWrite(napin3, LOW);
  digitalWrite(bpin3, LOW);
  digitalWrite(nbpin3, LOW);
}
void clockwiseZ()
{
  step1Z();
  step2Z();
  step3Z();
  step4Z();
  Serial.println("cwZ");
}
void cclockwiseZ()
{
  step3Z();
  step2Z();
  step1Z();
  step4Z();
  Serial.println("ccwZ");
}
void loop() {
  // p = positive n = negative s = stop
  
  if(command != ""){
    digitalRead(stop1);
    digitalRead(stop2);
    switch(command[0]){
        case 'x':
          if(command[1] == 'p' && digitalRead(stop1) == LOW){
            clockwiseX();
          }else if(command[1] == 'n' && digitalRead(stop2) == LOW){
            cclockwiseX();
          }
          break;
        case 'y':
          if(command[1] == 'p'){
            clockwiseY();
          }else if(command[1] == 'n'){
            cclockwiseY();
          }
          break;
        case 'z':
          if(command[1] == 'p'){
            clockwiseZ();
          }else if(command[1] == 'n'){
            cclockwiseZ();
          }
          break;
      }
  }
  while (Serial.available()) {
      char c = Serial.read();  //gets one byte from serial buffer
      readString += c; //makes the String readString
      delay(2);  //slow looping to allow buffer to fill with next character
  }
  //Test if readString is larger than zero
  if (readString.length() >0) {
      switch(readString[0]){
        case 'x':
          if(readString[1] == 'p'){
            command = "xp";
          }else if(readString[1] == 'n'){
            command = "xn";
          }else if(readString[1] == 's'){
            command = "";
          }
          break;
        case 'y':
          if(readString[1] == 'p'){
            command = "yp";
          }else if(readString[1] == 'n'){
            command = "yn";
          }else if(readString[1] == 's'){
            command = "";
          }
          break;
        case 'z':
          if(readString[1] == 'p'){
            command = "zp";
          }else if(readString[1] == 'n'){
            command = "zn";
          }else if(readString[1] == 's'){
            command = "";
          }
          break;
        case 'l':
         if(readString[1] == '1'){
          myservo.write(0);
         }else if(readString[1] == '2'){
          myservo.write(120);
         }else if(readString[1] == '3'){
          myservo.write(240);
         }
          break;
      }
      Serial.println(readString);
      //Reset readString
      readString = "";
  } 
}
