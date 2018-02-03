#ifndef CRAWLEDDATAPROCESSOR_H
#define CRAWLEDDATAPROCESSOR_H
/**
 * @file crawleddataprocessor.h
 *
 * @brief Contiene la definición la clase CrawledDataProcessor
 * @author José L. Valencia G.
 * @date 04/12/2012
 */

#include "types.h"
#include <fstream>
namespace SWSE
{
  /**
   * @brief Clase CrawledDataProcessor que procesa la data de la
   */
  class CrawledDataProcessor
  {
  public:
    /// Tamaño minimo de el buffer para la escritura.
    static size_t MinWriteSize;
    /**
     * @brief Constructor
     * @param fileName Nombre de el archivo donde se van a guardar los datos.
     */
    CrawledDataProcessor(std::string fileName);
    /**
     * @brief Agrega datos para la escritura
     * @param d Datos para ser guardados.
     */
    void save(Data_t && d);
    virtual ~CrawledDataProcessor();
  private:
    /// buffer
    Data_t m_data;
    /// archivo de salida.
    std::ofstream oFile;
  };
}//namespace SWSE
#endif // CRAWLEDDATAPROCESSOR_H
