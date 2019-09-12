#include <SoftwareSerial.h>

//Create software serial object to communicate with SIM900
SoftwareSerial mySerial(9,10); //SIM900 Tx & Rx is connected to Arduino #7 & #8

void setup()
{
  //Begin serial communication with Arduino and Arduino IDE (Serial Monitor)
  Serial.begin(9600);
  
  //Begin serial communication with Arduino and SIM900
  mySerial.begin(9600);

  Serial.println("Initializing..."); 
  delay(1000);
  mySerial.println("AT"); //Handshaking with SIM900
  updateSerial();
  
  
  mySerial.println("ATD+ +919973073465;"); //  change ZZ with country code and xxxxxxxxxxx with phone number to dial
  updateSerial();
  delay(1000); // wait for 10 seconds...
  mySerial.println("ATH"); //hang up
  updateSerial();
}

void loop()
{
}

void updateSerial()
{
  delay(500);
  while (Serial.available()) 
  {
    mySerial.write(Serial.read());//Forward what Serial received to Software Serial Port
      Serial.println("lizing..."); 

  }
  while(mySerial.available()) 
  {
    Serial.write(mySerial.read());//Forward what Software Serial received to Serial Port
  }
}
