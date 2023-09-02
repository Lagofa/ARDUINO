  #include <ESP8266WiFi.h>
#include <ArduinoJson.h>
#include <ESP8266HTTPClient.h>
#include "config/config.h"

StaticJsonDocument<100> httpData;

void setup() {
  Serial.begin(115200);
  WiFi.begin(SSID, PASSWORD);
  initSensor();
  httpData["uuid"] = uuid;
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    WiFiClientSecure client;
    HTTPClient http;
    if (http.begin(client, URL)) {
      httpData["value"] = getValue();
      String httpDataJson = "";
      serializeJson(httpData, httpDataJson);
      client.setFingerprint(SSL_FINGERPRINT);
      http.addHeader("Content-Type", "application/json");
      http.POST(httpDataJson);
      Serial.println( URL + httpDataJson);

      http.end();
    }
  }
  delay(sensor_time);
}
