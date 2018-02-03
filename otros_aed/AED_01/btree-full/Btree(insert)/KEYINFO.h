
typedef long pReg;

template<typename T>
class KEYINFO
{
    public:
    T dato;
    pReg reg;
    inline KEYINFO(){}
    inline KEYINFO(const KEYINFO &Ki):dato(Ki.dato),reg(Ki.reg){}
    inline KEYINFO(const T &_dato,pReg _reg):dato(_dato),reg(_reg){}
    KEYINFO &operator = (const KEYINFO &_ki)
    {
      dato=_ki.dato;
      reg=_ki.reg;
      return *this;
    }
    operator T (){
        return dato;
    }
};

