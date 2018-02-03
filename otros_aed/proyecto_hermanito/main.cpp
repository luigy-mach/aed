#include "crawler.h"
#include "signal.h"
#include <stdlib.h>
#include "urlresolverclient.h"

SWSE::Crawler * crawler_;

void abort_handler(int)
{
    //std::cout<<"\rEnding program ..."<<std::endl;
    //ON=false;
  crawler_->turnOff();
}

int main()
{
  signal(SIGINT, &abort_handler);
  //URLstr_t urlstr = "http://www.boost.org/doc/libs/1_49_0/libs/regex/doc/html/../../doc/html/index.html";
  //URLstr_t urlstr = "http://peru.com/actualidad/politicas/../";
  //URLstr_t url2 = "http://localhost/test/index.html";
  //URLstr_t url2 = "http://www.boost.org/doc/libs/1_49_0/libs/regex/doc/html/index.html";
  //URLstr_t url2 = "http://www.boost.org/doc/libs/1_49_0/libs/regex/doc/html/boost_regex/background_information/../";
  //URLstr_t url2 ="http://localhost/boost_1_52_0/libs/libraries.htm";
  //URLstr_t url2 ="http://localhost/boost_1_52_0/";
  //URLstr_t url2 ="http://www.boost.org/";
  SWSE::URLstr_t url2 ="http://elcomercio.pe/";
  //URLDownloader downloader(url2);
  //downloader();
  //downloader.getURLlist();
  SWSE::Crawler c;
  crawler_ = &c;
  c.loadQueue();
  boost::asio::io_service ios;
  SWSE::URLResolverClient rc(ios);
  rc.connect("localhost","1234");
  c.queueURL(rc.hash(url2));
  rc.close();
  ios.stop();
  c.run();
  return 0;
}

/**
 * @mainpage Buscador Web por similitud de texto
 * @author Rommel Anatoli Quintanilla Cruz
 * @author Jose Luis Valencia Gutierrez
 * @author José Miguel Huaman Cruz
 * @section intro_sec Introducción
 *  Este proyecto es desarrollado como trabajo final de el curso de Estructuras de Datos Avanzadas dictado por
 * el PhD Ernesto Cuadros Vargas en la Universidad Nacional de San Agustín.
 * @section arq_sec Arquitectura
 * ![Arquitectura de Alto Nivel](../../../../docs/Arquitectura_Alto_Nivel_SWSE.png "Diagrama de Arquitectura")
 */
