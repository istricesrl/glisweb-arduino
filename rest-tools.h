/**
 * libreria per lavorare con le API REST
 * 
 * v0.1.2 - 16/03/2025
 * 
 * 
 */

#ifndef REST_TOOLS_H
#define REST_TOOLS_H

/**
 * questa funzione fa una chiamata GET a un dato endpoint
 * 
 * TODO deve restituire la stringa del body della risposta
 * 
 */
void restGet(WiFiSSLClient connection, const char* api, int port, const char* service) {

    Serial.print("Mi connetto a ");
    Serial.println(api);
  
    if (!connection.connect(api, port)) {
      Serial.println("Connessione fallita");
      return;
    }
  
    connection.print("GET " + String(service) + " HTTP/1.1\r\n" +
                     "Host: " + api + "\r\n" +
                     "Connection: close\r\n\r\n");
  
    while (connection.connected()) {
      while (connection.available()) {
        char c = connection.read();
        Serial.print(c);
      }
    }
  
  }

#endif
