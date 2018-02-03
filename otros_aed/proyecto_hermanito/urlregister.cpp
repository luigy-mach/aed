#include "urlregister.h"
#include <openssl/md5.h>
#include <fstream>
#include <boost/serialization/concurrent_unordered_map.hpp>
#include <boost/serialization/concurrent_unordered_set.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
namespace SWSE
{
URLregister::URLregister()
{
  std::cout<<"Loading register.."<<std::endl;
  loadData();
}

URLhash_t URLregister::HashURL(URLstr_t url)
{
  URLhash_t hash;
  unsigned char* tmp_hash=new unsigned char[MD5_DIGEST_LENGTH];
  tmp_hash=MD5((const unsigned char*)url.c_str(),url.length(),NULL);

  char buffer[MD5_DIGEST_LENGTH*2];
  for(size_t I=0;I<MD5_DIGEST_LENGTH;I++)
  {
    sprintf(buffer,"%02x",tmp_hash[I]);
    hash.append(buffer);
  }
  return hash;
}

void URLregister::insert(URLstr_t curURl,URLlist & urls)
{
  URLhash_t curURLhash = HashURL(curURl);
  URLlist::iterator it = urls.begin();
  m_data[curURLhash].first = urls.size();
  for(;it!=urls.end();it++)
    m_data[HashURL(*it)].second.insert(curURLhash);
}

URLhashSet & URLregister::getURLpointTo(URLstr_t& key)
{
  return m_data[HashURL(key)].second;
}

void  URLregister::saveData()
{
    std::cout<<"Guardando register..."<<std::endl;
  std::ofstream ofs("crawlerURLRegister.data");
  boost::archive::text_oarchive oa(ofs);
  oa<<m_data;
}

void  URLregister::loadData()
{
  std::ifstream ifs("crawlerURLRegister.data");
  if(!ifs.is_open())
  {
    std::cout<<"Error File Register"<<std::endl;
    return;
  }
  boost::archive::text_iarchive ia(ifs);
  ia>>m_data;
}

URLregister::~URLregister()
{
  saveData();
}
}//namespace SWSE
