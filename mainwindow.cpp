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
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton->setVisible(false);
    setWindowFlags(windowFlags() ^ Qt::WindowMaximizeButtonHint);

    this->setFixedSize(this->maximumSize());

    lista1 = new listaClase();
    lista2= new listaLaboratorio();

    lista1->leerArchivoAleatorio();
    Curso * temp=lista1->getInicio();
    while(temp!=0){
        QString s=QString::number(temp->getCodigo());
        ui->CboCodigo->addItem(s);
        temp=temp->getSiguiente();
    }
    lista1->mostrarLista();

    lista2->leerArchivoAleatorio();
    Curso * temp2=lista2->getInicio();
    while(temp2!=0){
        QString s2=QString::number(temp2->getCodigo());
        ui->CboCodigo_2->addItem(s2);
        temp2=temp2->getSiguiente();
    }

    //Clases
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

    //Laboratorios
    if(lista2->getInicio() == 0){

    }
    else
    {
        int codigo2 = ui->CboCodigo_2->currentText().toInt();
        Curso * encontrado2 = lista2->buscarCurso2(codigo2);

        ui->TxtCodigo_2->setText(QString::number(encontrado2->getCodigo()));
        ui->TxtNombre_2->setText(QString(encontrado2->getNombre()));
        ui->TxtMatriculados_2->setText(QString::number(encontrado2->getMatriculados()));
        ui->TxtHora_2->setText(QString(encontrado2->getHora()));
        ui->TxtAula_2->setText(QString::number(((Laboratorio *)encontrado2)->getNumLaboratorio()));
        ui->TxtCatedratico_2->setText(QString(((Laboratorio *)encontrado2)->getInstructor()));
        ui->TxtDias_2->setText(QString::number(((Laboratorio *)encontrado2)->getDias()));
        ui->TxtCupo_2->setText(QString::number(encontrado2->getCupo() - encontrado2->getMatriculados()));
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

void MainWindow::on_pushButton_clicked()
{

}

/*****************************CLASES*************************************/

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
    ui->CboCodigo->setCurrentIndex(-1);
    ui->TxtCodigo_2->setFocus();
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

    if (codigo == 0)
    {
        QMessageBox msgbox;
        msgbox.setText("Datos vacios, no puede agregar");
        msgbox.exec();
        ui->TxtCodigo->setFocus();
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

    if((aula >= 1) &&  (aula <= 50))
    {

    }
    else
    {
        QMessageBox msgbox;
        msgbox.setText("Aula no valida, ingrese un valor entre 1 y 50");
        msgbox.exec();
        ui->TxtAula->setFocus();
        return;
    }

    QString Qcatedratico=ui->TxtCatedratico->text();
    char * catedratico= new char[strlen(Qcatedratico.toStdString().c_str())+1];
    strcpy(catedratico,Qcatedratico.toStdString().c_str());

    int dias=ui->TxtDias->text().toInt();

    Curso * nuevo= new Clase(codigo,nombre,matriculados,hora,aula,catedratico,dias);
    nuevo->imprimir();
    cout<<endl;
    ui->CboCodigo->addItem(ui->TxtCodigo->text());
    lista1->insertar(codigo,nombre,matriculados,hora,aula,catedratico,dias);

    QMessageBox msgBox;
    msgBox.setText("Clase agregada con exito");
    msgBox.exec();

    ui->CboCodigo->setCurrentIndex(ui->CboCodigo->findText(QString::number(codigo)));
    ui->CboCodigo->activated(ui->CboCodigo->currentIndex());

    delete nuevo;
}

void MainWindow::on_BtnModificar_clicked()
{
    int codigo=ui->TxtCodigo->text().toInt();

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

    lista1->ModificarCurso(codigo, nombre, matriculados, hora, aula, catedratico, dias);

    QMessageBox msgBox;
    msgBox.setText("Clase modificada con exito");
    msgBox.exec();

    ui->CboCodigo->activated(ui->CboCodigo->currentIndex());
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
            QMessageBox msgBox;
            msgBox.setText("Curso eliminado con exito");
            msgBox.exec();

            ui->CboCodigo->removeItem(ui->CboCodigo->currentIndex());

            if(lista1->getInicio() == 0)
                ui->BtnNuevo->click();
            else
                ui->CboCodigo->activated(ui->CboCodigo->currentIndex());
        }
}

void MainWindow::on_BtnMatricular_clicked()
{
    lista1->Matricular(ui->TxtCodigo->text().toInt());
    ui->CboCodigo->activated(ui->CboCodigo->currentIndex());
}

void MainWindow::on_BtnGuardar_clicked()
{
    lista1->guardarArchivoAleatorio();
}

/*****************************LABORATORIOS*************************************/

void MainWindow::on_CboCodigo_2_activated(int index)
{
    int codigo = ui->CboCodigo_2->currentText().toInt();
    Curso * encontrado = lista2->buscarCurso2(codigo);

    ui->TxtCodigo_2->setText(QString::number(encontrado->getCodigo()));
    ui->TxtNombre_2->setText(QString(encontrado->getNombre()));
    ui->TxtMatriculados_2->setText(QString::number(encontrado->getMatriculados()));
    ui->TxtHora_2->setText(QString(encontrado->getHora()));
    ui->TxtAula_2->setText(QString::number(((Laboratorio *)encontrado)->getNumLaboratorio()));
    ui->TxtCatedratico_2->setText(QString(((Laboratorio *)encontrado)->getInstructor()));
    ui->TxtDias_2->setText(QString::number(((Laboratorio *)encontrado)->getDias()));
    ui->TxtCupo_2->setText(QString::number(encontrado->getCupo() - encontrado->getMatriculados()));
}

void MainWindow::on_BtnNuevo_2_clicked()
{
    ui->TxtCodigo_2->setText("");
    ui->TxtNombre_2->setText("");
    ui->TxtMatriculados_2->setText("");
    ui->TxtHora_2->setText("");
    ui->TxtAula_2->setText("");
    ui->TxtCatedratico_2->setText("");
    ui->TxtDias_2->setText("");
    ui->TxtCupo_2->setText("");
    ui->CboCodigo_2->setCurrentIndex(-1);
    ui->TxtCodigo_2->setFocus();
}

void MainWindow::on_BtnAgregar_2_clicked()
{
    int codigo=ui->TxtCodigo_2->text().toInt();
    if(lista2->buscarCurso(codigo)){
       QMessageBox msgbox;
       msgbox.setText("Laboratorio ya existe");
       msgbox.exec();
       return;
    }

    if (codigo == 0)
    {
        QMessageBox msgbox;
        msgbox.setText("Datos vacios, no puede agregar");
        msgbox.exec();
        ui->TxtCodigo_2->setFocus();
        return;
    }

    QString Qnombre=ui->TxtNombre_2->text();
    char * nombre=new char[strlen(Qnombre.toStdString().c_str())+1];
    strcpy(nombre,Qnombre.toStdString().c_str());

    int matriculados=ui->TxtMatriculados_2->text().toInt();

    QString Qhora=ui->TxtHora_2->text();
    char * hora= new char[strlen(Qnombre.toStdString().c_str())+1];
    strcpy(hora,Qhora.toStdString().c_str());

    int aula=ui->TxtAula_2->text().toInt();

    if((aula >= 1) &&  (aula <= 10))
    {

    }
    else
    {
        QMessageBox msgbox;
        msgbox.setText("Laboratorio no valido, ingrese un valor entre 1 y 10");
        msgbox.exec();
        ui->TxtAula_2->setFocus();
        return;
    }

    QString Qcatedratico=ui->TxtCatedratico_2->text();
    char * catedratico= new char[strlen(Qcatedratico.toStdString().c_str())+1];
    strcpy(catedratico,Qcatedratico.toStdString().c_str());

    int dias=ui->TxtDias_2->text().toInt();

    Curso * nuevo= new Laboratorio(codigo,nombre,matriculados,hora,aula,catedratico);
    nuevo->imprimir();
    cout<<endl;
    ui->CboCodigo_2->addItem(ui->TxtCodigo_2->text());
    lista2->insertar(codigo,nombre,matriculados,hora,aula,catedratico);

    QMessageBox msgBox;
    msgBox.setText("Laboratorio agregado con exito");
    msgBox.exec();

    ui->CboCodigo_2->setCurrentIndex(ui->CboCodigo_2->findText(QString::number(codigo)));
    ui->CboCodigo_2->activated(ui->CboCodigo_2->currentIndex());

    delete nuevo;
}

void MainWindow::on_BtnModificar_2_clicked()
{
    int codigo=ui->TxtCodigo_2->text().toInt();

    QString Qnombre=ui->TxtNombre_2->text();
    char * nombre=new char[strlen(Qnombre.toStdString().c_str())+1];
    strcpy(nombre,Qnombre.toStdString().c_str());

    int matriculados=ui->TxtMatriculados_2->text().toInt();

    QString Qhora=ui->TxtHora_2->text();
    char * hora= new char[strlen(Qnombre.toStdString().c_str())+1];
    strcpy(hora,Qhora.toStdString().c_str());

    int aula=ui->TxtAula_2->text().toInt();
    if((aula >= 1) &&  (aula <= 10))
    {

    }
    else
    {
        QMessageBox msgbox;
        msgbox.setText("Laboratorio no valido, ingrese un valor entre 1 y 10");
        msgbox.exec();
        ui->TxtAula_2->setFocus();
        return;
    }

    QString Qcatedratico=ui->TxtCatedratico_2->text();
    char * catedratico= new char[strlen(Qcatedratico.toStdString().c_str())+1];
    strcpy(catedratico,Qcatedratico.toStdString().c_str());

    int dias=ui->TxtDias_2->text().toInt();

    lista2->ModificarCurso(codigo, nombre, matriculados, hora, aula, catedratico);

    QMessageBox msgBox;
    msgBox.setText("Laboratorio modificado con exito");
    msgBox.exec();

    ui->CboCodigo_2->activated(ui->CboCodigo_2->currentIndex());
}

void MainWindow::on_BtnEliminar_2_clicked()
{
    if(ui->TxtCodigo_2->text().isEmpty())
    {
       QMessageBox msgbox;
       msgbox.setText("Codigo esta en blanco");
       msgbox.exec();
    }
    else
    {
       // int codigo = ui->TxtCodigo_2->text().toInt();
        lista2->EliminarCurso(ui->TxtCodigo_2->text().toInt());
        QMessageBox msgBox;
        msgBox.setText("Laboratorio eliminado con exito");
        msgBox.exec();

        ui->CboCodigo_2->removeItem(ui->CboCodigo_2->currentIndex());

        if(lista2->getInicio() == 0)
            ui->BtnNuevo_2->click();
        else
            ui->CboCodigo_2->activated(ui->CboCodigo_2->currentIndex());
    }
}

void MainWindow::on_BtnMatricular_2_clicked()
{
    lista2->Matricular(ui->TxtCodigo_2->text().toInt());
    ui->CboCodigo_2->activated(ui->CboCodigo_2->currentIndex());
}

void MainWindow::on_BtnGuardar_2_clicked()
{
    lista2->guardarArchivoAleatorio();
}
