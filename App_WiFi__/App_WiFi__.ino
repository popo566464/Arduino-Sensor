#include<ESP8266WiFi.h>

char *ssid = "Jean";
char *passward = "20191007";

int Led = 13;
WiFiServer server(80);

void setup() {

Serial.begin(9600);
delay(10);

pinMode(Led,OUTPUT);
WiFi.begin(ssid,passward);
while(WiFi.status() != WL_CONNECTED){
  delay(500);
  Serial.println(".");
}
Serial.print("connect to");
Serial.println(ssid);
server.begin();
Serial.println("Server started");
Serial.println(WiFi.localIP());

}

void loop() {
WiFiClient client = server.available();
if(!client){
  return;
}
while(!client.available()){
  delay(1);
}
String req = client.readStringUntil('\r');
if(req.indexOf("gpio/1")!= -1){
  digitalWrite(Led,HIGH);
}
else if(req.indexOf("gpio/0")!= -1){
  digitalWrite(Led,LOW);
}
else{
  client.stop();
  Serial.println("invail request");
  return;
}
client.flush();  
}
