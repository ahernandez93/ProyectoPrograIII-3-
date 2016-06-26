#ifndef listaLaboratorio_H
#define listaLaboratorio_H
#include "Curso.h"

class listaLaboratorio
{
    public:
        listaLaboratorio();
        virtual ~listaLaboratorio();
        void insertarAlInicio(Curso *);
        void insertar(int, const char *, int, const char*, int, const char *);
        void insertarAlFinal(Curso *);
        void EliminarCurso(int);
        void ModificarCurso(int, char *, int, char *, int, char *);
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

#endif // listaLaboratorio_H
