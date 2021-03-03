int MIC=A1;  
int LED=6;  
boolean toggle=false;
int micVal;
long current=0; 
long last=0;  
long diff=0;  
int count=0;  

void setup() {
  pinMode(LED, OUTPUT);
  pinMode (MIC, INPUT);
  Serial.begin(9600);
  }

void loop() {
  micVal=analogRead(MIC);
  Serial.println(micVal); 
  if (micVal > 30) { 
    current=millis(); 
    ++count;  
    Serial.print("count=");  
    Serial.println(count);
    if (count >= 2) {  
      diff=current-last; 
      if (diff > 300 && diff < 1500) { 
        toggle = !toggle;  
        count=0;  
        }
      else {count=1;}  
      }
    last=current;  
    if (toggle) {digitalWrite(LED, HIGH);} 
    else {digitalWrite(LED, LOW);}  
    }
  }
