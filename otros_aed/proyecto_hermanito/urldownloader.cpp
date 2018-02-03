#include "urldownloader.h"
#include "httpasyncclient.h"

namespace SWSE
{
  ID URLDownloader::threadid = 0;

  URLDownloader::URLDownloader()
    :m_id (URLDownloader::threadid++)
  {
  }

  URLDownloader::URLDownloader(Crawler * cr)
    :ptr_crawler(cr)
    ,m_id (URLDownloader::threadid++)
    ,parser(cr,m_id)
  {
    boost::asio::io_service ios;
    rc = new URLResolverClient(ios);
    rc->connect("localhost","1234");
    parser.setURLResolverClient(rc);
  }

  URLDownloader::URLDownloader(URLstr_t url,Crawler * cr)
    :m_url(URL(url))
    ,ptr_crawler(cr)
    ,m_id (URLDownloader::threadid++)
    ,parser(cr,m_id)
  {
    boost::asio::io_service ios;
    rc = new URLResolverClient(ios);
    m_request.setURL(m_url);
  }

  void URLDownloader::operator()()
  {
    URLhash_t url;
    URLResolveResponse resp;
    while(ptr_crawler->isON())
    {
      boost::asio::io_service io_service;
      try
      {
        if(!ptr_crawler->PopURL(url))
        {
          std::cout<<"Empty Queue."<<std::endl;
          return;
        }
        resp = rc->resolve(url);
        std::cout<<"CURRENT "<<resp.url_<<"==>"<<this->m_id<<std::endl;
        URL u(resp.url_);
        m_request.setURL(u);
        if(!resp.date_.empty())
          m_request.AddHeader("If-Modified-since",resp.date_);
        httpAsyncClient c(io_service, &m_request);
        io_service.run();
        ptr_crawler->conneciones++;
        httpResponse* r = c.getResponse();
        if(r->HTTPstatusCode()==200)
        {
          std::string a = r->Header().getAttr("Date");
          rc->setDate(url,a);
          parser.run(r,u,url);
        }
        delete r;
        io_service.stop();
      }
      catch(std::runtime_error e)
      {
        io_service.stop();
        std::string w = e.what();
        std::cerr<<"Downloader Exception : "<<w<<std::endl;
      }
      catch(InvalidURL e)
      {
        std::cerr<<e.what()<<std::endl;
      }
    }
  }

  URLDownloader::~URLDownloader()
  {
    //  delete parser;
  }
}//namespace SWSE
