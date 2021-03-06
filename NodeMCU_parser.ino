//Autor: Martin Chlebovec alias: martinius96
//Podpora: https://www.paypal.me/Chlebovec
//Osobný web: https://arduino.php5.sk
//Email kontakt: martinius96@gmail.com
//Facebook ID kontakt: 100001242570317
//Používajte v súhlade s licenciou!  
#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
int rele = 16; //PIN D0 na NODEMCU
const char* ssid = "wifimeno";
const char* password = "wifiheslo";

const char* host = "arduino.php5.sk"; //bez www a https
const int httpsPort = 443;

// Informacie o stranke, zobrazit certifikat (posledny/predposledny riadok)
// SHA1 odtlacok certifikatu
const char* fingerprint = "13 9f 87 1d b1 85 be e6 bd 73 c1 8d 04 63 58 99 f0 32 43 92";

void setup() {
   pinMode(rele, OUTPUT);
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

  String url = "/rele/rele1.txt";
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
  
   digitalWrite(rele, HIGH);   // zapni diodu
  
  }else if(line=="0"){
    
     digitalWrite(rele, LOW);   // vypni diodu
    }else {
       Serial.println("Nepodporovana premenna");
      }
  Serial.println("Prichadzajuca odpoved:");
  Serial.println("==========");
  Serial.println(line);
  Serial.println("==========");
  Serial.println("zatvaram spojenie");
}
