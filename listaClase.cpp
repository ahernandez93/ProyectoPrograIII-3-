#include "listaClase.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include "clase.h"
#include "laboratorio.h"
#include "curso.h"
using namespace std;
listaClase::listaClase()
{
    //ctor
    inicio=0;
    fin=0;

}

listaClase::~listaClase()
{
    //dtor
    cout<<"Detructor de lista de Clases"<<endl;

    Curso * temp = inicio;
    while(inicio != 0){
        inicio = temp->getSiguiente();
        delete temp;
        temp = inicio;
    }

}

void listaClase::insertarAlInicio(Curso * nuevo)
{
    if(inicio == 0){
        inicio = nuevo;
        fin = nuevo;
   }
   else{
        nuevo->setSiguiente(inicio);
        inicio->setAnterior(nuevo);
        inicio = nuevo;
   }
}

void listaClase::insertar(int codigo, const char * nombre, int matriculados, const char* hora, int aula, const char * catedratico, int dias)
{
    Curso * nuevo= new Clase(codigo,nombre,matriculados,hora,aula,catedratico,dias);
    if(inicio == 0){
        inicio = nuevo;
        fin = nuevo;
   }
   else{
        fin->setSiguiente(nuevo);
        nuevo->setAnterior(fin);
        fin = nuevo;
   }
}

Curso * listaClase::getInicio(){
    return inicio;
}

void listaClase::insertarAlFinal(Curso * nuevo)
{
    if(inicio == 0){
        inicio = nuevo;
        fin = nuevo;
   }
   else{
        //delete fin;
        fin->setSiguiente(nuevo);
        nuevo->setAnterior(fin);
        fin = nuevo;
   }
}

void listaClase::agregar(Curso* nuevo)
{
    if(inicio == 0){
        inicio = nuevo;
        fin = nuevo;
   }
   else{
        fin->setSiguiente(nuevo);
        nuevo->setAnterior(fin);
        fin = nuevo;
   }
}

void listaClase::EliminarCurso(int codigo)
{
    Curso * temp = inicio;
    while(temp !=0){
        if(codigo == temp->getCodigo()){

            if (temp->getSiguiente() != 0 && temp->getAnterior() !=0)
            {
                temp->getAnterior()->setSiguiente(temp->getSiguiente());
                temp->getSiguiente()->setAnterior(temp->getAnterior());
                delete temp;

            }
            else if(temp->getAnterior() == 0 && temp->getSiguiente() != 0)
            {
                temp->getSiguiente()->setAnterior(0);
                inicio = temp->getSiguiente();
                delete temp;
            }
            else if(temp->getAnterior() != 0 && temp->getSiguiente() == 0)
            {
                temp->getAnterior()->setSiguiente(0);
                fin = temp->getAnterior();
                delete temp;
            }
            else
            {
                delete temp;
                inicio = NULL;
                fin = NULL;
            }
        }
        temp = temp->getSiguiente();
    }


}

void listaClase::mostrarLista()
{
    Curso * temp = inicio;
    while(temp !=0){
        temp->imprimir();
        temp = temp->getSiguiente();
    }
}

bool listaClase::buscarCurso(int codigo)
{
    Curso * temp = inicio;
    while(temp !=0){
        if(codigo == temp->getCodigo())
            return true;

        temp = temp->getSiguiente();
    }
    return false;
}

Curso * listaClase::buscarCurso2(int codigo)
{
    Curso * temp = inicio;
    while(temp !=0){
        if(codigo == temp->getCodigo())
            return temp;

        temp = temp->getSiguiente();
    }
    return 0;
}

void listaClase::guardarArchivoAleatorio()
{
    ofstream archivoSalida ("archivo.clase",ios::out|ios::binary);
    Curso *temp1=inicio;
   while(temp1 !=0){
        Clase *temp2 = new Clase(temp1->getCodigo(),temp1->getNombre(),temp1->getMatriculados(),temp1->getHora(),((Clase*)temp1)->getAula(),((Clase*)temp1)->getCatedratico(),((Clase*)temp1)->getDias());
        archivoSalida.write(reinterpret_cast <const char *> (temp2),sizeof(Clase));
        temp1=temp1->getSiguiente();
        delete temp2;
   }
   archivoSalida.close();
}

void listaClase::leerArchivoAleatorio()
{
    ifstream archivoEntrada ("archivo.clase",ios::in | ios::binary);
    if(!archivoEntrada)
    {
        cout<<"El archivo de clase no existe."<<endl;
        return;
    }

    Clase curso;

    archivoEntrada.read(reinterpret_cast<char *> (&curso), sizeof(Clase));

    while(archivoEntrada && !archivoEntrada.eof())
    {
        //curso->imprimir();
        this->insertar(curso.getCodigo(),curso.getNombre(),curso.getMatriculados(),curso.getHora(),curso.getAula(),curso.getCatedratico(),curso.getDias());
        archivoEntrada.read(reinterpret_cast<char *> (&curso), sizeof(Clase));

    }
    archivoEntrada.close();

}


