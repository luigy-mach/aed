#include "mainwindow.h"
#include "ui_mainwindow.h"
/////////////////////////////////////////

/////////////////////////////////////////
using namespace std;


#define TAM_NODO 20



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

 //---------------------------------------------------------

    scene= new QGraphicsScene(this);

//---------------------------------------------------------

    //scene->addLine(10,10,550,550,pen);

    ui->graphicsView_pantalla->setScene(scene);





    //scene->addEllipse(30,30,130,130,pen,paleta.color());


    ui->graphicsView_pantalla->setScene(scene);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::dibujar_nodo(double x,double y, string text, QBrush paleta, QPen pen){

    scene->addEllipse(x+TAM_NODO/2,y+TAM_NODO/2,TAM_NODO,TAM_NODO,pen,paleta.color());
    QGraphicsTextItem * io = new QGraphicsTextItem;
        io->setPos(x+TAM_NODO/2,y+TAM_NODO/2);
        io->setPlainText(QString::fromStdString(text));
    scene->addItem(io);


    ui->graphicsView_pantalla->setScene(scene);
}


//vector< pair<int,int> > MainWindow::dibujar_puntos(){


void MainWindow::on_pushButton_random_clicked()
{


    QBrush paleta;
    paleta.setColor(Qt::white);
    QPen pen;
    pen.setColor(Qt::black);

    for(int i=0;i<20;i++)
        dibujar_nodo(rand()%1000,rand()%1000,"3",paleta,pen);

    //ui->graphicsView_pantalla->cle
}
