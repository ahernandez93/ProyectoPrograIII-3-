#ifndef listaClase_H
#define listaClase_H
#include "Curso.h"

class listaClase
{
    public:
        listaClase();
        virtual ~listaClase();
        void insertarAlInicio(Curso *);
        void insertar(int, const char *, int, const char*, int, const char *, int);
        void insertarAlFinal(Curso *);
        void EliminarCurso(int);
        void ModificarCurso(int, char *, int, char *, int, char *, int);
        void Matricular(int);

        void mostrarLista();
        bool buscarCurso(int);
        void guardarArchivoAleatorio();
        void leerArchivoAleatorio();
        Curso * getInicio();
        void agregar(Curso *);
        Curso * buscarCurso2(int);

    protected:

    private:
        Curso * inicio;
        Curso * fin;
        char nombreArchivo[30];

};

#endif // listaClase_H
