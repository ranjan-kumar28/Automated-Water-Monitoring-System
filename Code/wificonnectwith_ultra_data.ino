#include "ThingSpeak.h"
#include <WiFi.h>
//#include "Adafruit_CCS811.h"
 
char ssid[] = "Galaxy S9"; // your network SSID (name)
char pass[] = "ujcj7403"; // your network password
//int keyIndex = 0; // your network key Index number (needed only for WEP)
//WiFiClient client;
 
unsigned long myChannelNumber = 774309;
const char * myWriteAPIKey = "DH56JRYGOPYZ0XZV";
const int trigPin = 25;
const int echoPin = 26;

long duration;
int distance; 
 
void setup() {
  Serial.begin(115200);         // Start the Serial communication to send messages to the computer
  delay(10);
  Serial.println('\n');
  
  WiFi.begin(ssid, password);             // Connect to the network
  Serial.print("Connecting to ");
  Serial.print(ssid);
 
  while (WiFi.status() != WL_CONNECTED) { // Wait for the Wi-Fi to connect
    delay(500);
    Serial.print('.');
  }
 
  Serial.println('\n');
  Serial.println("Connection established!");  
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP());         // Send the IP address of the ESP8266 to the computer
}
 
void loop() { 
  digitalWrite(trigPin, LOW);
delayMicroseconds(2);

digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;

Serial.print("Distance: ");
Serial.println(distance);

  
}
