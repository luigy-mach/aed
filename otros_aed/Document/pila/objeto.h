#ifndef OBJETO_H
#define OBJETO_H

class objeto
{
     public:
       virtual objeto* clone()=0;
       virtual void read()=0;
       virtual void print();
       virtual ~objeto();
};


#endif // OBJETO_H
