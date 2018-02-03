#include "mainwindow.h"
#include "QFile"
#include "ui_mainwindow.h"
#include <QStringListModel>
#include <QDebug>

void MainWindow::on_mostrar_clicked()
{
    QString namefile="data_base.txt";
    QStringList tokens;
        ifstream ifile(namefile.toStdString().c_str());
        std::string buffer;
        while(!ifile.eof())
        {
            getline(ifile,buffer);
            tokens<<QString::fromStdString(buffer);
            qDebug()<<QString::fromStdString(buffer);;
        }
        QStringListModel * model =  new QStringListModel(tokens);
        ui->tableView_tablas->setModel(model);
}
