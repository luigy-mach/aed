#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>



/////////////////////////////////////////
#include "iostream"
#include "QGraphicsScene"
#include "QPen"
#include "QGraphicsItem"

#include "string"

using namespace std;

/////////////////////////////////////////


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
    void on_pushButton_random_clicked();

private:
    Ui::MainWindow *ui;

    QGraphicsScene *scene;


    void dibujar_nodo(double x,double y, string text, QBrush paleta, QPen pen);


};

#endif // MAINWINDOW_H
