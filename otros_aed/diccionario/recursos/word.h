#ifndef WORD_H_
#define WORD_H_

#include<vector>
#include<string>

typedef long int lint;

//------------------RECORD---------------------------------
class Word{
	public:
		std::string word;
		lint begin;
		lint sizeoff;
		int pos;

	public:
		Word():begin(-1),sizeoff(-1),pos(-1){}
        Word(std::string m):begin(-1),sizeoff(-1),pos(-1){word=m;}
};
//------------------------------------------------------------
#endif
