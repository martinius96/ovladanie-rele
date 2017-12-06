
#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
int led = 16; //PIN D0 na NODEMCU
const char* ssid = "wifimeno";
const char* password = "wifiheslo";

const char* host = "moj.webserver.com"; //bez www a https
const int httpsPort = 443;

// Informacie o stranke, zobrazit certifikat (posledny/predposledny riadok)
// SHA1 odtlacok certifikatu
const char* fingerprint = "CF 05 98 89 CA FF 8E D8 5E 5C E0 C2 E4 F7 E6 C3 C7 50 DD 5C";

void setup() {
   pinMode(led, OUTPUT);
  Serial.begin(115200);
  Serial.println();
  Serial.print("pripajam sa na ");
  Serial.println(ssid);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("Pripojeny na wifi");
  Serial.println("IP adresa: ");
  Serial.println(WiFi.localIP());

  
}

void loop() {

// Pouzijeme WiFiClientSecure triedu na vytvorenie TLS pripojenia
  WiFiClientSecure client;
  Serial.print("connecting to ");
  Serial.println(host);
  if (!client.connect(host, httpsPort)) {
    Serial.println("connection failed");
    return;
  }

  if (client.verify(fingerprint, host)) {
    Serial.println("certifikat sedi");
  } else {
    Serial.println("certifikat nesedi");
  }

  String url = "/PHP/rele1.txt";
  Serial.print("requesting URL: ");
  Serial.println(url);

  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "User-Agent: NodeMCU \r\n" +
               "Connection: close\r\n\r\n");

  Serial.println("Request vykonany");
  while (client.connected()) {
    String line = client.readStringUntil('\n');
    if (line == "\r") {
      Serial.println("Hlavicka obdrzana");
      break;
    }
  }
  String line = client.readStringUntil('\n');
 if(line=="1"){
  
   digitalWrite(led, HIGH);   // zapni diodu
  
  }else if(line=="0"){
    
     digitalWrite(led, LOW);   // vypni diodu
    }else {
       Serial.println("Ina chyba");
      }
  Serial.println("Prichadzajuca odpoved:");
  Serial.println("==========");
  Serial.println(line);
  Serial.println("==========");
  Serial.println("zatvaram spojenie");
}
