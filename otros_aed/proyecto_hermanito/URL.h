#ifndef URL_H
#define URL_H

#include "types.h"

namespace SWSE
{
typedef std::string whatMsj_t;

class URLexception
{
public:
    URLexception(whatMsj_t what)
        :what_(what)
    {}
    virtual whatMsj_t what()
    {
        return "URL: "+what_;
    }
    virtual ~URLexception() {}
protected:
    whatMsj_t what_;
};

class InvalidProtocol: public URLexception
{
public:
    InvalidProtocol(whatMsj_t what)
        :URLexception(what)
    {}
};
class InvalidURL: public URLexception
{
public:
    InvalidURL(whatMsj_t what)
        :URLexception(what)
    {}
};

/**
 * @brief Clase URL
 * @details Almacena una URL y la descompone en sus datos específicos como el HOST
 *  ,el PATH, etc.
 * @author José Valencia G.
 */
class URL
{
private:
    /// @brief Protocolo de la URL.
    std::string protocol;
    /// @brief Servidor o dominio.
    std::string host;
    /// @brief Archivo alojado en el host.
    std::string path;
    /// @brief url completa.
    std::string dir_base;
    URLstr_t m_url;
    Net_uri* ptr_uri;
    static std::set<URLstr_t>* makeSet();
public:

    static std::set<URLstr_t>* URLprotocols;
    static void AddURLprotocols(URLstr_t prot);
    static bool isValidURLscheme(URLstr_t val);
    /// @brief Constructor por default
    URL() {}
    /**
       * @brief Constructor
       * @param url string de la url.
       * @exception runtime_error si url no representa una url válida
       */
    URL(URLstr_t & url);
    /**
       * @brief Descompone la url.
       * @param url string a ser descompuesto.
       * @exception runtime_error si url no representa una url válida
       */
    URLstr_t string()
    {
        return m_url;
    }
    void processURL(URLstr_t & url);
    /**
       * @brief Obtiene el protocolo de la URL.
       * @return Protocolo.
       */
    std::string getProtocol()
    {
        return protocol;
    }
    /**
       * @brief Obtiene el host de la URL.
       * @return Host.
       */
    std::string getHost() const
    {
        return host;
    }
    /**
       * @brief Obtiene el archivo o path de la URL.
       * @return Path de el archivo.
       */
    std::string getPath()
    {
        return path;
    }

    std::string getQuery()
    {
        return ptr_uri->query();
    }

    std::string getPathBase()
    {
        return dir_base;
    }

    /**
       * @brief Cambia el protocolo de la url
       * @param val Nuevo protocolo
       */
    void setProtocol(std::string val)
    {
        protocol = val;
    }
    /**
       * @brief Cambia el host de la url
       * @param val Nuevo host
       */
    void setHost(std::string val)
    {
        host = val;
    }
    /**
       * @brief Cambia el path de la url
       * @param val Nuevo path
       */
    void setFile(std::string val)
    {
        path = val;
    }

    URLstr_t Rel2AbsPath(URLstr_t rel);

    friend std::ostream & operator<<(std::ostream & os,URL a);
    //void operator = (URL a){std::cout<<"igual!!!"<<std::endl;}

    URLstr_t urlencode(const URLstr_t& url);
    virtual ~URL();
};
}//namespace SWSE
#endif // URL_H
