#include "AntaresESP8266HTTP.h"

#define ACCESSKEY "fill"
#define WIFISSID "glenn"
#define PASSWORD "123login"

#define projectName "fill"
#define deviceName "fill"

AntaresESP8266HTTP antares(ACCESSKEY);

void setup() {
  Serial.begin(9600);
  antares.setDebug(true);
  antares.wifiConnection(WIFISSID,PASSWORD);
  pinMode(D4,OUTPUT);
}

void loop() {
  antares.get(projectName, deviceName); // Store latest value in buffer
  if(antares.getSuccess()) {
    int status = antares.getInt("status");
      if (status==1)
      {
        digitalWrite(D4,HIGH);
      }
      else
      {
        digitalWrite(D4,LOW);
      }
    }
  delay(10000);
}
