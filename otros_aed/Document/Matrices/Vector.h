#ifndef PUNTO_H_INCLUDED
#define PUNTO_H_INCLUDED

class Vector
{
  private:
  int * m_pvec;
  int m_tam;
  public:
  Vector(int n);
  Vector ();
  ~Vector();
  void llenar();
  void print;
};
#endif // PUNTO_H_INCLUDED
