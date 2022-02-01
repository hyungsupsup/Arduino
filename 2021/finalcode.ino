#include <SoftwareSerial.h>
SoftwareSerial BTSerial(2, 3);

void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,OUTPUT);
    
 
}

void loop() {
  Serial.println("------------------------");
  Serial.println(analogRead(A0));
  Serial.println(analogRead(A1));
  Serial.println(analogRead(A2));
  Serial.println("hello");
  int a1 = analogRead(A0);
  int a2 = analogRead(A1);
  int a3 = analogRead(A2);
  delay(1000);
  
  char data;

//  if (a1<50 or a2<50 or a3<50) {
//    digitalWrite(A3,HIGH);
//    
//  }
  if (a1<100 and a2>400 and a3>400){
    data='1';
    //delay(5000);
  }
  else if (a1>400 and a2<100 and a3>400){
    data='2';
    //delay(5000);
  }
  else if (a1>400 and a2>400 and a3<100){
    data='3';
    //delay(5000);
  }
  else if (a1>400 and a2>400 and a3>400){
    data='0';
  }
  BTSerial.write(data);
  Serial.write(data);

}
