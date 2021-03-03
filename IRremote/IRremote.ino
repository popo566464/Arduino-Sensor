#include<IRremote.h>

IRrecv irrecv(6);
decode_results results;
int Led = 5;
bool Satue = false;
  
void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  Serial.println("Enable IRin");

}

void loop() {
  if(irrecv.decode(&results)){
    Serial.println(results.value);
    if(results.value == 16738455){   //0
      Satue = !Satue;
      digitalWrite(Led,Satue);
  }
    irrecv.resume();
  }
  delay(100);

}
