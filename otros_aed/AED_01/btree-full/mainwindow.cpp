#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
#include <QMessageBox>
#include <stdio.h>
#include <string>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_bdnew_clicked()
{
    QDir q;
    QString l="c:DB/"+ui->txt_DBnew->text();
    q.mkdir(l);
    QMessageBox m;
    m.setWindowTitle("OK");
    m.setText("Se creo la BD correctamente");
    m.exec();

}

void MainWindow::on_btn_tablenew_clicked()
{
    string a=ui->txt_tablenew->text().toStdString();
    a.append(".txt");
    string l;
    l="c:DB/"+ui->txt_useDB->text().toStdString()+"/";
    l+=a;
    FILE *f=fopen(l.c_str(),"w");
    string s="Documento: ";
    s.append(a);
    s.append("\n");
    fwrite(s.c_str(),1,s.length(),f);
    fclose(f);
    QMessageBox m;
    m.setWindowTitle("OK");
    m.setText("Se creo la tabla correctamente");
    m.exec();
}

