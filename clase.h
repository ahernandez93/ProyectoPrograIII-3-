#ifndef CLASE_H
#define CLASE_H
#include "curso.h"


class Clase : public Curso
{
public:
    Clase();
    Clase(int, const char *, int, const char*, int, const char *, int);
    virtual ~Clase();
    void setAula(int);
    void setCatedratico(const char *);
    void setDias(int);

    int getAula() const;
    const char * getCatedratico() const;
    int getDias() const;
    virtual void imprimir () const;
    virtual int getCupo() const;

private:
    int aula;
    char catedratico[100];
    int dias;
};

#endif // CLASE_H
