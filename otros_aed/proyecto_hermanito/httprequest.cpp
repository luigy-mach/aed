#include "httprequest.h"
#include <ostream>
namespace SWSE
{
httpRequest::httpRequest()
{
    init();
}

httpRequest::httpRequest(URL & url)
    :m_url(url)
{
    init();
}

void httpRequest::AddHeader(std::string name,std::string val)
{
    attributes[name]=val;
}

void httpRequest::init()
{
    // Form the request. We specify the "Connection: close" header so that the
    // server will close the socket after transmitting the response. This will
    // allow us to treat all data up until the EOF as the content.
    attributes["Accept"]="text/*,*/*;q=0";
    //attributes["Connection"]="close";
}

void httpRequest::WriteSocket(socket_t & socket)
{
    boost::asio::streambuf request;
    std::ostream request_stream(&request);
    request_stream<<this;
    boost::asio::write(socket, request);
}

std::ostream & operator<<(std::ostream & os, httpRequest* req)
{
    URLstr_t query = req->m_url.getQuery();
    query = (query.empty())? "":"?"+query;
    os << "GET " << req->m_url.getPath()<<query<< " HTTP/1.1\r\n";
    os << "Host: " << req->m_url.getHost() << "\r\n";
    mapstrstr::iterator it = req->attributes.begin();
    for(; it!=req->attributes.end(); it++)
        os << (*it).first <<": "<< (*it).second <<"\r\n";
    os<<"Connection: close\r\n\r\n";
    return os;
}
}//namespace SWSE
