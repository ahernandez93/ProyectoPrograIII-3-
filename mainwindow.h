#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "listaClase.h"
#include "listalaboratorio.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_BtnAgregar_clicked();

private:
    Ui::MainWindow *ui;
    listaClase * lista1;
    ListaLaboratorio * lista2;

};

#endif // MAINWINDOW_H
