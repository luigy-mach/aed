#ifndef HTTPHEADER_H
#define HTTPHEADER_H

#include "types.h"

/**
 * @class httpHeader
 * @brief clase httpHeader
 * @details Maneja los header de una respuesta http de un servidor.
 * @author José Valencia G.
 */
namespace SWSE
{
  class httpHeader
  {
  public:
    httpHeader();//<Constructor
    /**
     * @brief Construye el httpheader apartir de el buffer que contiene lo que se ha leido de el
     *  socket que esta conectado al servidor web.
     * @param buf Bufer con el header
     */
    httpHeader(boost::asio::streambuf & buf);
    /**
     * @brief Obtiene el valor de un atributo de el header
     * @param attrName  Nombre de el atributo
     * @return Valor de el atributo
     */
    std::string getAttr(std::string attrName);
    /**
     * @brief Procesa el bufer para obtener los atributos
     * @param buf   Bufer con el header
     */
    void processHeader(boost::asio::streambuf & buf);
  private:
    /// @brief Mapea los atributos de el header con sus valores.
    mapstrstr attributes;

    /**
 * @brief Escribe el contenido de el objeto en un flujo de salida.
 * @param os  flujo salida
 * @param h Objeto a imprimir
 * @return Referencia al flujo.
 */
    friend std::ostream & operator<<(std::ostream & os,httpHeader &h);

  };
}//namespace SWSE
#endif // HTTPHEADER_H
