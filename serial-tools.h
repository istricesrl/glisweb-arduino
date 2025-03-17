/**
 * libreria per la gestione ottimizzata della console seriale
 *
 * v0.0.2 - 16/03/2025
 *
 *
 *
 *
 */

#ifndef SERIAL_TOOLS_H
#define SERIAL_TOOLS_H

/**
 * questa funzione inizializza la comunicazione seriale
 */
void initSerial() {

    // inizializza la comunicazione seriale
    Serial.begin(9600);

    // connessione alla porta seriale
    while(!Serial);

    // debug
    Serial.println("connesso alla porta seriale");

}

#endif
