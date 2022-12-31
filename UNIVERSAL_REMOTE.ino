#include <IRremote.h> 
#define RECEIVER_PIN 7
IRrecv receiver(RECEIVER_PIN);
decode_results results; 
unsigned long key_value = 0; 
int red=10;
int yellow=9;
int green=8;


void setup() {
  Serial.begin(9600); 
  receiver.enableIRIn(); 
  receiver.blink13(true);
  pinMode(red,OUTPUT);
  pinMode(yellow,OUTPUT);
  pinMode(green,OUTPUT);
}

void loop() {
  if (receiver.decode(&results)) { 
    if (results.value == 0xFFFFFFFF) { 
      results.value = key_value; // 
    }
    switch (results.value) { 
      case 0XF7283C77: 
        digitalWrite(green,HIGH);
      
        break;
      case  0XE3F87EF7:
        digitalWrite(yellow,HIGH);
       
        break;
     
      case  0XB33B4597:
        
        digitalWrite(red,HIGH);
        break ;
      case  0XF61E2A57 :
       digitalWrite(8,LOW);
        digitalWrite(9,LOW);
        digitalWrite(10,LOW); 
        break ;
     
    }
    key_value = results.value;
    receiver.resume(); 
  }
}
