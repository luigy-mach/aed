#include "httpheader.h"
#include <sstream>
namespace SWSE
{
httpHeader::httpHeader()
{
}

httpHeader::httpHeader(boost::asio::streambuf & buf)
{
    processHeader(buf);
}

void httpHeader::processHeader(boost::asio::streambuf & buf)
{
    attributes.clear();
    std::istream response_stream(&buf);
    std::string attr,attrv;
    while (std::getline(response_stream,attr) && attr != "\r")
    {
        std::stringstream ss;
        ss<<attr;
        std::getline(ss,attr,':');
        ss.ignore();
        std::getline(ss,attrv,'\r');
        attributes[attr] = attrv;
    }
}


std::string httpHeader::getAttr(std::string attrName)
{
    return attributes[attrName];
}

std::ostream & operator<<(std::ostream & os,httpHeader &h)
{
    mapstrstr::iterator it = h.attributes.begin();
    for(; it!=h.attributes.end(); it++)
    {
        os<<(*it).first<<": "<<(*it).second<<std::endl;
    }
    return os;
}
}//namespace SWSE
