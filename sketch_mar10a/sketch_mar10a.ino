#include <WiFiClient.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "Home_Automation";
const char* pwd = "suryahome";

ESP8266WebServer server(80);

String page = "";

void setup(void) {
  // put your setup code here, to run once:
  page = "\
  <h1>Simply Web Server: Made By <b> Suryansh </b> </h1> \
  <a href='/D0ON'><button>SWITCH 1 ON</button></a><br> \
  <a href='/D0OFF'><button>SWITCH 1 OFF</button></a><br> \
  <a href='/D1ON'><button>SWITCH 2 ON</button></a><br>\
  <a href='/D1OFF'><button>SWITCH 2 OFF</button></a><br>\
  <a href='/D2ON'><button>SWITCH 3 ON</button></a><br>\
  <a href='/D2OFF'><button>SWITCH 3 OFF</button></a><br>\
  <a href='/D3ON'><button>SWITCH 4 ON</button></a><br>\
  <a href='/D3OFF'><button>SWITCH 4 OFF</button></a><br>\
  <a href='/D4ON'><button>SWITCH 5 ON</button></a><br>\
  <a href='/D4OFF'><button>SWITCH 5 OFF</button></a><br>\
  <a href='/D5ON'><button>SWITCH 6 ON</button></a><br>\
  <a href='/D5OFF'><button>SWITCH 6 OFF</button></a><br>\
  <a href='/D6ON'><button>SWITCH 7 ON</button></a><br>\
  <a href='/D6OFF'><button>SWITCH 7 OFF</button></a><br>\
  <a href='/D7ON'><button>SWITCH 8 ON</button></a><br>\
  <a href='/D7OFF'><button>SWITCH 8 OFF</button></a><br>\
  <a href='/D8ON'><button>SWITCH 9 ON</button></a><br>\
  <a href='/D8OFF'><button>SWITCH 9 OFF</button></a><br>";
  pinMode(D0,OUTPUT);
  pinMode(D1,OUTPUT);
  pinMode(D2,OUTPUT);
  pinMode(D3,OUTPUT);
  pinMode(D4,OUTPUT);
  pinMode(D5,OUTPUT);
  pinMode(D6,OUTPUT);
  pinMode(D7,OUTPUT);
  pinMode(D8,OUTPUT);
  digitalWrite(D0,LOW);
  digitalWrite(D1,LOW);
  digitalWrite(D2,LOW);
  digitalWrite(D3,LOW);
  digitalWrite(D4,LOW);
  digitalWrite(D5,LOW);
  digitalWrite(D6,LOW);
  digitalWrite(D7,LOW);
  digitalWrite(D8,LOW);
  delay(100);
  Serial.begin(115200);
  WiFi.softAP(ssid,pwd);
  Serial.println("Started Wifi");
  Serial.println("Connected to ");
  Serial.println(ssid);
  Serial.println("IP ADDR: ");
  Serial.println(WiFi.softAPIP());
  server.on("/",[](){ server.send(200,"text/html",page); });
  server.on("/D0OFF",[](){ server.send(200,"text/html",page+"SWITCH 1: OFF"); digitalWrite(D0,LOW); delay(100); });
  server.on("/D0ON",[](){ server.send(200,"text/html",page+"SWITCH 1: ON"); digitalWrite(D0,HIGH); delay(100); });
  server.on("/D1OFF",[](){ server.send(200,"text/html",page+"SWITCH 2: OFF"); digitalWrite(D1,LOW); delay(100); });
  server.on("/D1ON",[](){ server.send(200,"text/html",page+"SWITCH 2: ON"); digitalWrite(D1,HIGH); delay(100); });
  server.on("/D2OFF",[](){ server.send(200,"text/html",page+"SWITCH 3: OFF"); digitalWrite(D2,LOW); delay(100); });
  server.on("/D2ON",[](){ server.send(200,"text/html",page+"SWITCH 3: ON"); digitalWrite(D2,HIGH); delay(100); });
  server.on("/D3OFF",[](){ server.send(200,"text/html",page+"SWITCH 4: OFF"); digitalWrite(D3,LOW); delay(100); });
  server.on("/D3ON",[](){ server.send(200,"text/html",page+"SWITCH 4: ON"); digitalWrite(D3,HIGH); delay(100); });
  server.on("/D4OFF",[](){ server.send(200,"text/html",page+"SWITCH 5: OFF"); digitalWrite(D4,LOW); delay(100); });
  server.on("/D4ON",[](){ server.send(200,"text/html",page+"SWITCH 5: ON"); digitalWrite(D4,HIGH); delay(100); });
  server.on("/D5OFF",[](){ server.send(200,"text/html",page+"SWITCH 6: OFF"); digitalWrite(D5,LOW); delay(100); });
  server.on("/D5ON",[](){ server.send(200,"text/html",page+"SWITCH 6: ON"); digitalWrite(D5,HIGH); delay(100); });
  server.on("/D6OFF",[](){ server.send(200,"text/html",page+"SWITCH 7: OFF"); digitalWrite(D6,LOW); delay(100); });
  server.on("/D6ON",[](){ server.send(200,"text/html",page+"SWITCH 7: ON"); digitalWrite(D6,HIGH); delay(100); });
  server.on("/D7OFF",[](){ server.send(200,"text/html",page+"SWITCH 8: OFF"); digitalWrite(D7,LOW); delay(100); });
  server.on("/D7ON",[](){ server.send(200,"text/html",page+"SWITCH 8: ON"); digitalWrite(D7,HIGH); delay(100); });
  server.on("/D8OFF",[](){ server.send(200,"text/html",page+"SWITCH 9: OFF"); digitalWrite(D8,LOW); delay(100); });
  server.on("/D8ON",[](){ server.send(200,"text/html",page+"SWITCH 9: ON"); digitalWrite(D8,HIGH); delay(100); });
  server.begin();
  Serial.println("Web Started");
}

void loop() {
  // put your main code here, to run repeatedly:
  server.handleClient();
}
