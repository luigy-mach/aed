#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QColorDialog>
#include "comprensor.h"
//#include "sound.h"
#include <QSound>
#include <stdlib.h>

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

    void on_boton_Bin_clicked();

    void on_Bt_Com_clicked();

    void on_bt_Des_clicked();

private:
    Ui::MainWindow *ui;
    QPixmap * pix;
    Comprensor * compress;
    //sound *  mysound;
    QSound * mysound;
};

#endif // MAINWINDOW_H
