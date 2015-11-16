// Define the LED digit patters, from 0 - 9
// Note that these patterns are for common cathode displays
// For common anode displays, change the 1's to 0's and 0's to 1's
// 1 = LED on, 0 = LED off, in this order:
// Arduino pin: 2,3,4,5,6,7,8
byte seven_seg_digits[][7] = { 
    { 1,1,1,1,1,1,0 },  // = 0
    { 0,1,1,0,0,0,0 },  // = 1
    { 1,1,0,1,1,0,1 },  // = 2
    { 1,1,1,1,0,0,1 },  // = 3
    { 0,1,1,0,0,1,1 },  // = 4
    { 1,0,1,1,0,1,1 },  // = 5
    { 1,0,1,1,1,1,1 },  // = 6
    { 1,1,1,0,0,0,0 },  // = 7
    { 1,1,1,1,1,1,1 },  // = 8
    { 1,1,1,0,0,1,1 },   // = 9
    { 1,0,1,1,1,0,1 },  // eyeOpen
    { 1,0,0,1,0,0,0 }   // eyeClose
  };

void setup() {                
  pinMode(2, OUTPUT);   
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  
  //writeDot(0);  // start with the "dot" off
}

void writeDot(byte dot) {
  digitalWrite(9, dot);
}
    
void sevenSegWrite(byte digit) {
  // 
  byte pin = 2;
  for (byte segCount = 0; segCount < 7; ++segCount) {
    // pin 2 HIGH, LOW digitalWrite(pinNumber, HIGH, LOW);
    digitalWrite(pin, seven_seg_digits[digit][segCount]); // digitalWrite(pin, HIGH, LOW)
    ++pin;
  }
}

void eyeOpen() {
  sevenSegWrite(10);
}

void eyeClose() {
  sevenSegWrite(11);
}

void zero() {
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
}

void one() {
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
}

void turnOffAll() {
  int i=2; // initialize
  for(i=2; i<9; i++){
    digitalWrite(i, LOW);
  }
}

void loop() {

    digitalWrite(2, HIGH);
    delay(100);
    
  
  /*
  for (byte count = 11; count > 0; --count) {
   delay(1000);
   sevenSegWrite(count - 1); // array index 
  }
  delay(4000);
  */
  
}
