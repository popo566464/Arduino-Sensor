int Vrx;
int Vry;

void setup() {
  Serial.begin(9600);
}

void loop() {
Vrx = analogRead(A0);
Vry = analogRead(A1);
Serial.print(Vrx);
Serial.print(",");
Serial.println(Vry);
delay(10);

}
