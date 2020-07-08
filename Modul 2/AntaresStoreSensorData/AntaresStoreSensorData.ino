#include "DHT.h"
#include "AntaresESP8266HTTP.h"
#define DHTPIN D3
#define DHTTYPE DHT11

#define ACCESSKEY "fill"
#define WIFISSID "glenn"
#define PASSWORD "123login"

#define projectName "fill"
#define deviceName "fill"

AntaresESP8266HTTP antares(ACCESSKEY);
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("DHTxx test!");
  dht.begin();
  antares.setDebug(true);
  antares.wifiConnection(WIFISSID,PASSWORD);
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  antares.add("temperature", t);
  antares.add("humidity", h);
  antares.send(projectName, deviceName);
  delay(10000);
}
