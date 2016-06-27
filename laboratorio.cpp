#include "laboratorio.h"
#include <iostream>
#include <cstring>

using namespace std;

Laboratorio::Laboratorio() : Curso()
{
    this->numlaboratorio = 0;
    //this->instructor=new char [1];
    strcpy(this->instructor,"");
    this->dias = 0;
}

Laboratorio::Laboratorio(int codigo,const char * nombre, int matriculados,const char* hora, int numlaboratorio,const char * instructor) : Curso(codigo,nombre,matriculados,hora)
{
    this->setNumLaboratorio(numlaboratorio);
    this->setInstructor(instructor);
    this->setDias();
}

Laboratorio::~Laboratorio()
{
    cout<<"destructor laboratorio"<<endl;
    //delete [] this->instructor;
}

void Laboratorio::setNumLaboratorio(int numlaboratorio)
{
    this->numlaboratorio = numlaboratorio;
}

void Laboratorio::setInstructor(const char * instructor)
{
    //delete [] this->instructor;
    //this->instructor=new char [strlen(instructor)+1];
    strcpy(this->instructor,instructor);
}

void Laboratorio::setDias()
{
    this->dias = 6;
}

int Laboratorio::getNumLaboratorio() const
{
    return this->numlaboratorio;
}
const char * Laboratorio::getInstructor() const
{
    return this->instructor;
}
int Laboratorio::getDias() const
{
    return this->dias;
}
int Laboratorio::getCupo() const
{
    return 12;
}
