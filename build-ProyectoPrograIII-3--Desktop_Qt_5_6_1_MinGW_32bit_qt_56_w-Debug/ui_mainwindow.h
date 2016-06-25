/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QPushButton *BtnNuevo;
    QPushButton *BtnModificar;
    QPushButton *BtnEliminar;
    QPushButton *BtnMatricular;
    QPushButton *BtnAbrir;
    QPushButton *BtnGuardar;
    QPushButton *BtnBuscar;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *label;
    QLineEdit *TxtCatedratico;
    QLabel *label_4;
    QLineEdit *TxtMatriculados;
    QLineEdit *TxtDias;
    QLineEdit *TxtNombre;
    QLabel *label_6;
    QLabel *label_2;
    QLabel *label_5;
    QLineEdit *TxtCodigo;
    QLineEdit *TxtHora;
    QLineEdit *TxtAula;
    QLabel *label_3;
    QLabel *label_7;
    QWidget *tab_2;
    QLineEdit *TxtMatriculados_2;
    QLabel *label_8;
    QLineEdit *TxtNombre_2;
    QLabel *label_13;
    QLineEdit *TxtDias_2;
    QLineEdit *TxtCodigo_2;
    QLineEdit *TxtCatedratico_2;
    QLabel *label_9;
    QLabel *label_10;
    QLineEdit *TxtAula_2;
    QLabel *label_14;
    QLabel *label_11;
    QLineEdit *TxtHora_2;
    QLabel *label_12;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(397, 410);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(0, 400, 75, 23));
        BtnNuevo = new QPushButton(centralWidget);
        BtnNuevo->setObjectName(QStringLiteral("BtnNuevo"));
        BtnNuevo->setGeometry(QRect(300, 90, 91, 41));
        BtnModificar = new QPushButton(centralWidget);
        BtnModificar->setObjectName(QStringLiteral("BtnModificar"));
        BtnModificar->setGeometry(QRect(300, 140, 91, 41));
        BtnEliminar = new QPushButton(centralWidget);
        BtnEliminar->setObjectName(QStringLiteral("BtnEliminar"));
        BtnEliminar->setGeometry(QRect(300, 190, 91, 41));
        BtnMatricular = new QPushButton(centralWidget);
        BtnMatricular->setObjectName(QStringLiteral("BtnMatricular"));
        BtnMatricular->setGeometry(QRect(300, 240, 91, 41));
        BtnAbrir = new QPushButton(centralWidget);
        BtnAbrir->setObjectName(QStringLiteral("BtnAbrir"));
        BtnAbrir->setGeometry(QRect(60, 300, 121, 41));
        BtnGuardar = new QPushButton(centralWidget);
        BtnGuardar->setObjectName(QStringLiteral("BtnGuardar"));
        BtnGuardar->setGeometry(QRect(200, 300, 131, 41));
        BtnBuscar = new QPushButton(centralWidget);
        BtnBuscar->setObjectName(QStringLiteral("BtnBuscar"));
        BtnBuscar->setGeometry(QRect(300, 40, 91, 41));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 291, 281));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 20, 37, 16));
        TxtCatedratico = new QLineEdit(tab);
        TxtCatedratico->setObjectName(QStringLiteral("TxtCatedratico"));
        TxtCatedratico->setGeometry(QRect(90, 170, 171, 20));
        label_4 = new QLabel(tab);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 110, 43, 20));
        TxtMatriculados = new QLineEdit(tab);
        TxtMatriculados->setObjectName(QStringLiteral("TxtMatriculados"));
        TxtMatriculados->setGeometry(QRect(90, 80, 51, 20));
        TxtDias = new QLineEdit(tab);
        TxtDias->setObjectName(QStringLiteral("TxtDias"));
        TxtDias->setGeometry(QRect(90, 200, 51, 20));
        TxtNombre = new QLineEdit(tab);
        TxtNombre->setObjectName(QStringLiteral("TxtNombre"));
        TxtNombre->setGeometry(QRect(90, 50, 171, 20));
        label_6 = new QLabel(tab);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 170, 61, 20));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 50, 43, 20));
        label_5 = new QLabel(tab);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 140, 43, 20));
        TxtCodigo = new QLineEdit(tab);
        TxtCodigo->setObjectName(QStringLiteral("TxtCodigo"));
        TxtCodigo->setGeometry(QRect(90, 20, 51, 20));
        TxtHora = new QLineEdit(tab);
        TxtHora->setObjectName(QStringLiteral("TxtHora"));
        TxtHora->setGeometry(QRect(90, 110, 51, 20));
        TxtAula = new QLineEdit(tab);
        TxtAula->setObjectName(QStringLiteral("TxtAula"));
        TxtAula->setGeometry(QRect(90, 140, 51, 20));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 80, 71, 20));
        label_7 = new QLabel(tab);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(20, 200, 43, 20));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        TxtMatriculados_2 = new QLineEdit(tab_2);
        TxtMatriculados_2->setObjectName(QStringLiteral("TxtMatriculados_2"));
        TxtMatriculados_2->setGeometry(QRect(100, 80, 51, 20));
        label_8 = new QLabel(tab_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(20, 20, 37, 16));
        TxtNombre_2 = new QLineEdit(tab_2);
        TxtNombre_2->setObjectName(QStringLiteral("TxtNombre_2"));
        TxtNombre_2->setGeometry(QRect(100, 50, 171, 20));
        label_13 = new QLabel(tab_2);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(20, 170, 61, 20));
        TxtDias_2 = new QLineEdit(tab_2);
        TxtDias_2->setObjectName(QStringLiteral("TxtDias_2"));
        TxtDias_2->setGeometry(QRect(100, 200, 51, 20));
        TxtCodigo_2 = new QLineEdit(tab_2);
        TxtCodigo_2->setObjectName(QStringLiteral("TxtCodigo_2"));
        TxtCodigo_2->setGeometry(QRect(100, 20, 51, 20));
        TxtCatedratico_2 = new QLineEdit(tab_2);
        TxtCatedratico_2->setObjectName(QStringLiteral("TxtCatedratico_2"));
        TxtCatedratico_2->setGeometry(QRect(100, 170, 171, 20));
        label_9 = new QLabel(tab_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(20, 50, 43, 20));
        label_10 = new QLabel(tab_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(20, 80, 71, 20));
        TxtAula_2 = new QLineEdit(tab_2);
        TxtAula_2->setObjectName(QStringLiteral("TxtAula_2"));
        TxtAula_2->setGeometry(QRect(100, 140, 51, 20));
        label_14 = new QLabel(tab_2);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(20, 200, 43, 20));
        label_11 = new QLabel(tab_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(20, 110, 43, 20));
        TxtHora_2 = new QLineEdit(tab_2);
        TxtHora_2->setObjectName(QStringLiteral("TxtHora_2"));
        TxtHora_2->setGeometry(QRect(100, 110, 51, 20));
        label_12 = new QLabel(tab_2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(20, 140, 81, 20));
        tabWidget->addTab(tab_2, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 397, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Control Academico", 0));
        pushButton->setText(QApplication::translate("MainWindow", "PushButton", 0));
        BtnNuevo->setText(QApplication::translate("MainWindow", "Nuevo", 0));
        BtnModificar->setText(QApplication::translate("MainWindow", "Modificar", 0));
        BtnEliminar->setText(QApplication::translate("MainWindow", "Eliminar", 0));
        BtnMatricular->setText(QApplication::translate("MainWindow", "Matricular", 0));
        BtnAbrir->setText(QApplication::translate("MainWindow", "Abrir archivo", 0));
        BtnGuardar->setText(QApplication::translate("MainWindow", "Guardar archivo", 0));
        BtnBuscar->setText(QApplication::translate("MainWindow", "Buscar", 0));
        label->setText(QApplication::translate("MainWindow", "Codigo:", 0));
        label_4->setText(QApplication::translate("MainWindow", "Hora:", 0));
        label_6->setText(QApplication::translate("MainWindow", "Catedratico:", 0));
        label_2->setText(QApplication::translate("MainWindow", "Nombre:", 0));
        label_5->setText(QApplication::translate("MainWindow", "Aula:", 0));
        label_3->setText(QApplication::translate("MainWindow", "Matriculados:", 0));
        label_7->setText(QApplication::translate("MainWindow", "Dias:", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Clases", 0));
        label_8->setText(QApplication::translate("MainWindow", "Codigo:", 0));
        label_13->setText(QApplication::translate("MainWindow", "Instructor:", 0));
        label_9->setText(QApplication::translate("MainWindow", "Nombre:", 0));
        label_10->setText(QApplication::translate("MainWindow", "Matriculados:", 0));
        label_14->setText(QApplication::translate("MainWindow", "Dias:", 0));
        label_11->setText(QApplication::translate("MainWindow", "Hora:", 0));
        label_12->setText(QApplication::translate("MainWindow", "No. laboratorio:", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Laboratorios", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
