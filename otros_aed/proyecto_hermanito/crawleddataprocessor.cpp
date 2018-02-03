#include "crawleddataprocessor.h"

namespace SWSE
{

  size_t CrawledDataProcessor::MinWriteSize = 1024;

  CrawledDataProcessor::CrawledDataProcessor(std::string fileName)
  {
    oFile.open(fileName);
  }

  void CrawledDataProcessor::save(Data_t && d)
  {
    m_data.append(d);
    if(m_data.size()>MinWriteSize)
    {
      oFile<<m_data;
      m_data.clear();
    }
  }

  CrawledDataProcessor::~CrawledDataProcessor()
  {
    oFile<<m_data;
    oFile.close();
  }
}//namespace SWSE
