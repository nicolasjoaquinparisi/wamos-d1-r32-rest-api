﻿# Arduino Wemos D1 R32 - REST API
 This project demonstrates how to create a basic REST API using an Arduino Wemos D1 R32, allowing you to interact with connected devices over a WiFi network.
 
# Requirements
- Arduino Wemos D1 R32
- WiFi connection with Internet access
- Arduino IDE or compatible development environment

# Setup
- Connect your Arduino Wemos D1 R32 to your WiFi network by editing the following lines in the code:
```cpp
const char* ssid     = "your_wifi_network_name";
const char* password = "your_wifi_network_password";
```
- Upload the code to your Arduino using the Arduino IDE.
- Open the serial monitor to verify the WiFi connection and the assigned local IP address.
