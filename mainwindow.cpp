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
#include <qmessagebox.h>
#include <string.h>

using namespace  std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //QMessageBox msgbox;
    ui->setupUi(this);
    lista1 = new listaClase();
    lista2= new ListaLaboratorio;
    lista1->leerArchivoAleatorio();
    Curso * temp=lista1->getInicio();
    while(temp!=0){
        QString s=QString::number(temp->getCodigo());
        ui->CboCodigo->addItem(s);
        temp=temp->getSiguiente();
    }
    lista1->mostrarLista();
    lista2->leerArchivoAleatorio();
}

MainWindow::~MainWindow()
{
    delete ui;
    lista1->guardarArchivoAleatorio();
    lista2->guardarArchivoAleatorio();

    delete lista1;
    delete lista2;


}



void MainWindow::on_BtnAgregar_clicked()
{

    int codigo=ui->TxtCodigo->text().toInt();
    if(lista1->buscarCurso(codigo)){
       QMessageBox msgbox;
       msgbox.setText("Curso ya existe");
       msgbox.exec();
       return;
    }
    QString Qnombre=ui->TxtNombre->text();
    char * nombre=new char[strlen(Qnombre.toStdString().c_str())+1];
    strcpy(nombre,Qnombre.toStdString().c_str());

    int matriculados=ui->TxtMatriculados->text().toInt();

    QString Qhora=ui->TxtHora->text();
    char * hora= new char[strlen(Qnombre.toStdString().c_str())+1];
    strcpy(hora,Qhora.toStdString().c_str());


    int aula=ui->TxtAula->text().toInt();

    QString Qcatedratico=ui->TxtCatedratico->text();
    char * catedratico= new char[strlen(Qcatedratico.toStdString().c_str())+1];
    strcpy(catedratico,Qcatedratico.toStdString().c_str());

    int dias=ui->TxtDias->text().toInt();


    Curso * nuevo= new Clase(codigo,nombre,matriculados,hora,aula,catedratico,dias);
    nuevo->imprimir();
    cout<<endl;
    ui->CboCodigo->addItem(ui->TxtCodigo->text());
    lista1->insertar(codigo,nombre,matriculados,hora,aula,catedratico,dias);

    //cout<<nombre<<endl;
    //delete nombre;
    delete nuevo;

}

void MainWindow::on_pushButton_clicked()
{

}
