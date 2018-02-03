#include "record.h"

bool Record::operator==(Record& r){
    std::string::iterator it_this=this->word.begin();
    std::string::iterator it_r=r.word.begin();
    int value_this=0;
    int value_r=0;
    for(int i=1;it_this!=this->word.end();i++){
        value_this+=(*it_this)*i;
        it_this++;
    }

    for(int i=1;it_r!=r.word.end();i++){
        value_r+=(*it_r)*i;
        it_r++;
    }
    return (value_this==value_r)?true:false;
}

bool Record::operator!=(Record& r){
    std::string::iterator it_this=this->word.begin();
    std::string::iterator it_r=r.word.begin();
    int value_this=0;
    int value_r=0;
    for(int i=1;it_this!=this->word.end();i++){
        value_this+=(*it_this)*i;
        it_this++;
    }

    for(int i=1;it_r!=r.word.end();i++){
        value_r+=(*it_r)*i;
        it_r++;
    }
    return (value_this!=value_r)?true:false;
}

bool Record::operator<(Record& r){

    std::string::iterator it_this=this->word.begin();
    std::string::iterator it_r=r.word.begin();
    int value_this=0;
    int value_r=0;
    for(int i=1;it_this!=this->word.end();i++){
        value_this+=(*it_this)*i;
        it_this++;
    }

    for(int i=1;it_r!=r.word.end();i++){
        value_r+=(*it_r)*i;
        it_r++;
    }

    return (value_this<value_r)?true:false;
}

bool Record::operator>(Record& r){

    std::string::iterator it_this=this->word.begin();
    std::string::iterator it_r=r.word.begin();
    int value_this=0;
    int value_r=0;
    for(int i=1;it_this!=this->word.end();i++){
        value_this+=(*it_this)*i;
        it_this++;
    }

    for(int i=1;it_r!=r.word.end();i++){
        value_r+=(*it_r)*i;
        it_r++;
    }

    return (value_this>value_r)?true:false;
}


bool Record::operator==(Record* r){
    return	operator==(*r);
}

bool Record::operator!=(Record* r){
    return	operator!=(*r);
}

bool Record::operator<(Record* r){
    return	operator<(*r);
}
bool Record::operator>(Record* r){
    return	operator>(*r);

}

void Record::operator=(Record& r){
    this->word=r.word;
}

/*void Record::operator=(Record* r){
    operator=(*r);
}*/
