#include <ESP8266WiFi.h>
#include <WiFiClient.h>

const char* ssid = "Zhi";//put your wifi network name here
const char* password = "19980201 ";//put your wifi password here

//IPAddress ip();
//IPAddress gateway(192.168.1.1);
//IPAddress subnet(255.255.255.0);

WiFiServer server(80);
WiFiClient client;

int SensorState;

// #define echoPin D5    //echo Pin connected to sensor

void setup() 
{
  Serial.begin(9600);

  //pinMode(echoPin, INPUT);

  WiFi.begin(ssid, password);
 // WiFi.config(ip, gateway, subnet);
  Serial.println("Connecting");

  while(WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.print("Connected to ");
  Serial.println(ssid);

  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  server.begin();
  Serial.printf("Web server started, open %s in a web browser\n", WiFi.localIP().toString().c_str());
}

void loop() 
{
  //Liten to connecting clients
  client = server.available();

  if(client)
  {
    Serial.println("Client Connected");
    while(client.connected())
    {
      SensorState = client.read();
      client.flush();
      if(SensorState == 49)
      {
        Serial.println("lighton");
        client.print("lighton");
      }
      if(SensorState == 48)
      {
        Serial.println("lightoff");
        client.print("lightoff");
      }

      delay(500);
    }
  }
}
