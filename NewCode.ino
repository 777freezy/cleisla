#include <SoftwareSerial.h> 

const int led = 13;
const int releLeft = 4;
const int releRight = 5;
char data = '0';

 
SoftwareSerial bluetooht(2, 3);

void setup() {
  Serial.begin(9600);
  bluetooht.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(releLeft, OUTPUT);
  pinMode(releRight, OUTPUT);
}

void loop() {
  if(bluetooht.available()){
    data = bluetooht.read(); 
    Serial.println(data);
      switch(data){
        case '1':
          digitalWrite(releLeft, HIGH);
          digitalWrite(releRight, HIGH);
          break;
        case '2': 
          digitalWrite(releLeft, LOW);
          digitalWrite(releRight, LOW);
          break;
        case '3': 
          digitalWrite(releLeft, LOW);
          digitalWrite(releRight, HIGH);
          break;
        case '4':
          digitalWrite(releLeft, HIGH);
          digitalWrite(releRight, LOW);
          break;
      }
  }
}
