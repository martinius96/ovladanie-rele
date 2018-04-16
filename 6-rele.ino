#include <SPI.h>
#include <Ethernet.h>
const int svetlo1 = 3;
const int svetlo2 = 5;
const int svetlo3 = 6;
const int zasuvka1 = 7;
const int zasuvka2 = 8;
const int zasuvka3 = 9;
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED }; //fyzicka adresa MAC
char serverName[] = "www.arduino.php5.sk"; // webserver
IPAddress ip(192, 168, 2, 40);
EthernetClient client;
String readString;
int x=0; //pocitadlo riadkov
char lf=10; //line feed character
void setup(){
pinMode(svetlo1, OUTPUT);
pinMode(svetlo2, OUTPUT);
pinMode(svetlo3, OUTPUT);
pinMode(zasuvka1, OUTPUT);
pinMode(zasuvka2, OUTPUT);
pinMode(zasuvka3, OUTPUT);

  Serial.begin(9600); 
}
void zisti_svetlo1(){
if (client.connect(serverName, 80)) {  //starts client connection, checks for connection
    Serial.println("connected");
    client.println("GET /6rele/rele1.txt HTTP/1.1"); //download text
    client.println("Host: www.arduino.php5.sk");
    client.println("Connection: close");  //close 1.1 persistent connection  
    client.println(); //end of get request
  } 
  else {
    Serial.println("Pripojenie neuspesne - svetlo1"); //chyba ak nie som pripojeny
    Serial.println();
  }
  while(client.connected() && !client.available()) delay(1); //cakaj na data
  while (client.connected() || client.available()) { //pramenna
    char c = client.read(); //dostan bity z buffera
    Serial.print(c); //cela http hlavicka
    if (c==lf) x=(x+1); //pocitaj 
    else if (x==12) readString += c;
   } 
    Serial.println("Premenna: "); 
    Serial.println(readString); //nasa premenna
if(readString=="ZAP"){
  digitalWrite(svetlo1, LOW); 
   Serial.println("Svetlo 1 zapnute");
  }else if(readString=="VYP"){
  digitalWrite(svetlo1, HIGH); 
   Serial.println("Svetlo 1 vypnute");
    }
    else{
 Serial.println("Nepodporovana premenna - svetlo 1.");
 }  
  readString = (""); //vynuluj premennu
  x=0; //riadky na 0
  client.stop(); //ukonc spojenie
  }
  void zisti_svetlo2(){
if (client.connect(serverName, 80)) {  //starts client connection, checks for connection
    Serial.println("connected");
    client.println("GET /6rele/rele2.txt HTTP/1.1"); //download text
    client.println("Host: www.arduino.php5.sk");
    client.println("Connection: close");  //close 1.1 persistent connection  
    client.println(); //end of get request
  } 
  else {
    Serial.println("Pripojenie neuspesne - svetlo2"); //chyba ak nie som pripojeny
    Serial.println();
  }
  while(client.connected() && !client.available()) delay(1); //cakaj na data
  while (client.connected() || client.available()) { //pramenna
    char c = client.read(); //dostan bity z buffera
    Serial.print(c); //cela http hlavicka
    if (c==lf) x=(x+1); //pocitaj 
    else if (x==12) readString += c;
   } 
    Serial.println("Premenna: "); 
    Serial.println(readString); //nasa premenna
if(readString=="ZAP"){
  digitalWrite(svetlo2, LOW); 
   Serial.println("Svetlo 2 zapnute");
  }else if(readString=="VYP"){
  digitalWrite(svetlo2, HIGH); 
   Serial.println("Svetlo 2 vypnute");
    }
    else{
 Serial.println("Nepodporovana premenna - svetlo 2.");
 }  
  readString = (""); //vynuluj premennu
  x=0; //riadky na 0
  client.stop(); //ukonc spojenie
  }
  void zisti_svetlo3(){
if (client.connect(serverName, 80)) {  //starts client connection, checks for connection
    Serial.println("connected");
    client.println("GET /6rele/rele3.txt HTTP/1.1"); //download text
    client.println("Host: www.arduino.php5.sk");
    client.println("Connection: close");  //close 1.1 persistent connection  
    client.println(); //end of get request
  } 
  else {
    Serial.println("Pripojenie neuspesne - svetlo3"); //chyba ak nie som pripojeny
    Serial.println();
  }
  while(client.connected() && !client.available()) delay(1); //cakaj na data
  while (client.connected() || client.available()) { //pramenna
    char c = client.read(); //dostan bity z buffera
    Serial.print(c); //cela http hlavicka
    if (c==lf) x=(x+1); //pocitaj 
    else if (x==12) readString += c;
   } 
    Serial.println("Premenna: "); 
    Serial.println(readString); //nasa premenna
if(readString=="ZAP"){
  digitalWrite(svetlo3, LOW); 
   Serial.println("Svetlo 3 zapnute");
  }else if(readString=="VYP"){
  digitalWrite(svetlo3, HIGH); 
   Serial.println("Svetlo 3 vypnute");
    }
    else{
 Serial.println("Nepodporovana premenna - svetlo 3.");
 }  
  readString = (""); //vynuluj premennu
  x=0; //riadky na 0
  client.stop(); //ukonc spojenie
  }
    void zisti_zasuvka1(){
if (client.connect(serverName, 80)) {  //starts client connection, checks for connection
    Serial.println("connected");
    client.println("GET /6rele/rele4.txt HTTP/1.1"); //download text
    client.println("Host: www.arduino.php5.sk");
    client.println("Connection: close");  //close 1.1 persistent connection  
    client.println(); //end of get request
  } 
  else {
    Serial.println("Pripojenie neuspesne - zasuvka 1"); //chyba ak nie som pripojeny
    Serial.println();
  }
  while(client.connected() && !client.available()) delay(1); //cakaj na data
  while (client.connected() || client.available()) { //pramenna
    char c = client.read(); //dostan bity z buffera
    Serial.print(c); //cela http hlavicka
    if (c==lf) x=(x+1); //pocitaj 
    else if (x==12) readString += c;
   } 
    Serial.println("Premenna: "); 
    Serial.println(readString); //nasa premenna
if(readString=="ZAP"){
  digitalWrite(zasuvka1, LOW); 
   Serial.println("Zasuvka 1 zapnuta");
  }else if(readString=="VYP"){
  digitalWrite(zasuvka1, HIGH); 
   Serial.println("Zasuvka 1 vypnuta");
    }
    else{
 Serial.println("Nepodporovana premenna - zasuvka 1");
 }  
  readString = (""); //vynuluj premennu
  x=0; //riadky na 0
  client.stop(); //ukonc spojenie
  }
   void zisti_zasuvka2(){
if (client.connect(serverName, 80)) {  //starts client connection, checks for connection
    Serial.println("connected");
    client.println("GET /6rele/rele5.txt HTTP/1.1"); //download text
    client.println("Host: www.arduino.php5.sk");
    client.println("Connection: close");  //close 1.1 persistent connection  
    client.println(); //end of get request
  } 
  else {
    Serial.println("Pripojenie neuspesne - zasuvka 2"); //chyba ak nie som pripojeny
    Serial.println();
  }
  while(client.connected() && !client.available()) delay(1); //cakaj na data
  while (client.connected() || client.available()) { //pramenna
    char c = client.read(); //dostan bity z buffera
    Serial.print(c); //cela http hlavicka
    if (c==lf) x=(x+1); //pocitaj 
    else if (x==12) readString += c;
   } 
    Serial.println("Premenna: "); 
    Serial.println(readString); //nasa premenna
if(readString=="ZAP"){
  digitalWrite(zasuvka2, LOW); 
   Serial.println("Zasuvka 2 zapnuta");
  }else if(readString=="VYP"){
  digitalWrite(zasuvka2, HIGH); 
   Serial.println("Zasuvka 2 vypnuta");
    }
    else{
 Serial.println("Nepodporovana premenna - zasuvka 2.");
 }  
  readString = (""); //vynuluj premennu
  x=0; //riadky na 0
  client.stop(); //ukonc spojenie
  }
    void zisti_zasuvka3(){
if (client.connect(serverName, 80)) {  //starts client connection, checks for connection
    Serial.println("connected");
    client.println("GET /6rele/rele6.txt HTTP/1.1"); //download text
    client.println("Host: www.arduino.php5.sk");
    client.println("Connection: close");  //close 1.1 persistent connection  
    client.println(); //end of get request
  } 
  else {
    Serial.println("Pripojenie neuspesne - zasuvka 3"); //chyba ak nie som pripojeny
    Serial.println();
  }
  while(client.connected() && !client.available()) delay(1); //cakaj na data
  while (client.connected() || client.available()) { //pramenna
    char c = client.read(); //dostan bity z buffera
    Serial.print(c); //cela http hlavicka
    if (c==lf) x=(x+1); //pocitaj 
    else if (x==12) readString += c;
   } 
    Serial.println("Premenna: "); 
    Serial.println(readString); //nasa premenna
if(readString=="ZAP"){
  digitalWrite(zasuvka3, LOW); 
   Serial.println("Zasuvka 3 zapnuta");
  }else if(readString=="VYP"){
  digitalWrite(zasuvka3, HIGH); 
   Serial.println("Zasuvka 3 vypnuta");
    }
    else{
 Serial.println("Nepodporovana premenna - zasuvka 2.");
 }  
  readString = (""); //vynuluj premennu
  x=0; //riadky na 0
  client.stop(); //ukonc spojenie
  }
void loop(){

if (Ethernet.begin(mac) == 0) {
    Serial.println("Nepodarilo sa nastavit IP cez DHCP - nastavujem staticku IP");
    Ethernet.begin(mac, ip);
    delay(200);
  }
zisti_svetlo1();
zisti_svetlo2();
zisti_svetlo3();
zisti_zasuvka1();
zisti_zasuvka2();
zisti_zasuvka3();
delay(1000); //pockaj sekundu pred novou sluckou
} 
