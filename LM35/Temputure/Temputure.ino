int temp = A0;
float temper;
void setup() {
  // put your setup code here, to run once:
  pinMode(temp,INPUT);
  Serial.begin(9600);
  temper = analogRead(temp);
  Serial.println(temper);
}

void loop() {
  // put your main code here, to run repeatedly:
  
}
