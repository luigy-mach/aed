#ifndef URLREGISTER_H
#define URLREGISTER_H

#include "types.h"

/**
 * \brief The URLregister class
 */
namespace SWSE
{
  class URLregister
  {
  public:
    URLregister();
    void insert(URLstr_t curURl,URLlist& urls);
    URLhashSet & getURLpointTo(URLstr_t& key);
    URLhash_t HashURL(URLstr_t url);
    void saveData();
    void loadData();
    virtual ~URLregister();
  private:
    URLHashSetMap m_data;
  };
}//namespace SWSE
#endif // URLREGISTER_H
