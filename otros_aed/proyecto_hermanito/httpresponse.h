#ifndef HTTPRESPONSE_H
#define HTTPRESPONSE_H

#include "types.h"
#include "httpheader.h"

namespace SWSE
{
  /**
 * \class httpResponse
 * @brief Clase httpResponse, Contiene los datos de una respuesta de un servidor en el protocolo http.
 *Organiza los datos de la respuesta de un servidor http en Header y Body.
 */
  class httpResponse
  {
  public:
    /**
   * @brief Constructor por default
   */
    httpResponse(){}
    /**
   * @brief Obtiene versión de el protocolo http.
   * @return Referencia a la variable del protocolo http.
   */
    std::string & HTTPversion(){return http_version;}
    /**
   * @brief Obtiene el codigo de estado del response.
   * @return Referencia a la variable del código de estado.
   */
    httpStatusC & HTTPstatusCode(){return status_code;}
    /**
   * @brief Obtiene el mesage http.
   * @return Referencia a la variable del mensaje http.
   */
    std::string & HTTPmessage(){return status_message;}

    /**
   * @brief Obtiene la cabezera de la respuesta.
   * @return Referencia al objeto Cabezera.
   */
    httpHeader & Header(){return m_header;}
    /**
   * @brief Obtiene el cuerpo de la respuesta.
   * @return Referencia a los datos de el cuerpo de la respuesta.
   */
    Data_t & Body(){return m_body;}

    /**
   * @brief Cambia la cabezara.
   * @param Objeto cabezera nuevo.
   */
    void setHeader(streambuffer & buf)
    {
      m_header.processHeader(buf);
    }

  private:
    ///Version de el protocolo http usado.
    std::string http_version;
    ///Codigo de estado de la respuesta de el servidor.
    httpStatusC status_code;
    ///Mensaje de estado http.
    std::string status_message;

    ///Objeto de la cabecera http.
    httpHeader m_header;
    ///Datos de el cuerpo de la respuesta.
    Data_t  m_body;
  };
}//namespace SWSE
#endif // HTTPRESPONSE_H
