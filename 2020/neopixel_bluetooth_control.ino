#include <Stepper.h>
#include <SoftwareSerial.h>
#include <Adafruit_NeoPixel.h>  

int i,j,k;
int BT_RXD = 3;
int BT_TXD = 2;
int n_led = 120;    // 네오픽셀 수는 120개
int neo_pin = 6;  // 네오픽셀은 6번핀에 연결
const int stepsPerRevolution = 2037; 

int getbyte;
SoftwareSerial bluetooth(BT_RXD, BT_TXD);
Stepper myStepper(stepsPerRevolution,11,9,10,8);    
Adafruit_NeoPixel strip = Adafruit_NeoPixel(n_led, neo_pin, NEO_GRB + NEO_KHZ800);  // 네오픽셀 객체 불러옴
     
void setup() {
   myStepper.setSpeed(10);
   Serial.begin(115200);
   delay(200);
   bluetooth.begin(9600);
   strip.begin();  // 네오픽셀 시작
}

void loop(){  
  if(bluetooth.available()){
    Serial.write(getbyte);
    getbyte = bluetooth.read();

    if(getbyte =='D'){        //LED on
        for(i=0; i<120; i++){
          strip.setPixelColor(i, 128, 128, 128);
          strip.show();
        }
    }  
          
    if(getbyte =='E'){        //LED off
        for(j=0; j<120; j++){
          strip.setPixelColor(j, 0,0,0);
          strip.show();
        }    
    }if(getbyte =='F'){         //LED Blink    //while문을 쓰기
      for(i=0; i<1; i++){
        for(k=0; k<120; k++){
          strip.setPixelColor(k, 128, 0, 0);   //Red
          strip.show();
         
        }
        for(k=0; k<120; k++){
          strip.setPixelColor(k, 0,0,0);
          strip.show();
        }
          
        for(k=0; k<120; k++){
          strip.setPixelColor(k, 0, 128, 0);    //Green
          strip.show();
         
        }
        for(k=0; k<120; k++){
          strip.setPixelColor(k, 0,0,0);
          strip.show();
        }
        for(k=0; k<120; k++){
          strip.setPixelColor(k, 0, 0, 128);    //Blue
          strip.show();
         
        }
        for(k=0; k<120; k++){
          strip.setPixelColor(k, 0,0,0);
          strip.show();
        }
        for(k=0; k<120; k++){
          strip.setPixelColor(k, 128, 128, 0);    
          strip.show();
         
        }
        for(k=0; k<120; k++){
          strip.setPixelColor(k, 0,0,0);
          strip.show();
        } 
        for(k=0; k<120; k++){
          strip.setPixelColor(k, 128, 0, 128);    
          strip.show();
         
        }
        for(k=0; k<120; k++){
          strip.setPixelColor(k, 0,0,0);
          strip.show();
        }
        for(k=0; k<120; k++){
          strip.setPixelColor(k, 0, 128, 128);    
          strip.show();
         
        }
        for(k=0; k<120; k++){
          strip.setPixelColor(k, 0,0,0);
          strip.show();
        }
        for(k=0; k<120; k++){
          strip.setPixelColor(k, 128, 128, 128);    
          strip.show();
         
        }                                         
      }
    }
  }

    if(getbyte =='A'){       //motor run
        myStepper.setSpeed(10); 
        myStepper.step(stepsPerRevolution);
     }
         
    if(getbyte =='B'){        //Motor Stop
        myStepper.step(0);
        
    }if(getbyte =='C'){        //Motor CounterClockwise
        myStepper.setSpeed(10);
        myStepper.step(-stepsPerRevolution);
    }
              
}
  
