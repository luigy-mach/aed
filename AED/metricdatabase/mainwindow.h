#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QTableView>
#include <QString>
#include <QStringList>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void show_in_table(QSqlQuery& q, QTableView *t);
    void clean_table(QTableView *t);
    void config_table(QString t);
    void select_colum(QString t);

private slots:

    void on_pushButton_contains_clicked();

    void on_pushButton_similar_clicked();

    void on_comboBox_index_activated(const QString &arg1);

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    QSqlQuery query;
    QString myTable;
    QString myCol;
    QList<QString> list_header;


};

#endif // MAINWINDOW_H
