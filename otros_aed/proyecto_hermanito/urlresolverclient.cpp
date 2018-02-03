#include "urlresolverclient.h"
#include <sstream>

namespace SWSE
{
  using boost::asio::ip::tcp;

  URLResolverClient::URLResolverClient(boost::asio::io_service & ios):socket_(ios),resolver_(ios)
  {
  }

  void URLResolverClient::connect(std::string adress, std::string port)
  {
    tcp::resolver::query query(tcp::v4(),adress, port);
    tcp::resolver::iterator iter;
    try
    {
      iter = resolver_.resolve(query);
    }
    catch(...){std::cerr<<"No encuentra el host\n";return;}

    tcp::resolver::iterator end;
    /*tcp::endpoint endpoint;
  while(iter!=end)
    endpoint=*iter++;
  socket_.connect(endpoint);*/
    boost::asio::connect(socket_, iter);

  }

  URLhash_t URLResolverClient::hash(URLstr_t && url)
  {
    return hash(url);
  }

  URLhash_t URLResolverClient::hash(URLstr_t & url)
  {
    Request(HASH,url);
    boost::asio::streambuf in_buff;
    std::istream stream(&in_buff);
    boost::asio::read_until(socket_,in_buff,"#\n");
    URLhash_t tmp;
    std::getline(stream,tmp,'#');
    return tmp;
  }

  URLResolveResponse URLResolverClient::resolve(URLhash_t & hash)
  {
    Request(URL,hash);
    boost::asio::streambuf in_buff;
    std::istream stream(&in_buff);
    boost::asio::read_until(socket_,in_buff,"#\n");
    URLResolveResponse tmp;
    std::getline(stream,tmp.url_,'#');
    std::getline(stream,tmp.date_,'#');
    return tmp;
  }

  void URLResolverClient::close()
  {
    Request(CLOSE,"");
  }

  void URLResolverClient::setDate(URLhash_t h ,Data_t t)
  {
    Request(SET_DATE,h+"#"+t);
  }

  void URLResolverClient::Request(requestType type,Data_t data)
  {
    boost::asio::streambuf buff;
    std::ostream request_stream(&buff);
    request_stream<<type<<"#"<<data<<"#\n";
    boost::asio::write(socket_,buff);
  }
}//namespace SWSE
