#include "listaLaboratorio.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include "clase.h"
#include "laboratorio.h"
#include "curso.h"
#include <QMessageBox>

using namespace std;
listaLaboratorio::listaLaboratorio()
{
    //ctor
    inicio=0;
    fin=0;

}

listaLaboratorio::~listaLaboratorio()
{
    //dtor
    cout<<"Detructor de lista de laboratorio"<<endl;

    Curso * temp = inicio;
    while(inicio != 0){
        inicio = temp->getSiguiente();
        delete temp;
        temp = inicio;
    }

}

void listaLaboratorio::insertarAlInicio(Curso * nuevo)
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

void listaLaboratorio::insertar(int codigo, const char * nombre, int matriculados, const char* hora, int NumLaboratorio, const char * Instructor)
{
    Curso * nuevo= new Laboratorio(codigo,nombre,matriculados,hora,NumLaboratorio,Instructor);
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

Curso * listaLaboratorio::getInicio(){
    return inicio;
}

void listaLaboratorio::insertarAlFinal(Curso * nuevo)
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

void listaLaboratorio::agregar(Curso* nuevo)
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

void listaLaboratorio::EliminarCurso(int codigo)
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

void listaLaboratorio::ModificarCurso(int codigo, char * nombre, int matriculados, char * hora, int NumLaboratorio, char * Instructor)
{
    Curso * temp = inicio;
    while(temp !=0){
        if(codigo == temp->getCodigo())
        {
            temp->setNombre(nombre);
            temp->setMatriculados(matriculados);
            temp->setHora(hora);
            ((Laboratorio *)temp)->setNumLaboratorio(NumLaboratorio);
            ((Laboratorio *)temp)->setInstructor(Instructor);
        }

        temp = temp->getSiguiente();
    }

}

void listaLaboratorio::Matricular(int codigo)
{
    Curso * temp = inicio;
    while(temp !=0){
        if(codigo == temp->getCodigo())
        {
            if(temp->getMatriculados()<30)
                temp->setMatriculados(temp->getMatriculados() + 1);
            else
            {
                QMessageBox msgbox;
                msgbox.setText("Laboratorio llena");
                msgbox.exec();

            }
        }
        temp = temp->getSiguiente();
    }
}

void listaLaboratorio::mostrarLista()
{
    Curso * temp = inicio;
    while(temp !=0){
        temp->imprimir();
        temp = temp->getSiguiente();
    }
}

bool listaLaboratorio::buscarCurso(int codigo)
{
    Curso * temp = inicio;
    while(temp !=0){
        if(codigo == temp->getCodigo())
            return true;

        temp = temp->getSiguiente();
    }
    return false;
}

Curso * listaLaboratorio::buscarCurso2(int codigo)
{
    Curso * temp = inicio;
    while(temp !=0){
        if(codigo == temp->getCodigo())
            return temp;

        temp = temp->getSiguiente();
    }
    return 0;
}

void listaLaboratorio::guardarArchivoAleatorio()
{
    ofstream archivoSalida ("archivo.laboratorio",ios::out|ios::binary);
    Curso *temp1=inicio;
   while(temp1 !=0){
        Laboratorio *temp2 = new Laboratorio(temp1->getCodigo(),temp1->getNombre(),temp1->getMatriculados(),temp1->getHora(),((Laboratorio*)temp1)->getNumLaboratorio(),((Laboratorio*)temp1)->getInstructor());
        archivoSalida.write(reinterpret_cast <const char *> (temp2),sizeof(Laboratorio));
        temp1=temp1->getSiguiente();
        delete temp2;
   }
   archivoSalida.close();
}

void listaLaboratorio::leerArchivoAleatorio()
{
    ifstream archivoEntrada ("archivo.laboratorio",ios::in | ios::binary);
    if(!archivoEntrada)
    {
        cout<<"El archivo de Laboratorio no existe."<<endl;
        return;
    }

    Laboratorio curso;

    archivoEntrada.read(reinterpret_cast<char *> (&curso), sizeof(Laboratorio));

    while(archivoEntrada && !archivoEntrada.eof())
    {
        this->insertar(curso.getCodigo(),curso.getNombre(),curso.getMatriculados(),curso.getHora(),curso.getNumLaboratorio(),curso.getInstructor());
        archivoEntrada.read(reinterpret_cast<char *> (&curso), sizeof(Laboratorio));

    }
    archivoEntrada.close();

}




