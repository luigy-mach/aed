#include "persona.h"

Persona::Persona(string c, string n, int e, char a, string d)
{
    codigo=c;
    name=n;
    edad=e;
    sexo=a;
    direccion=d;
}
Persona::~Persona()
{

}

void Persona::set_name(string n){name=n;}
void Persona::set_edad(int e){edad=e;}
void Persona::set_sexo(char s){sexo=s;}
void Persona::set_codigo(string c){codigo=c;}
void Persona::set_direccion(string d){direccion =d;}
string Persona::get_name(){return name;}
int Persona::get_edad(){return edad;}
char Persona::get_sexo(){return sexo;}
string Persona::get_codigo(){return codigo;}
string Persona::get_direccion(){return direccion;}
