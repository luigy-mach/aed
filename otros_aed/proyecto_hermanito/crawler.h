#ifndef CRAWLER_H
#define CRAWLER_H
/**
 * @file crawler.h
 * Contiene la definición de la clase Crawler.
 * @author Jose L. Valencia G.
 * @date 04/12/2012
 */

#include "urlregister.h"
#include "types.h"


/**
 * @class Crawler
 * @brief Clase Crawler, Administra la descarga del contenido.
 *  Tiene la cola de URL's a ser obenidas, alimentadas por los URL's de las páginas ya descargadas.
 * @todo Paralelizar el crawler
 */
namespace SWSE
{
  class Crawler
  {
  public:
    /**
     * @brief Constructor por default.
     */
    Crawler();
    /**
     * @brief Encola una URL representada por un string.
     * @param String de la URL.
     */
    void queueURL(URLhash_t);
    /**
     * @brief Inicia el Crawler.
     * @return Estado con el que termina el pograma.
     */
    int run();
    /**
     * @brief Detiene el crawler.
     * Cambia la variable de control ON a false para detener el crawler correctamente.
     */
    void turnOff();
    /**
     * @brief PopURL obtiene la siguiente url de la cola.
     * @param t variable donde se guardara la url obtenida
     * @return true si es obtuvo algo, en caso contrario false
     */
    bool PopURL(URLhash_t & t);

    /**
     * @brief isON Verifica si el crawler esta en ejecución.
     * @return true si esta en ejecución.
     */
    inline bool isON(){return ON;}
    /**
     * @brief saveQueue Guarda la cola.
     */
    void saveQueue();
    /**
     * @brief carga la cola desde archivo.
     */
    void loadQueue();
    /**
     * @brief Obtiene el puntero al objeto de registro.
     * @return Puntero al Registro de urls
     */
    URLregister & getRegister(){return m_urlregist;}
    /// Contador de coneciones;
    long int conneciones;

  private:
    ///Cola de URL's, soporta concurrencia.
    URLqueue_t urlQueue;
    ///Pool de threads.
    PoolThread_t poolThread;
    ///Variable de control para detener el crawler.
    bool ON;
    ///Tamaño de la cola.
    size_t TamCola;
    ///Registro de urls
    URLregister m_urlregist;
    ///Numero de hilos corriendo.
    size_t NumThreads;
  };
}//namespace SWSE
#endif // CRAWLER_H
