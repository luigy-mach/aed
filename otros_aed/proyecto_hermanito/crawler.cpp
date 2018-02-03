#include "crawler.h"
#include "urldownloader.h"
#include <fstream>

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/concurrent_queue.hpp>
namespace SWSE

{
  Crawler::Crawler()
  {
    conneciones=0;
    ON=true;
    NumThreads = 5;
    URL::AddURLprotocols("http");
  }

  void Crawler::queueURL(URLhash_t url)
  {
    urlQueue.push(url);
  }

  bool Crawler::PopURL(URLhash_t & t)
  {
    return urlQueue.try_pop(t);
  }

  struct wrapper
  {
    URLDownloader * m;
    void operator()()
    {
      (*m)();
    }
    /*~wrapper()
  {
    delete m;
  }*/
  };

  int Crawler::run()
  {
    /*URLDownloader a(this);
    wrapper w;
    w.m = &a;
    std::thread t(wx    );
    t.join();*/
    //loadQueue();
    for(size_t i = 0; i<NumThreads; i++)
    {
      URLDownloader* a = new URLDownloader(this);
      wrapper w;
      w.m = a;
      poolThread.push_back(std::thread(w));
    }
    //URLDownloader d(this);
    //d();
    for(size_t i = 0; i< NumThreads; i++)
    {
      poolThread[i].join();
    }
    saveQueue();
    return 0;
  }

  void Crawler::turnOff()
  {
    std::cout<<"\rApagando..."<<std::endl;
    ON=false;
  }

  void Crawler::saveQueue()
  {
    std::fstream ofs("crawlerURLQueue.data");
    boost::archive::text_oarchive oa1(ofs);
    oa1<<urlQueue;
  }

  void Crawler::loadQueue()
  {
    std::ifstream ss("crawlerURLQueue.data");
    boost::archive::text_iarchive ia(ss);
    ia>>urlQueue;
  }
}//namespace SWSE
