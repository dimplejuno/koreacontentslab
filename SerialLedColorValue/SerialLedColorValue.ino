
// pins for the LEDs:
const int redPin = 3;
const int greenPin = 5;
const int bluePin = 6;

static int redColor;
static int greenColor;
static int blueColor;

void setup(){
    Serial.begin(9600);
}


void setRGBColor() {
  analogWrite(redPin, redColor);
  analogWrite(greenPin, greenColor);
  analogWrite(bluePin, blueColor);
}

void rgbColor(int r, int g, int b) {
  analogWrite(redPin, r);
  analogWrite(greenPin, g);
  analogWrite(bluePin, b);
}

void loop(){
  
  while(Serial.available() > 0) {
    String firstCommand  = Serial.readStringUntil(',');
    Serial.read(); //next character is comma, so skip it using this
    String secondValue = Serial.readStringUntil('\n');
    Serial.read();
   
    //parse your data here. example:
    
    if(firstCommand == "red") {
      Serial.print("red on : ");
      Serial.println(secondValue);
      redColor = secondValue.toInt();
    }
    
    if(firstCommand == "green") {
      Serial.print("green on : ");
      Serial.println(secondValue);
      rgbColor(0, secondValue.toInt(), 0);
      greenColor = secondValue.toInt();
    }
    
    if(firstCommand == "blue") {
      Serial.print("blue on : ");
      Serial.println(secondValue);
      rgbColor(0, 0, secondValue.toInt());
      blueColor = secondValue.toInt();
    }
    
    setRGBColor();
    
  }
}
