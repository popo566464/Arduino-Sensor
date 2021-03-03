#include <ESP8266WiFi.h>
#include <WiFiClient.h>

char ssid[] = "Jean_2.4"; // your network SSID (name) 
char passward[] = "20191007"; // your network password
 
char server[] = "www.popo566464.000webhostapp.com";
int Led = 13;
int loginUser;
int PassScore;
String Data;

WiFiClient client; 



void setup() {

Serial.begin(9600);

pinMode(Led,OUTPUT);
WiFi.begin(ssid,passward);
while(WiFi.status() != WL_CONNECTED){
  delay(500);
  Serial.println(".");
}
Serial.print("connect to");
Serial.println(ssid);
Serial.println(WiFi.localIP());

}

void loop() {
  loginUser = 123;
  PassScore = 5;
  Data =String("") + "loginUser=" + loginUser + "&PassScore=" + PassScore;
  if(client.connect(server,80)){    
    client.println("POST /Score2.php HTTP/1.1");
    client.println("Host: popo566464.000webhostapp.com");
    client.println("Content-Type: application/x-www-form-urlencoded");
    client.print("Content-Length: ");
    client.println(Data.length());
    client.println();
    client.print(Data);
  }
  if(client.connected()){
    client.stop();
  }
  delay(5000);
}
