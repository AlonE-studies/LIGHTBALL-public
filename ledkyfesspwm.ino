#include <HC05.h>


//**************************************************************//
//  Name    : LIGHTBALL                                
//  Author  : Matej Luha
//  Date    :   
//  Modified:                                 
//  Version :                                            
//  Notes   :                       
//****************************************************************

//Pin connected to ST_CP of 74HC595
int latchPin = 8;
//Pin connected to SH_CP of 74HC595
int clockPin = 12;
////Pin connected to DS of 74HC595
int dataPin = 11;
int analogPWM = 150;
int analogPin = 2;
int numberToDisplay = B10000001;
char bluetooth='S';
int registerCount = 2;
int[] numbersToDisplay = int[registerCount];
int Reg1
int Reg2


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
    case '1' : ON      () ; break;
    case '0' : OFF     () ; break;
  }
}

  //This turns LEDs ON
  void ON(){  
   Reg1 = B11111111;
   Reg2 = B11111111;
   digitalWrite(latchPin, LOW);
   shiftOut(dataPin, clockPin, MSBFIRST, reg1);
   shiftOut(dataPin, clockPin, MSBFIRST, reg2);
   digitalWrite(latchPin, HIGH);
   delay(10);
     }
  
  //This turns LEDs OFF
  void OFF(){
   numberToDisplay = B00000000;
   digitalWrite(latchPin, LOW);
   shiftOut(dataPin, clockPin, MSBFIRST, numberToDisplay);
   digitalWrite(latchPin, HIGH);
   delay(10);
 }
  
 void repeat(){
    for(int i=0; i<4; i++){
    Zapnut();
    Vypnut();
  }
 }
