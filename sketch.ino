#include <WiFi.h>
#include <WebServer.h>
#include <ArduinoJson.h>

const char* ssid     = "wifi_ssid";
const char* password = "wifi_password";

WebServer server(80);

void connectToWiFi() {
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    Serial.println("Connecting to WiFi...");
    delay(5000);
  }

  Serial.println("Connected to WiFi.");
  Serial.print("Local IP Address: ");
  Serial.println(WiFi.localIP());
}

void handlePing() {
  StaticJsonDocument<200> jsonDoc;
  
  jsonDoc["message"] = "hello from arduino!";
  
  String response;
  serializeJson(jsonDoc, response);

  server.send(200, "application/json", response);
}

void setup()  {
  Serial.begin(9600);

  connectToWiFi();

  server.on("/ping", HTTP_GET, handlePing);

  server.begin();
  Serial.println("Server listening on port 80...");
}

void loop() {
  server.handleClient();
}