#ifndef URLRESOLVERCLIENT_H
#define URLRESOLVERCLIENT_H

#include "types.h"

namespace SWSE
{
  typedef std::string URLdate;

  /**
 * \brief The URLResolveResponse struct
 */
  struct URLResolveResponse
  {
    URLstr_t url_;
    URLdate date_;
  };

  class URLResolverClient
  {
  public:

    /*static std::string ADRESS;
  static std::string PORT;

  static void ConfigureResolver(std::string adress, std::string port){ADDRESS = adress; PORT }*/

    enum requestType{HASH,URL,CLOSE,SET_DATE};
    URLResolverClient(boost::asio::io_service& ios );
    void connect(std::string adress, std::string port);
    URLhash_t hash(URLstr_t && url);
    URLhash_t hash(URLstr_t & url);
    URLResolveResponse resolve(URLhash_t & hash);
    void setDate(URLhash_t hash,Data_t d);
    void close();

  private:
    socket_t socket_;
    resolver_t resolver_;
    void Request(requestType type,Data_t data);
  };
}//namespace SWSE

#endif // URLRESOLVERCLIENT_H
