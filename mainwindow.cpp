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

    if(lista1->getInicio() == 0){

    }
    else
    {
        int codigo = ui->CboCodigo->currentText().toInt();
        Curso * encontrado = lista1->buscarCurso2(codigo);

        ui->TxtCodigo->setText(QString::number(encontrado->getCodigo()));
        ui->TxtNombre->setText(QString(encontrado->getNombre()));
        ui->TxtMatriculados->setText(QString::number(encontrado->getMatriculados()));
        ui->TxtHora->setText(QString(encontrado->getHora()));
        ui->TxtAula->setText(QString::number(((Clase *)encontrado)->getAula()));
        ui->TxtCatedratico->setText(QString(((Clase *)encontrado)->getCatedratico()));
        ui->TxtDias->setText(QString::number(((Clase *)encontrado)->getDias()));
        ui->TxtCupo->setText(QString::number(encontrado->getCupo() - encontrado->getMatriculados()));
    }


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

void MainWindow::on_CboCodigo_activated(int index)
{
    int codigo = ui->CboCodigo->currentText().toInt();
    Curso * encontrado = lista1->buscarCurso2(codigo);


    ui->TxtCodigo->setText(QString::number(encontrado->getCodigo()));
    ui->TxtNombre->setText(QString(encontrado->getNombre()));
    ui->TxtMatriculados->setText(QString::number(encontrado->getMatriculados()));
    ui->TxtHora->setText(QString(encontrado->getHora()));
    ui->TxtAula->setText(QString::number(((Clase *)encontrado)->getAula()));
    ui->TxtCatedratico->setText(QString(((Clase *)encontrado)->getCatedratico()));
    ui->TxtDias->setText(QString::number(((Clase *)encontrado)->getDias()));
    ui->TxtCupo->setText(QString::number(encontrado->getCupo() - encontrado->getMatriculados()));
}

void MainWindow::on_BtnNuevo_clicked()
{
    ui->TxtCodigo->setText("");
    ui->TxtNombre->setText("");
    ui->TxtMatriculados->setText("");
    ui->TxtHora->setText("");
    ui->TxtAula->setText("");
    ui->TxtCatedratico->setText("");
    ui->TxtDias->setText("");
    ui->TxtCupo->setText("");
}

void MainWindow::on_BtnModificar_clicked()
{

}

void MainWindow::on_BtnEliminar_clicked()
{
    if(ui->TxtCodigo->text().isEmpty())
    {
       QMessageBox msgbox;
       msgbox.setText("Codigo esta en blanco");
       msgbox.exec();
    }
    else
    {
        lista1->EliminarCurso(ui->TxtCodigo->text().toInt());
        ui->CboCodigo->removeItem(ui->CboCodigo->currentIndex());

        if(lista1->getInicio() == 0)
            ui->BtnNuevo->click();
        else
            ui->CboCodigo->activated(ui->CboCodigo->currentIndex());
    }
}
