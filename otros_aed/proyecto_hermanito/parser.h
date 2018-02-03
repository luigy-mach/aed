#ifndef PARSER_H
#define PARSER_H
/**
 * @class Parser
 * @brief Clase Parser
 * @details Esta clase elimina todos los tags html y retorna texto plano
 * @author Jose Miguel Huaman Cruz josemiki24@gmail.com
 */

#include "types.h"
#include "crawleddataprocessor.h"
#include "urlresolverclient.h"
namespace SWSE
{
  class URL;
  class Crawler;
  class httpResponse;
  //class URLResolverClient;

  class Parser
  {
  private:
    /// @brief Almacena la expresion regular que remueve los tags html  <...></...>
    boost::regex reg_word_tag;
    /// @brief Almacena la expresion regular que remueve <script>...</script>
    boost::regex reg_word_script;
    /// @brief Almacena la expresion regular que remueve <style>...</style>
    boost::regex reg_word_style;
    /// @brief Almacena la expresion regular que remueve cualquier caracter diferente a [a-zA-Z0-9_]
    boost::regex reg_word;

    //std::vector<boost::regex> regexList;

    Crawler * ptr_crawler;
    URLResolverClient * urlResolver;

  public:
    /**
     * @brief Builds Class Parser and assigns regex to data members.
     */
    Parser(Crawler * c = 0,ID id = 0);
    /**
     * @brief Take string input and remove all tags html
     * @param URL_str String containing an html page
     * @return Plain text
     */
    URLstr_t& to_plain_text(URLstr_t &str);
    /**
     * @brief Take string input and return link list
     * @param URL_str String containing an html page
     */
    size_t get_links(Data_t& str, URL& url);

    void setURLResolverClient(URLResolverClient * rc){urlResolver = rc;}

    void saveData(URLhash_t& h,Data_t& d );

    void run(httpResponse * resp,URL & url,URLhash_t& hash);
    virtual ~Parser();
    std::string genFileName();
    CrawledDataProcessor* cdp;
  };
}//namespace SWSE
#endif // PARSER_H
