#ifndef MATRIZ_H_INCLUDED
#define MATRIZ_H_INCLUDED

class Matriz
{
  private:
  int i;
  int j;
  int ** vprinc;
  int d;
  int ** temp;
  public:
  Matriz(int n,int m);
  ~Matriz();
  void llenar();
  void print ();
  void smatriz(int **m);
  void rmatriz(int **m);
  void mmatriz(int **m);
  bool simetrica();
  void transpuesta();

};

#endif // MATRIZ_H_INCLUDED
