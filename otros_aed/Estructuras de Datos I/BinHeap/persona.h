#ifndef PERSONA_H
#define PERSONA_H

#include<iostream>
#include<string>
using namespace std;
class Persona
{
private:
    int edad;
    string name;
    char sexo;
    string codigo;
    string direccion;
public:
    Persona(){};
    ~Persona();
    Persona(string c, string n, int e, char a, string d);
    void set_name(string n);
    void set_edad(int e);
    void set_sexo(char s);
    void set_codigo(string c);
    void set_direccion(string d);
    string get_name();
    int get_edad();
    char get_sexo();
    string get_codigo();
    string get_direccion();
    bool operator==(Persona p) {return codigo == p.codigo;}
    bool operator<(Persona p) {return codigo < p.codigo;}
};

#endif // PERSONA_H
