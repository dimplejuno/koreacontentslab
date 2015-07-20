/* 
 Debounce
 
 Each time the input pin goes from LOW to HIGH (e.g. because of a push-button
 press), the output pin is toggled from LOW to HIGH or HIGH to LOW.  There's
 a minimum delay between toggles to debounce the circuit (i.e. to ignore
 noise).  
 
 The circuit:
 * LED attached from pin 13 to ground
 * pushbutton attached from pin 2 to +5V
 * 10K resistor attached from pin 2 to ground
 
 * Note: On most Arduino boards, there is already an LED on the board
 connected to pin 13, so you don't need any extra components for this example.
 
 
 created 21 November 2006
 by David A. Mellis
 modified 30 Aug 2011
 by Limor Fried
 modified 28 Dec 2012
 by Mike Walters
 
 This example code is in the public domain.
 
 http://www.arduino.cc/en/Tutorial/Debounce
 */

// constants won't change. They're used here to 
// set pin numbers:
const int button = 5;    // the number of the pushbutton pin

const int red = 11;           // the pin that the LED is attached to
const int green = 10;
const int blue = 9;

int state = -1;

int brightness = 0;    // how bright the LED is
int fadeAmount = 5;

// Variables will change:
int ledState = HIGH;         // the current state of the output pin

int buttonState;             // the current reading from the input pin
int lastButtonState = LOW;   // the previous reading from the input pin

// the following variables are long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 30;    // the debounce time; increase if the output flickers

void setup() {
  pinMode(button, INPUT_PULLUP);
  
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);

}

void loop() {
  // read the state of the switch into a local variable:
  int reading = digitalRead(button);

  // check to see if you just pressed the button 
  // (i.e. the input went from LOW to HIGH),  and you've waited 
  // long enough since the last press to ignore any noise:  

  // If the switch changed, due to noise or pressing:
  if (reading != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  } 
  
  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer
    // than the debounce delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != buttonState) {
      buttonState = reading;
     
  

      // only toggle the LED if the new button state is HIGH
      if (buttonState == HIGH) {
        ledState = !ledState;
        
         state++; // 0:r 1:g 2:b 3:w
    
        if(state > 3) {
          state = -1;
        }
      }
    }
  }
  
  if(state == 0){
    redFading();
  }
  else if (state == 1) {
    greenFading(); 
  } 
  else if (state == 2) {
    blueFading(); 
  } else if (state == 3) {
    allFading();
  } else if (state == -1) {
    
    analogWrite(red, 0);
    analogWrite(green, 0);
    analogWrite(blue, 0);
  }

  // save the reading.  Next time through the loop,
  // it'll be the lastButtonState:
  lastButtonState = reading;
}


void allFading() {
  // set the brightness of pin 9:
  analogWrite(red, brightness);
  analogWrite(green, brightness);
  analogWrite(blue, brightness);

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount ;
  }
  // wait for 30 milliseconds to see the dimming effect
  delay(10);
}

void redFading() {
  
  // set the brightness of pin 9:
  analogWrite(red, brightness);
  analogWrite(green, 0);
  analogWrite(blue, 0);

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount ;
  }
  // wait for 30 milliseconds to see the dimming effect
  delay(10);
}


void greenFading() {
  
  // set the brightness of pin 9:
  analogWrite(green, brightness);
  analogWrite(red, 0);
  analogWrite(blue, 0);

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount ;
  }
  // wait for 30 milliseconds to see the dimming effect
  delay(10);
}

void blueFading() {
  
  // set the brightness of pin 9:
  analogWrite(blue, brightness);
  analogWrite(green, 0);
  analogWrite(red, 0);

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount ;
  }
  // wait for 30 milliseconds to see the dimming effect
  delay(10);
}

