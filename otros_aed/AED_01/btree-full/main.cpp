#include "mainwindow.h"
#include <QApplication>
#include <QDir>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QDir p;
    p.mkdir("c:DB");
    MainWindow w;
    w.show();
    
    return a.exec();
}
