#include "Morse.h"

Morse morse(13); 

int numdata=0;//for incoming serial data

void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
  while(Serial.read()>= 0){ }//clear serial port
}

void loop() {
  // put your main code here, to run repeatedly:
   // read data from serial port
 
  while(Serial.available()>0){
    delay(3000);
    numdata = Serial.read();//读串口第一个字节
    switch(numdata){
      case 'a' :{
      morse.dot();
      morse.dash();
      continue;
      }
      
      
      case 'b' :{
      morse.dash();
      morse.dot();
      morse.dot();
      morse.dot();
      continue;
      }

      case 'c' :{
      morse.dash();
      morse.dot();
      morse.dash();
      morse.dot();
      continue;
      }

      case 'd' :{
      morse.dash();
      morse.dot();
      morse.dot();
      continue;
      }
      
      case 'e':{
      morse.dot();
      continue;
      }

      case 'f' :{
      morse.dot();
      morse.dot();
      morse.dash();
      morse.dot();
      continue;
      }

      case 'g' :{
      morse.dash();
      morse.dot();
      morse.dot();
      continue;
      }

      case 'h' :{
      morse.dot();
      morse.dot();
      morse.dot();
      morse.dot();
      continue;
      }
      case 'i' :{
      morse.dot();
      morse.dot();
      continue;
      }

      case 'j' :{
      morse.dot();
      morse.dash();
      morse.dash();
      morse.dash(); 
      continue;
      }

      case 'k' :{
      morse.dash();
      morse.dot();
      morse.dash();
      continue;
      }

      case 'l' :{
      morse.dot();
      morse.dash();
      morse.dot();
      continue;
      }

      case 'm' :{
      morse.dash();
      morse.dash();
      continue;
      }

      case 'n' :{
      morse.dash();
      morse.dot();
      continue;
      }

      case 'o' :{
      morse.dash();
      morse.dash();
      morse.dash();
      continue;
      }

      case 'p' :{
      morse.dot();
      morse.dash();
      morse.dash();
      morse.dot();
      continue;
      }

      case 'q' :{
      morse.dash();
      morse.dash();
      morse.dot();
      morse.dash();
      continue;
      }


      case 'r' :{
      morse.dot();
      morse.dash();
      morse.dot();
      continue;
      }

      case 's' :{
      morse.dot();
      morse.dot();
      morse.dot();
      continue;
      }

      case 't' :{
      morse.dash();
      continue;
      }

      case 'u' :{
      morse.dot();
      morse.dot();
      morse.dash();
      continue;
      }
      case 'v' :{
      morse.dot();
      morse.dot();
      morse.dot();
      morse.dash();
      continue;
      }
      
      case 'w' :{
      morse.dot();
      morse.dash();
      morse.dash();
      continue;
      }
      
      case 'x' :{
      morse.dash();
      morse.dot();
      morse.dot();
      morse.dash();
      continue;
      }
      
      case 'y' :{
      morse.dash();
      morse.dot();
      morse.dash();
      morse.dash();
      continue;
      }
      
      case 'z' :{
      morse.dash();
      morse.dash();
      morse.dot();
      morse.dot();
      continue;
      }

      case ' ' :{
      morse.c_space();
      continue;
      }
      
      case '\r' :{
      morse.w_space();
      continue;
      }

      default:{
      Serial.print("Please input lowercase letters, or' ', or'\r'");
      continue;
      
      }
    }
  }
}
