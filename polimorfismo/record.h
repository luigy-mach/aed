#ifndef RECORD_H_
#define RECORD_H_


#include<string>


typedef long int lint;

class Record{
	public:
		std::string model;
		lint begin;
		lint sizeoff;
		int available;
		int pos;
	public:
		Record():begin(-1),sizeoff(-1),available(-1),pos(-1){}
		//// para objetos
		bool operator==(Record& r);
		bool operator<(Record& r);
		bool operator>(Record& r);
		/// para punteros
		bool operator==(Record* r);
		bool operator<(Record* r);
		bool operator>(Record* r);
		//otros
		void operator=(Record& r);
		//void operator=(Record* r);
};




#endif
