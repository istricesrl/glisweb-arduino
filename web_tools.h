/**
 * 
 * 
 * 
 */

// librerie per le mappe
#include <unordered_map>
#include <map>

// libreria per le stringhe
#include <string>

// invia il codice di stato HTTP
std::string stampaCodiceStatoHTTP(int codice) {

    // mappa dei codici di stato HTTP
    std::unordered_map<int, const char*> codiciHTTP = {
        {200, "200 OK"},
        {201, "201 Created"},
        {204, "204 No Content"},
        {400, "400 Bad Request"},
        {401, "401 Unauthorized"},
        {403, "403 Forbidden"},
        {404, "404 Not Found"},
        {500, "500 Internal Server Error"},
        {502, "502 Bad Gateway"},
        {503, "503 Service Unavailable"}
    };

    // controlla se il codice è presente nella mappa
    auto it = codiciHTTP.find(codice);

    // se il codice esiste
    if (it != codiciHTTP.end()) {

        // crea e restituisce la stringa con il formato richiesto
        return "HTTP/1.1 " + std::string(it->second);

    }

    // se il codice non è valido, restituisce un messaggio di errore
    return "HTTP/1.1 400 Bad Request";
}

// invia il mime type
std::string stampaContentType(const std::string& mimeType) {

    // mappa dei MIME types senza "Content-Type: "
    std::unordered_map<std::string, std::string> mimeTypes = {
        {"text/html", "text/html"},
        {"text/plain", "text/plain"},
        {"application/json", "application/json"},
        {"application/xml", "application/xml"},
        {"image/jpeg", "image/jpeg"},
        {"image/png", "image/png"},
        {"audio/mpeg", "audio/mpeg"},
        {"video/mp4", "video/mp4"},
        {"application/pdf", "application/pdf"},
        {"application/zip", "application/zip"}
    };

    // controlla se il MIME type è presente nella mappa
    auto it = mimeTypes.find(mimeType);

    // se il mime type esiste, restituisce la riga Content-Type corrispondente
    if (it != mimeTypes.end()) {
        return "Content-Type: " + it->second;
    }

    // valore di default
    return "Content-Type: application/octet-stream";

}

// crea un tag html
std::string creaTagHTML(const std::string& tagName, const std::string& content, const std::map<std::string, std::string>& attributes) {

    // apertura del tag
    std::string tag = "<" + tagName;

    // aggiunge gli attributi, se presenti
    for (const auto& attr : attributes) {
        tag += " " + attr.first + "=\"" + attr.second + "\"";
    }

    // aggiunge il contenuto e chiude il tag
    tag += ">" + content + "</" + tagName + ">";

    // valore di ritorno
    return tag;

}
