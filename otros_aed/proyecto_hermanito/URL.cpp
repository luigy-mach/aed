#include "URL.h"
#include <algorithm>
#include <sstream>
#include <boost/regex.hpp>
#include <boost/function_output_iterator.hpp>
#include <boost/bind.hpp>
#include <iterator>
#include <iomanip>

namespace SWSE
{
std::set<URLstr_t>* URL::URLprotocols = URL::makeSet();

std::set<URLstr_t>* URL::makeSet()
{
    return new std::set<URLstr_t>;
}

void URL::AddURLprotocols(URLstr_t prot)
{
    //std::set<URLstr_t> URL::URLprotocols;
    //std::set<URLstr_t> & su = (std::set<URLstr_t>)URL::URLprotocols;
    if(URL::isValidURLscheme(prot))
        return;
    ((std::set<URLstr_t>*)URL::URLprotocols)->insert(prot);
}

bool URL::isValidURLscheme(URLstr_t val)
{
    return (((std::set<URLstr_t>*)URL::URLprotocols)->find(val)!=((std::set<URLstr_t>*)URL::URLprotocols)->end());
}

URL::URL(URLstr_t & url)
    :m_url(url)
{
    processURL(url);
}

void URL::processURL(URLstr_t & url)
{
    ptr_uri=new Net_uri(url);
    if(!ptr_uri->is_valid())
        throw InvalidURL("Invalid URL: "+url);
    protocol = ptr_uri->scheme();
    if(!URL::isValidURLscheme(protocol))
    {
        throw InvalidProtocol("No URL protocol " + protocol);
    }
    host = ptr_uri->host();
    path = ptr_uri->path();
    if(path.empty())
        path=dir_base ="/";
    else
        dir_base = path.substr(0,path.find_last_of("/")+1);
}

std::ostream & operator<<(std::ostream & os,URL a)
{
    os<<a.m_url;
    return os;
}

URLstr_t URL::Rel2AbsPath(URLstr_t rel)
{
    rel = urlencode(rel);
    if(rel[0]=='/')
        return protocol+"://"+host+rel;
    if(rel[0]=='#')
    {
        throw InvalidURL("Nothing to do.");
        return "";
    }
    if(rel.substr(0,3)=="../")
    {
        size_t pr = 0;
        size_t aux = 0;
        size_t pa = dir_base.size()-1;
        while(((pr=rel.find("../",pr))!=std::string::npos)
                &&((pa=dir_base.rfind('/',pa-1))>0))
        {
            pr+=3;
            aux=pr;
        }
        pr=aux;
        while((pr=rel.find("../",pr))!=std::string::npos)
        {
            pr+=3;
            aux=pr;
        }
        return protocol+"://"+host+dir_base.substr(0,pa)+"/"+rel.substr(aux,std::string::npos);
    }
    if(rel.substr(0,2)=="./")
        return protocol+"://"+host+dir_base+rel.substr(1,rel.size());
    else
        try
        {
            URL u(rel);
            return rel;
        }
        catch(InvalidURL)
        {
            return protocol+"://"+host+dir_base+rel;
        }
    return "";
}

URLstr_t URL::urlencode(const URLstr_t& url)
{
    // Find the start of the query string
    const std::string::const_iterator start = std::find(url.begin(), url.end(), '?');

    // If there isn't one there's nothing to do!
    if (start == url.end())
        return url;

    // store the modified query string
    std::string qstr;

    std::transform(start+1, url.end(),
                   // Append the transform result to qstr
                   boost::make_function_output_iterator(boost::bind(static_cast<std::string& (std::string::*)(const std::string&)>(&std::string::append),&qstr,_1)),
                   [](URLstr_t::value_type v)
    {
        if (isalnum(v)|| v =='=' || v == '&' || v =='%')
            return std::string()+v;

        std::ostringstream enc;
        enc << '%' << std::setw(2) << std::setfill('0') << std::hex << std::uppercase << int(static_cast<unsigned char>(v));
        return enc.str();
    }
                  );
    return std::string(url.begin(), start+1) + qstr;
}

URL::~URL()
{
    //delete ptr_uri;
}
}//namespace SWSE
