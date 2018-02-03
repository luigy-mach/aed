#ifndef GARBAGE_H
#define GARBAGE_H

class garbage
{
    private:
        int count;
        long int memDir;
        int tamano;
    public:
        garbage();
        int getCount();
        void setCount(int);
        void incrementar();
        void decrementar();
        void setMenDir(long int);
        long int getmenDir();
        bool operator ==(garbage *a){return count== a->getCount();}
        bool operator <(garbage *a){return count < a->getCount();}
        bool operator >(garbage *a){return count > a->getCount();}
};


garbage::garbage()
{
    memDir=0;
    count=0;
}
int garbage::getCount(){ return count;}
void garbage::setCount(int c){ count=c;}
void garbage::setMenDir(long int a){ memDir=a;}
long int garbage::getmenDir(){return memDir;}
void garbage::decrementar(){count--;}
void garbage::incrementar(){count++;}
#endif // GARBAGE_H
