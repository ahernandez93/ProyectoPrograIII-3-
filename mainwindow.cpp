#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "curso.h"
#include "clase.h"
#include <iostream>
#include "laboratorio.h"
#include "listaClase.h"
#include "listalaboratorio.h"
#include <QMessageBox>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace  std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    lista1 = new listaClase();
    lista2= new ListaLaboratorio;
    lista1->leerArchivoAleatorio();
    lista2->leerArchivoAleatorio();
    lista1->guardarArchivoAleatorio();
    lista2->leerArchivoAleatorio();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete lista1;
    delete lista2;


}

void MainWindow::on_pushButton_clicked()
{
   Curso * curso4 = new Clase(1,"Programacion VI",12,"3pm",501,"Reggie Murray",145);

   Curso * curso5 = new Clase(2,"Programacion VII",10,"4pm",50,"Juan Perez",135);

   Curso * curso6 = new Clase(3,"Programacion VIII",14,"5pm",10,"Mario Nones",6);

        listaClase * lista = new listaClase();
        //lista->insertarAlFinal(curso4);
        //lista->insertarAlFinal(curso5);
       // lista->insertarAlFinal(curso6);

        lista->leerArchivoAleatorio();
        lista->mostrarLista();

        lista->guardarArchivoAleatorio();

        delete curso4;
        delete curso5;
        delete curso6;
        delete lista;

}

void MainWindow::on_BtnAgregar_clicked()
{
    int codigo=ui->TxtCodigo->text().toInt();
    QString snombre=ui->TxtNombre->text();
    char * nombre=new char[strlen(snombre.toStdString().c_str())+1];
    strcpy(nombre,snombre.toStdString().c_str());

    cout<<nombre<<endl;
    //delete nombre;

}
