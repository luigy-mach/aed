#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <iostream>
#include <QTableView>
#include <QSqlRecord>
#include <QStandardItemModel>
#include <QString>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    config_table("table1");
    config_columna("only_name");
    ui->setupUi(this);

        db= QSqlDatabase::addDatabase("QPSQL");
            db.setHostName("localhost");
            db.setDatabaseName("test");
            db.setUserName("postgres");
            //db.setPassword("postgres");
            db.open();

        QSqlQuery query;
        query.exec("SELECT * FROM "+ myTable);

        //query.exec("COPY (SELECT id FROM tabletest ) TO '/tmp/backup.txt' WITH (DELIMITER '|')");

        show_in_table(query,ui->tableViewDB);

}

MainWindow::~MainWindow()
{
    db.close();
    delete ui;
}

void MainWindow::show_in_table(QSqlQuery &q, QTableView *t)
{
    int num_rows=q.size();

    QStandardItemModel *model = new QStandardItemModel(num_rows,1,this);

    int i=0;
    while(q.next())
    {
            QList<QStandardItem*> newRow;

            //QStandardItem* col1=new QStandardItem(QString::number(q.record().value(0).toInt()));
            QStandardItem* col1=new QStandardItem(q.record().value(0).toString());
            QStandardItem* col2=new QStandardItem(q.record().value(1).toString());
            QStandardItem* col3=new QStandardItem(q.record().value(2).toString());
            QStandardItem* col4=new QStandardItem(q.record().value(3).toString());
            QStandardItem* col5=new QStandardItem(q.record().value(4).toString());

            newRow.append(col1);
            newRow.append(col2);
            newRow.append(col3);
            newRow.append(col4);
            newRow.append(col5);
            model->insertRow(i,newRow);
            i++;
    }

    t->setModel(model);
}

void MainWindow::clean_table(QTableView *t)
{
    std::cout<< "LIMPIANDO TABLA "<<std::endl;

    t->clearSpans();
    ui->tableViewRespuesta->clearSpans();
}

void MainWindow::on_pushButton_contains_clicked()
{

    if(!ui->lineEdit_contains->text().isEmpty())
    {
        std::cout<< "CONTAINS EJECUTANDO "<<std::endl;
        QSqlQuery queryy(db);
        QString entrada=ui->lineEdit_contains->text();
        QString consulta="SELECT * FROM "+ myTable +" WHERE CONTAINS("+myCol+",'"+ entrada +"')";
        std::cout<<consulta.toStdString()<<std::endl;
        queryy.exec(consulta);
        show_in_table(queryy,ui->tableViewRespuesta);
    }
    else
         clean_table(ui->tableViewRespuesta);

}


void MainWindow::on_pushButton_similar_clicked()
{
    int distance= ui->spinBox_similar_distance->value()+1;

    if(!ui->lineEdit_similar->text().isEmpty() && distance)
    {
        std::cout<< "SIMILAR EJECUTANDO "<<std::endl;
        QSqlQuery queryy(db);
        QString entrada=ui->lineEdit_similar->text();
        QString consulta="SELECT * FROM "+ myTable +" WHERE similar5_to("+myCol+",'"+ entrada +"',"+ QString::number(distance) +")";
        std::cout<<consulta.toStdString()<<std::endl;
        queryy.exec(consulta);
        show_in_table(queryy,ui->tableViewRespuesta);
    }
    else
        clean_table(ui->tableViewRespuesta);
}



void MainWindow::config_table(QString t)
{
    myTable = t;
}

void MainWindow::config_columna(QString t)
{
    myCol=t;
}



