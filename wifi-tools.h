/**
 * libreria per semplificare la gestione del wifi
 * 
 * v0.0.2 - 16/03/2025
 * 
 * 
 * 
 */

#ifndef WIFI_TOOLS_H
#define WIFI_TOOLS_H

/**
 * questa funzione inizializza il wifi, dati ssid e password
 */
void initWiFi( const char* ssid, const char* pass ) {

  Serial.println("connessione a WiFi");

  WiFi.disconnect();

  WiFi.begin(ssid, pass);

  do {
    delay(1000);
    Serial.print(".");
  } while (WiFi.status() != WL_CONNECTED);

  Serial.println("WiFi connesso!");

  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

}

#endif
