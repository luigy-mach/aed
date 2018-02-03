#include <string>
class Palabra//Diccionario
{
  public:
	 string castellano;//almacena palabras en castellano
	 string ingles;//almacena palabras en ingles
  public:
	  Palabra(){};
	  Palabra(string c, string i)
	  {
		  castellano = c;//guarda string c en castellano
		  ingles = i;//guarda string i en castellano
	  }

	  string traducir(bool t =0)//solo retorna 0 cuando la palabra esta en ingles
	  {
		  if (t ==0) return ingles;
		  return castellano;
		   
	  }

	  bool operator==(Palabra & p) 
	  {
		  return castellano == p.castellano;

	  }

	  bool operator>(Palabra & p) 
	  {
		  return castellano > p.castellano;

	  }

	  friend ostream & operator<<(ostream &os, Palabra & p)
	  {
		  os<<p.castellano<<"--"<<p.ingles<<endl;
		  return os;
	  }
};

