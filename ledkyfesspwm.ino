#include <HC05.h>


//**************************************************************//
//  Name    : LIGHTBALL                                
//  Author  : Matej Luha
//  Date    :   
//  Modified:                                 
//  Version :                                            
//  Notes   : ON/OFF working, Lightning cannot be turned off
//**************************************************************//

//Pin connected to ST_CP of 74HC595
int latchPin = 8;
//Pin connected to SH_CP of 74HC595
int clockPin = 12;
////Pin connected to DS of 74HC595
int dataPin = 11;
int analogPWM = 150;
int analogPin = 2;
char bluetooth='S';
const int registerCount = 2;
int numberToDisplay[registerCount];
int Reg1;
int Reg2;


void setup() {

  
  //set pins to output so you can control the shift register
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(analogPin, OUTPUT);
  Serial.begin(9600);
  
    // take the latchPin low so 
    // the LEDs don't change while you're sending in bits:
    digitalWrite(latchPin, LOW);
 
    // shift out the bits:
    shiftOut(dataPin, clockPin, MSBFIRST, numberToDisplay);  

    //take the latch pin high so the LEDs will light up:
    digitalWrite(latchPin, HIGH);
    // pause before next value:
    delay(500);
}

//Bluetooth part, reading commands from App
void loop() {
  bluetooth=Serial.read();
switch (bluetooth) {
    case '1' : ON() ; break;
    case '0' : OFF() ; break;
    case 'L' : Lightning();break;
  }
  if (analogPWM = 255)
{
  analogPWM = 0;
}
analogPWM++;
analogWrite(analogPin, analogPWM);
}

  //This turns LEDs ON
  void ON(){  
   int Reg1 = B11111111;
   int Reg2 = B11111111;
   digitalWrite(latchPin, LOW);
   shiftOut(dataPin, clockPin, MSBFIRST, Reg1);
   shiftOut(dataPin, clockPin, MSBFIRST, Reg2);
   digitalWrite(latchPin, HIGH);
   delay(10);
     }
  
  //This turns LEDs OFF
  void OFF(){
   int Reg1 = B00000000;
   int Reg2 = B00000000;
   digitalWrite(latchPin, LOW);
   shiftOut(dataPin, clockPin, MSBFIRST, Reg1);
   shiftOut(dataPin, clockPin, MSBFIRST, Reg2);
   digitalWrite(latchPin, HIGH);
   delay(10);
 }

  //This does lightning effect
  void Lightning(){
    do {
    int Reg1 = random(B00000001, B11111111);
    int Reg2 = random(B00000001, B11111111);
    int randomDelay = random (10, 200);
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, Reg1);
    shiftOut(dataPin, clockPin, MSBFIRST, Reg2);
    digitalWrite(latchPin, HIGH);
    delay(randomDelay);
      bluetooth=Serial.read();
   } while (bluetooth == 'L');
  }
  
 void repeat(){
    for(int i=0; i<4; i++){
    ON();
    OFF();
  }
 }
