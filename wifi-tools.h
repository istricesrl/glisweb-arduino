/**
 * libreria per semplificare la gestione del wifi
 * 
 * v0.0.1 - 16/03/2025
 * 
 * 
 * 
 */

/**
 * questa funzione inizializza il wifi, dati ssid e password
 */
void initWiFi( const char* ssid, const char* pass ) {

    Serial.print("connessione a WiFi " + String(ssid));
  
    if (WiFi.status() == WL_NO_MODULE) {
      Serial.println("comunicazione con il modulo WiFi fallita!");
    }
  
    if (String(WiFi.firmwareVersion()) < WIFI_FIRMWARE_LATEST_VERSION) {
      Serial.println("per favore aggiorna il firmware");
    }
  
    WiFi.begin(ssid, pass);
  
    while (WiFi.status() != WL_CONNECTED) {
      Serial.print(".");
      delay(500);
    }
  
    Serial.println("WiFi connesso!");
  
    Serial.print("SSID: ");
    Serial.println(WiFi.SSID());
  
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
  
  }
  