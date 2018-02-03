#ifndef KEYINFO_H
#define KEYINFO_H

typedef long pReg;
typedef void* T;

class KeyInfo
{
public:
   T key;
   pReg reg;
   inline KeyInfo(){}
   inline KeyInfo(const KeyInfo &Ki):key(Ki.key),reg(Ki.reg){}
   inline KeyInfo(T _key,const pReg _reg):key(_key),reg(_reg){}
   KeyInfo &operator = (const KeyInfo &Ki){
     key=Ki.key;
     reg=Ki.reg;
     return *this;
     }
};

#endif // KEYINFO_H
