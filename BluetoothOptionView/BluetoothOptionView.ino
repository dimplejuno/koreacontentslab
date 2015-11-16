#include <SoftwareSerial.h>

#define rxPin 3
#define txPin 2

SoftwareSerial SwSerial(rxPin, txPin);
char data;

void setup() {
  Serial.begin(9600);
  SwSerial.begin(9600);
  Serial.println("Ready..");
}

void loop() {
   // 시리얼 버퍼를 비운다.
   Serial.flush();
   Serial.print("cmd : ");
   // 버퍼에 값이 들어올 때 까지 대기. 
   while(!Serial.available());
   // HC-06 으로 명령어를 날린다. 
   while(Serial.available()) {
      data = Serial.read();
      if(data == -1) break;
      SwSerial.print(data);
      Serial.print(data);
      // 시리얼 통신에서는 9600bps 기준으로
      // read 를 사용할 때 1ms 의 딜레이를 줘야 한다.
      delay(1);
   }   
   Serial.println();
   // HC-06에서 처리할 시간을 준다.
   delay(1000);
   Serial.print("return : ");
   // HC-06 으로 부터 받아온 리턴 값을 출력한다.
   while(SwSerial.available()) {
      data = SwSerial.read();
      if(data == -1) break;
      Serial.print(data);
      delay(1);
   }  
   Serial.print("\n\n");
}
