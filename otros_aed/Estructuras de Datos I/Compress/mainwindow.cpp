
#include "ui_mainwindow.h"
#include "mainwindow.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    pix = new QPixmap(ui->ImgColor->size());
    compress = new Comprensor();
    QString soundFile(QApplication::applicationDirPath());
    soundFile.append("sonido.wav");
    QSound::play(soundFile);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete pix;
    delete compress;
}

void MainWindow::on_pushButton_clicked()
{

    pix->fill();
    QFileDialog * ventana = new QFileDialog();
    QString filename = ventana->getOpenFileName(this,tr("Open File"),"/home/josemiki/Escritorio/Compress-build-desktop/",tr("Files(*.png *.xpm *.jpg)"));
    string a = filename.toStdString();
    compress->setOriFile(a);
    pix->load(filename,"png/jpg");
    ui->ImgColor->setPixmap(*(pix));
    delete ventana;
}

void MainWindow::on_boton_Bin_clicked()
{
    compress->binarisar();
    QFileDialog * ventana = new QFileDialog();
    QString filename = ventana->getSaveFileName(this,tr("Save File"), "/home/josemiki/Escritorio/Compress-build-desktop/" ,tr("Files (*.txt *.png *.xpm *.jpg)"));
    compress->setBcimgFile(filename.toStdString());
    compress->save_cimg_bin();
    compress->showBin();
    pix->fill();
    pix->load("binarizado","png");
    ui->ImgBin->setPixmap(*(pix));
    delete ventana;
}

void MainWindow::on_Bt_Com_clicked()
{

    compress->quadt->setMat(compress->bina->getMatriz());
    compress->quadt->setH(255);
    compress->quadt->setW(255);
    compress->quadt->subdividir(compress->quadt->getRoot());
    QFileDialog * ventana = new QFileDialog();
    QString filename = ventana->getSaveFileName(this,tr("Save File"), "/home/josemiki/Escritorio/Compress-build-desktop/" ,tr("Files (*.txt *.png *.xpm *.jpg)"));
    compress->setCompFile(filename.toStdString());
    cout<<"file :"<<filename.toStdString()<<endl;
    compress->save_comp(compress->quadt->getRoot());
    delete ventana;
}

void MainWindow::on_bt_Des_clicked()
{

    QFileDialog * ventana = new QFileDialog();
    QString filename = ventana->getOpenFileName(this,tr("Save File"), "/home/josemiki/Escritorio/Compress-build-desktop/" ,tr("Files (*.txt *.png *.xpm *.jpg)"));
    compress->setbmyFle(filename.toStdString());
    compress->descomprimir();
    compress->save_des();
    compress->bina->mostrar_img(filename.toStdString());
    pix->fill();
    pix->load("nuevo","png");
    ui->imgRes->setPixmap(*(pix));
    delete ventana;
}
