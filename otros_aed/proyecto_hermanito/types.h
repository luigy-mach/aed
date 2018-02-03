#ifndef TYPES_H
#define TYPES_H

#include <thread>
#include <vector>
#include <string>
#include <list>
#include <unordered_map>
#include <unordered_set>

#include <boost/network/uri/uri.hpp>
#include <boost/regex.hpp>
#include <boost/asio.hpp>
#include <tbb/concurrent_queue.h>
#include <tbb/concurrent_unordered_map.h>
#include <tbb/concurrent_unordered_set.h>

/**
 * @file types.h
 *
 * @brief Contiene las definiciones de los tipos que usados
 * @author José L. Valencia G.
 * @date 04/12/2012
 */
namespace SWSE
{
typedef unsigned int ID;

typedef std::string URLhash_t;

typedef tbb::concurrent_unordered_set<URLhash_t> URLhashSet;

typedef tbb::concurrent_unordered_map<URLhash_t,std::pair<size_t,URLhashSet> > URLHashSetMap;

using boost::asio::io_service;

typedef boost::asio::ip::tcp::resolver resolver_t;

typedef boost::asio::ip::tcp::socket socket_t;

typedef unsigned int httpStatusC;

typedef boost::asio::streambuf streambuffer;

typedef std::string Data_t;

/**
 * @typedef Net_uri
 * @brief URI manager.
 */
typedef boost::network::uri::uri Net_uri;

/**
 * @typedef mapstrstr
 * @brief Mapea un string apartír de otro string
 */
typedef  std::unordered_map<std::string,std::string> mapstrstr;

/**
 * @brief Tipo de dato para el string de una URL
 */
typedef std::string URLstr_t;

/**
 * @typedef URLqueue_t
 * @brief Cola concurrente de URL's para ser procesadas.
 */
typedef tbb::concurrent_queue<URLhash_t> URLqueue_t;

/**
 * @brief Pool de hilos.
 */
typedef std::vector<std::thread> PoolThread_t;

/**
 * @brief Lista de URLstr_t.
 */
typedef std::unordered_set<URLstr_t> URLlist;
/**
 * @brief Puntero a la lista de URLstr_t.
 */
//typedef URLlist* pURLlist;
}//namespace SWSE
#endif // TYPES_H
