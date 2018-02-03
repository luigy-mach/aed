#include "parser.h"
#include <fstream>
#include <random>
#include "boost/date_time/posix_time/posix_time.hpp"

#include "crawler.h"
#include "URL.h"
#include "httpresponse.h"

namespace SWSE
{
Parser::Parser(Crawler * c,ID id)
  :ptr_crawler(c)
  ,cdp(new CrawledDataProcessor(genFileName()+std::to_string(id)))
{
  /*this->reg_word_tag=boost::regex ("<(.|\n)*?>");
  //    this->reg_word_sas=boost::regex ("(<(script|style).*>(.|\n)*?<\\/(script|style)>)*?");
  this->reg_word_script=boost::regex ("<script.*>.*<\\/script>");
  this->reg_word_style=boost::regex ("<style.*>.*<\\/style>");*/
  this->reg_word=boost::regex ("<\\s*script[^>]*>.*?<\\s*/\\s*script\\s*>|<\\s*style[^>]*>.*?<\\s*/\\s*style\\s*>|<[^>]*>|\\t|\\n|[^a-zA-ZñáéíóúÑÁÉÍÓÚüÜ\\s]");

}

void Parser::run(httpResponse * resp,URL & url,URLhash_t& hash)
{
  get_links(resp->Body(),url);
  Data_t data = to_plain_text(resp->Body());
  saveData(hash,data);
}

URLstr_t& Parser::to_plain_text(URLstr_t& str)
{
  /*str=boost::regex_replace(str, reg_word_script, "", boost::match_default | boost::format_all);
  str=boost::regex_replace(str, reg_word_style, "", boost::match_default | boost::format_all);
  str=boost::regex_replace(str, reg_word_tag, "", boost::match_default | boost::format_all);*/
  str=boost::regex_replace(str, reg_word, " ", boost::match_default | boost::format_all);
  boost::regex e1("\\s+");
  str=boost::regex_replace(str, e1, " ", boost::match_default | boost::format_all);
  std::transform(str.begin(), str.end(), str.begin(), ::tolower);
  return str;
}

size_t Parser::get_links(Data_t & m_data,URL &url)
{
  //"<\\s*meta\\s+[^>]*http-equiv\\s*=\\s*\"\\s*refresh\\s*\"\\s+[^>]*content=\"[^>]*;\\s+URL\\s*=([^>]*)\">"
  boost::regex e("<\\s*a\\s+[^>]*href\\s*=\\s*\"([^\"]*)\"",
                 boost::regex::normal | boost::regbase::icase);
    boost::regex sl("\\n");
  boost::sregex_token_iterator i(m_data.begin(), m_data.end(), e, 1);
  boost::sregex_token_iterator j;
  URLlist urls;
  while(i != j)
  {
    URLstr_t u = *i++;
    u = boost::regex_replace(u, sl, "", boost::match_default | boost::format_all);
    auto p = urls.insert(u);
    if(p.second)
      try
    {
      URLstr_t tmp = url.Rel2AbsPath(u);
      URLhash_t h = urlResolver->hash(tmp);
      ptr_crawler->queueURL(h);
    }
    catch(URLexception e){/*std::cerr<<"URL exception :"<<e.what()<<std::endl;*/}
    catch(boost::system::system_error e){/*std::cerr<<"SYSTEM="<<e.what()<<std::endl;*/}
  }
  URLregister & reg = ptr_crawler->getRegister();
  reg.insert(url.string(), urls);
  return urls.size();
}

void Parser::saveData(URLhash_t& h,Data_t& d )
{
  std::stringstream file;
  file<<h<<d<<std::endl;
  cdp->save(file.str());
}

std::string Parser::genFileName()
{
  /*std::stringstream ss;
  posix_time::time_facet *facet = new posix_time::time_facet("%d-%b-%Y %H:%M:%S");
  ss.imbue(locale(ss.getloc(), facet));
  cout <<  << endl;*/
  //std::default_random_engine e((unsigned int)time(0));
  return "Data/"+boost::posix_time::to_iso_string(boost::posix_time::second_clock::universal_time());
}

 Parser::~Parser()
 {
   delete cdp;
 }
}//namespace SWSE
