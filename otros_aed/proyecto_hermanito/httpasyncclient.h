#ifndef HTTPASYNCCLIENT_H
#define HTTPASYNCCLIENT_H

#include "types.h"

#include "httpresponse.h"

namespace SWSE
{
  class httpRequest;
  /*class httpExeption
{
private:
  std::string what;
public:
};*/

  using boost::asio::ip::tcp;
  /**
 * @brief Clase httpAsyncClient, Cliente http asíncrono.
 *  Realiza el procedimiento de conexión al servidor http y reception de los datos solicitados.
 * @class httpAsyncClient
 */
  class httpAsyncClient
  {
  public:
    /**
   * @brief Constructor.
   * Inicializa el socket y el resolvedor de direcciones con un io_service, y recibe el request que se
   * enviara al servidor http, ademas inicia las operaciones asincronas resolviedo la dirección de el host
   * proveido por el request.
   * @param io_service para realizar operaciones asincronas.
   * @param req Request a ser enviado al servidor http, que ademas contiene a URL que se va ha descargar.
   */
    httpAsyncClient(boost::asio::io_service & io_service,httpRequest* req);
    /**
   * @brief Obtiene el objeto Response que contiene los datos recibidos de el servidor.
   * @return httpResponse Objeto con datos recibidos de el servidor.
   */
    httpResponse* getResponse(){return ptr_response;}
    //void start();
    /**
   * @brief Destructor.
   */
    virtual ~httpAsyncClient();
  private:
    /**
   * @brief Realiza la conexión con el servidor.
   * Manejador de los errores origindos en la resolución la dirección, conecta el socket al resolver iterator.
   * @param err Código de error devuelto por el procedimiento de resolución.
   * @param endpoint_iterator Iterador de direciones válidas encontradas.
   */
    void handle_resolve(const boost::system::error_code& err,
                        tcp::resolver::iterator endpoint_iterator);
    /**
   * @brief Envía el request al servidor.
   * Manejador de los errores originados en la conexión, escribe el request en el socket.
   * @param err Código de error devuelto por el procedimiento conexión.
   */
    void handle_connect(const boost::system::error_code& err);
    /**
   * @brief Lee la linea de estado recibidos por el servidor.
   * Manejador de los errores originados en el envío del request. Lee los datos de estado iniciales
   * de la respuesta de el servidor.
   * @param err Código de error devuelto por el procedimiento de envío del request.
   */
    void handle_write_request(const boost::system::error_code& err);
    /**
   * @brief Lee la cabezera http recibida de el servidor.
   * Manejador de los errores originados en la lectura del código de estado. Lee la
   * cabezera HTTP enviada como parte de el response del servidor.
   * @param err Código de error devuelto por el procedimiento de lectura del código de estado.
   */
    void handle_read_status_line(const boost::system::error_code& err);
    /**
   * @brief Inicia la lectura de el contenido.
   *Manejador de los errores originados en la lectura de la cabezera. Inicia la lectura de el cuerpo del
   *response.
   * @param err Código de error devuelto por el procedimiento de lectura de la cabecera.
   */
    void handle_read_headers(const boost::system::error_code& err);
    /**
   * @brief Lee el contenido del cuerpo del request.
   *Lee iterativamente los datos del contenido, Maneja los errores originados por la lectura anterior.
   * @param err Código de error devuelto por el procedimiento de lectura de contenido anterior.
   * @param tam Tamaño de la lectura anterior.
   */
    void handle_read_content(const boost::system::error_code& err,size_t tam);

    ///Resolvedor de las direcciones web.
    resolver_t resolver_;
    ///Socket de coneccion.
    socket_t socket_;
    ///Request enviado al servidor.
    httpRequest* ptr_request;
    ///Respuesta recibida de el servidor.
    httpResponse * ptr_response;
    ///Buffer de lectura de datos.
    streambuffer response_;
  };
}//namespace SWSE
#endif // HTTPASYNCCLIENT_H
