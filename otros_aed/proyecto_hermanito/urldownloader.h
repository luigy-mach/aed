#ifndef URLDOWNLOADER_H
#define URLDOWNLOADER_H

#include "httpheader.h"
#include "crawler.h"
#include "parser.h"
#include "httprequest.h"
#include "urlresolverclient.h"

#include "types.h"

namespace SWSE
{
  class Parser;

  /**
 * @class URLDownloader
 * @brief Clase URLDownloader, Ejecuta la descarga de la URL.
 *Maneja el cliente http a ser usado, y parsea los datos recibidos.
 */
  class URLDownloader
  {
  public:
    /**
   * @brief Constructor por default.
   */
    URLDownloader();
    /**
   * @brief Constructor a partir de un obejo URL.
   * @param url URL a ser descargada.
   * @param cr puntero al crawler creador.
   */
    URLDownloader(Crawler * cr = 0 );
    /**
   * @brief Constructor a apatir del string de una URL.
   * @param url String del URL a ser descargado.
   * @param cr puntero al crawler creador.
   */
    URLDownloader(URLstr_t url,Crawler * cr = 0);
    /**
   * @brief Pone a la cola de el crawler los URL encontrados en la página descargada.
   */
    void queueURLlist();
    /**
   * @brief Inicia la ejcución de las descargas.
   */
    void operator()();
    virtual ~URLDownloader();
  private:
    /// URL a ser descargada.
    URL m_url;
    /// Request enviado al servidor.
    httpRequest m_request;
    /// Datos recibidos.
    Data_t m_data;
    /// Puntero al crawler para acceder a la cola.
    Crawler * ptr_crawler;
    /// Objeto parser que obtiene las url de el documento y obtiene las palabras para ser indexadas.
    ID m_id;

    Parser parser;

    URLResolverClient* rc;

    static ID threadid;
  };
}//namespace SWSE
#endif // URLDOWNLOADER_H
