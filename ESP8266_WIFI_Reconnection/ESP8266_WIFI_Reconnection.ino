#include <ESP8266WiFi.h>


// Check WIFI Reconnect Auto
const char* ssid_Recon_WIFI = "WIFI Name";
const char* password_Recon_WIFI = "WIFI Password";

WiFiEventHandler wifiConnectHandler;
WiFiEventHandler wifiDisconnectHandler;


   void initWiFi() {
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid_Recon_WIFI,  password_Recon_WIFI);
    Serial.print("connect to WiFi ..");
    while (WiFi.status() != WL_CONNECTED) {
      Serial.println('.');
      delay(1000);
    }
    Serial.println(" ");
    Serial.println(WiFi.localIP());
  }

  //WIFI Connection Success
  void onWifiConnect(const WiFiEventStationModeGotIP& event) {
    Serial.println(" ");
    Serial.print("Connected to WIFI : ");
    Serial.print(ssid_Recon_WIFI);
    Serial.print(" Sucessfully.");
    Serial.println(" ");
    Serial.print("IP address: ");
    Serial.print(WiFi.localIP());
  }

  //WIFI Reconect & Conecting
  void onWifiDisconnect(const WiFiEventStationModeDisconnected& event) {
    Serial.println(" ");
    Serial.print("Reconnect WIFI : ");
    Serial.print(ssid_Recon_WIFI);
    WiFi.disconnect();
    WiFi.begin(ssid_Recon_WIFI,  password_Recon_WIFI);
  }


void setup() {
  Serial.begin(115200);
  
  //Register event handlers
  wifiConnectHandler = WiFi.onStationModeGotIP(onWifiConnect);
  wifiDisconnectHandler = WiFi.onStationModeDisconnected(onWifiDisconnect);
   
  initWiFi();
  Serial.print("RRSI: ");
  Serial.println(WiFi.RSSI());
}

void loop() { 

}
