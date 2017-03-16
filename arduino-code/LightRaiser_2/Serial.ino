 void readSerial(){
  while (Serial.available()) {
      char c = Serial.read();  //gets one byte from serial buffer
      input += c; //makes the String input
      delay(2);  //slow looping to allow buffer to fill with next character
  }
  //Test if input is larger than zero
  if (input.length() >0) {
      switch(input[0]){
        case 'x':
          if(input[1] == 'p'){
            command = "xp";
          }else if(input[1] == 'n'){
            command = "xn";
          }else if(input[1] == 's'){
            command = "";
          }
          break;
        case 'y':
          if(input[1] == 'p'){
            command = "yp";
          }else if(input[1] == 'n'){
            command = "yn";
          }else if(input[1] == 's'){
            command = "";
          }
          break;
        case 'z':
          if(input[1] == 'p'){
            command = "zp";
          }else if(input[1] == 'n'){
            command = "zn";
          }else if(input[1] == 's'){
            command = "";
          }
          break;
      }
      //Reset input
      input = "";
  } 
}
