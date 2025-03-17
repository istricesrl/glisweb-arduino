/**
 * libreria per la generazione di codice HTML
 *
 * v0.1.2 - 16/03/2025
 * 
 * 
 */

// librerie per le mappe
#include <unordered_map>
#include <map>

// libreria per le stringhe
#include <string>

// crea un tag doctype
std::string stampaDocType(const std::string& type) {

    // mappa dei MIME types senza "Content-Type: "
    std::unordered_map<std::string, std::string> docTypes = {
        {"html5", "html"}
    };

    // controlla se il MIME type è presente nella mappa
    auto it = docTypes .find(type);

    // se il mime type esiste, restituisce la riga Content-Type corrispondente
    if (it != docTypes .end()) {
        return "<!DOCTYPE " + it->second + ">";
    }

    // valore di default
    return "";

}

// crea un tag html
std::string creaTagHTML(const std::string& tagName, const std::map<std::string, std::string>& attributes, const std::string& content) {

    // apertura del tag
    std::string tag = "<" + tagName;

    // aggiunge gli attributi, se presenti
    for (const auto& attr : attributes) {
        tag += " " + attr.first;
        if( attr.second != "" ) {
          tag += "=\"" + attr.second + "\"";
        }
    }

    // chiude il tag
    tag += ">";

    // se c'è contenuto lo aggiunge e chiude il tag
    if( content != "" ) {
      tag += content + "</" + tagName + ">";
    }

    // valore di ritorno
    return tag;

}
