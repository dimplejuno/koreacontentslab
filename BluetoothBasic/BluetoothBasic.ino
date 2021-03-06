#include <SoftwareSerial.h>

#define rxPin 3
#define txPin 2

SoftwareSerial mySerial(rxPin, txPin); // RX, TX
char myChar ; 

const int led = 13;

void setup() {
  Serial.begin(9600);   
  Serial.println("Goodnight moon!");

  mySerial.begin(9600);
  mySerial.println("Hello, world?");

  pinMode(led, OUTPUT);
}

void loop(){
  while(mySerial.available()){
    myChar = mySerial.read();

    if(myChar == 'O') {
        digitalWrite(led, HIGH);
    } else if(myChar == 'F') {
      digitalWrite(led, LOW);
    }

    Serial.print(myChar);
  }

  while(Serial.available()){
   myChar = Serial.read();
   mySerial.print(myChar);
  }
}