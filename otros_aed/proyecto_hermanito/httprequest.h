#ifndef HTTPREQUEST_H
#define HTTPREQUEST_H

#include "URL.h"

/**
 * @class httpRequest
 * @brief Clase httpRequest
 * @details Manipula las cabeceras para hacer una petición a un servidor http.
 * @author José Valencia G.
 */
namespace SWSE
{
class httpRequest
{
public:
  /**
  * @brief Constructor por default
  */
    httpRequest();
    /**
     * @brief Constructor
     * @param url URL a la que se hará la petición
     */
    httpRequest(URL & url);
    /**
     * @brief Cambia la URL del request.
     * @param val Nueva URL.
     */
    void setURL(URL val){m_url = val;}
    /**
     * @brief Envia la petición en el socket
     * @param socket Socket conectado al servidor http
     */
    void WriteSocket(socket_t & socket);
    /**
     * @brief Agrega una cabecera a la peticion.
     * @code
     *  request.AddHeader("If-Modified-Since","Sat, 09 Jul 2000 19:21:28 GMT");
     * @endcode
     * @param name
     * @param val
     */
    void AddHeader(std::string name,std::string val);
    /**
     * @brief Genera los datos minimos para un request http
     */
    void init();

    URL* getURL()
    {
      return &m_url;
    }

    friend std::ostream & operator<<(std::ostream & os, httpRequest* req);
private:
    /// Dirección a la que se hará la solicitud.
    URL m_url;
    std::string method;
    mapstrstr attributes;

};
}//namespace SWSE
#endif // HTTPREQUEST_H
