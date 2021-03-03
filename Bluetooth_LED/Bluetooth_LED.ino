#include<Servo.h>

byte cmmd[20];
int insize,a;
int Led = 5;
Servo servo;


void setup() {
  Serial.begin(9600);
  pinMode(5, OUTPUT);
  servo.attach(9);
}

void loop() {
  
  while(1){
    if((insize = (Serial.available()))>0){
      Serial.print("input size = ");
      Serial.println(insize);
      for (int i=0; i<insize; i++){
         Serial.print(cmmd[i]=char(Serial.read()));
         Serial.print(" ");
        }
     }
  }
  if(insize==4){  
      a = (cmmd[0]-48)*10;
      a=a+(cmmd[1]-48);
  }
  if(insize==3){
      a=(cmmd[0]-48);
  }
  Serial.println(a);
  servo.write(map(a,0,50,0,180));
}
