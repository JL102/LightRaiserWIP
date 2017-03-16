//Initializing public variables
int apin, napin, bpin, nbpin; //Pin #s for motor controller Y
int apin2, napin2, bpin2, nbpin2; //Pin #s for second motor controller
  // a,Blue
  //na,Black
  //b,Red
  //nb,Yellow 
int stepDelay; //Delay for each step. Lower # = faster motor speed
String input; //String that is read from serial
String command; //For commands sent from serial (interpreted from input)

void setup() {
  //Begins serial and prints 
  Serial.begin(9600);
  Serial.println("Initializing...");
  
  //Sets up pin-out numbers (corresponds to OUTs on arduino)
  apin = 2;
  napin = 3;
  bpin = 4;
  nbpin = 5;
  apin2 = 6;
  napin2 = 7;
  bpin2 = 8;
  nbpin2 = 9;

  //Step delay
  stepDelay = 20;

  //Tells arduino to turn each pin into an OUT.
  pinMode(apin, OUTPUT);
  pinMode(napin, OUTPUT);
  pinMode(bpin, OUTPUT);
  pinMode(nbpin, OUTPUT);
  pinMode(apin2, OUTPUT);
  pinMode(napin2, OUTPUT);
  pinMode(bpin2, OUTPUT);
  pinMode(nbpin2, OUTPUT);

  
}

void loop() {
  // put your main code here, to run repeatedly:
  readSerial();
}
