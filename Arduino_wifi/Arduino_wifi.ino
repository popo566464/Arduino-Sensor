 //#include <SPI.h>
 #include <ESP8266WiFi.h>
 #include <WiFiClient.h>
 
 char ssid[] = "HowFun"; // your network SSID (name) 
 char pass[] = "88888888"; // your network password
 
 int led1 = 13;  //D7
 
 
 WiFiServer server(80); 
 
 char thisChar = 0;
 
 void setup() {   
   pinMode(led1, OUTPUT);
   Serial.begin(115200); 
   WiFi.begin(ssid, pass);
   Serial.println("Correcting");
   while ( WiFi.status() != WL_CONNECTED) {           
     delay(500);
     Serial.println(".");
   }

  server.begin();
   
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());
 
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);
  }
 
 
 void loop() {
  
   WiFiClient client = server.available();    
   if (client) {
     while(client.available()) {  
        thisChar = client.read();  
        client.flush();      
        if (thisChar == 49) {                            
           Serial.print("Light on"); 
           client.println("Light on"); 
           digitalWrite(led1, HIGH);             
        }         
        if (thisChar == 48) {                           
           Serial.print("Light off");  
           client.println("Light off");    
           digitalWrite(led1, LOW);
        }  
     }     
  }
}
   
 

 
