#include "httpasyncclient.h"
#include "httprequest.h"
#include <boost/bind.hpp>

/*httpAsyncClient::httpAsyncClient()
{
}*/
namespace SWSE
{
  httpAsyncClient::httpAsyncClient(boost::asio::io_service & io_service, httpRequest* req)
    :resolver_(io_service),
      socket_(io_service),
      ptr_request(req)
  {
    ptr_response = new httpResponse;
    tcp::resolver::query query(req->getURL()->getHost(),"http");

    tcp::resolver::iterator iter=resolver_.resolve(query);
    tcp::resolver::iterator end;
    tcp::endpoint endpoint;
    while(iter!=end)
    {
      endpoint=*iter++;
    }
    //socket_.connect(endpoint);
    resolver_.async_resolve(endpoint,
                            boost::bind(&httpAsyncClient::handle_resolve, this,
                                        boost::asio::placeholders::error,
                                        boost::asio::placeholders::iterator));
  }

  //void httpAsyncClient::start()


  void httpAsyncClient::handle_resolve(const boost::system::error_code& err,
                                       tcp::resolver::iterator endpoint_iterator)
  {
    if (!err)
    {
      // Attempt a connection to each endpoint in the list until we
      // successfully establish a connection.
      boost::asio::async_connect(socket_, endpoint_iterator,
                                 boost::bind(&httpAsyncClient::handle_connect, this,
                                             boost::asio::placeholders::error));
    }
    else
    {
      std::cout << "Error: " << err.message() << "\n";
      throw std::runtime_error("");
    }
  }

  void httpAsyncClient::handle_connect(const boost::system::error_code& err)
  {
    if (!err)
    {
      streambuffer request;
      std::ostream request_stream(&request);
      request_stream<<ptr_request;
      // The connection was successful. Send the request.
      boost::asio::async_write(socket_, request,
                               boost::bind(&httpAsyncClient::handle_write_request, this,
                                           boost::asio::placeholders::error));
    }
    else
    {
      std::cout << "Error: " << err.message() << "\n";
    }
  }

  void httpAsyncClient::handle_write_request(const boost::system::error_code& err)
  {
    if (!err)
    {
      // Read the response status line. The response_ streambuf will
      // automatically grow to accommodate the entire line. The growth may be
      // limited by passing a maximum size to the streambuf constructor.
      boost::asio::async_read_until(socket_, response_, "\r\n",
                                    boost::bind(&httpAsyncClient::handle_read_status_line, this,
                                                boost::asio::placeholders::error));

    }
    else
    {
      std::cout << "Error: " << err.message() << "\n";
    }
  }

  void httpAsyncClient::handle_read_status_line(const boost::system::error_code& err)
  {
    if (!err)
    {
      // Check that response is OK.
      std::istream response_stream(&response_);
      std::string http_version;
      response_stream >> http_version;
      ptr_response->HTTPversion()=http_version;
      httpStatusC status_code;
      response_stream >> status_code;
      ptr_response->HTTPstatusCode() = status_code;
      std::string status_message;
      std::getline(response_stream, status_message);
      ptr_response->HTTPmessage() = status_message;
      if (!response_stream || http_version.substr(0, 5) != "HTTP/")
      {
        std::cout << "Invalid response\n";
        return;
      }
      // Read the response headers, which are terminated by a blank line.
      boost::asio::async_read_until(socket_, response_, "\r\n\r\n",
                                    boost::bind(&httpAsyncClient::handle_read_headers, this,
                                                boost::asio::placeholders::error));
    }
    else
    {
      std::cout << "Error: " << err << "\n";
    }
  }

  void httpAsyncClient::handle_read_headers(const boost::system::error_code& err)
  {
    if (!err)
    {
      // Process the response headers.
      ptr_response->setHeader(response_);

      if (ptr_response->HTTPstatusCode() != 200)
      {
        std::cout << "Response returned with status code ";
        std::cout << ptr_response->HTTPstatusCode() << "\n";
        std::cout << (ptr_response->Header());
        return;
      }
      // Start reading remaining data until EOF.
      boost::asio::async_read(socket_, response_,
                              boost::asio::transfer_at_least(1),
                              boost::bind(&httpAsyncClient::handle_read_content, this,
                                          boost::asio::placeholders::error
                                          ,boost::asio::placeholders::bytes_transferred));
    }
    else
    {
      std::cout << "Error: " << err << "\n";
    }
  }

  void httpAsyncClient::handle_read_content(const boost::system::error_code& err,size_t /*tam*/)
  {
    if (!err)
    {
      // Write all of the data that has been read so far.
      //std::cout<<tam<<std::endl;
      std::stringstream ss;
      ss<<&response_;
      ptr_response->Body().append(ss.str());
      // Continue reading remaining data until EOF.
      boost::asio::async_read(socket_, response_,
                              boost::asio::transfer_at_least(1),
                              boost::bind(&httpAsyncClient::handle_read_content, this,
                                          boost::asio::placeholders::error
                                          ,boost::asio::placeholders::bytes_transferred));
    }
    else if (err != boost::asio::error::eof)
    {
      std::cout << "Error: " << err << "\n";
    }
  }

  httpAsyncClient::~httpAsyncClient()
  {
    socket_.close();
    //delete ptr_request;
  }
}//namespace SWSE
