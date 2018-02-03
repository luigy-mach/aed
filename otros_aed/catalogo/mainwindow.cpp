#include "mainwindow.h"
#include "ui_mainwindow.h"
///////////////////////////////////
#include <QFile>
#include<QTextStream>
#include<QMessageBox>
#include<qprocess.h>
/////////////////////////////////
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /////////////////////////////
    ui->comboBox_estructuras->addItem("avl");
    ui->comboBox_estructuras->addItem("Lista doble");
    ui->comboBox_estructuras->addItem("Red-black");
    ////////////////////////////
    pRactual=NULL;
    abrir_foto=NULL;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_insetar_clicked()
{

    abrir_foto=new Dialog_button_insertar(this);
    abrir_foto->setModal(true);
    abrir_foto->show();
        abrir_foto->exec();
    QString modelo=abrir_foto->modelo;
    QString descripcion=abrir_foto->descrip;
    QString dir_foto=abrir_foto->dir_foto;
    agregar_record(modelo.toStdString(),descripcion.toStdString(),dir_foto.toStdString());
}

void MainWindow::on_pushButton_index_clicked()
{
    //AGREGAR INDEX SEGUN ESTRUCURA
    int index=ui->comboBox_estructuras->currentIndex();
    switch (index) {
        case 0: f=new AVL< Record* >();
                    break;
        case 1: f=new ListaD< Record* >();
                    break;
        case 2: //f=new RedBblack< Record* >();
                    break;
        }
    open_file(DATABASETXT);
    indexing(f);
    f->print_dot();
    close_file();
    on_pushButton_inicio_clicked();
}

void MainWindow::on_pushButton_buscar_clicked()
{

    //----------------------------------------------
    secs = (double)(t_fin - t_ini) / CLOCKS_PER_SEC;
    QString text=ui->lineEdit_buscar->text();
    if(text!= ""){
        Record* in=new Record(text.toStdString());
        Record* out=NULL;
        //***
            t_ini = clock();
        f->find(in,out);
        pRactual=out;
            t_fin = clock();
        //***
        if(out==NULL)
            mostrar_error("no se ah encontrado:"+ui->lineEdit_buscar->text());
        delete in;
        //----------------------------
        int available;
        string mo,de,ph;
        //----------------------------
        open_file(DATABASETXT);
        seekg_record(*out);
        read_file();
        read_buffer(available,mo,de,ph);
        if(available==0)
            mostrar_error("**fue borrado "+ui->lineEdit_buscar->text());
        mostrar_modelo(QString::fromStdString(mo));
        mostrar_descripcion(QString::fromStdString(de));
        mostrar_foto(DIRFOTOS+QString::fromStdString(ph));
        close_file();
    }
    else
        mostrar_error("no se ah encontrado:"+ui->lineEdit_buscar->text());
    //-----------------------------------------------
    secs = (double)(t_fin - t_ini)/(double)CLOCKS_PER_SEC;
    ui->label_tiempo_buscar->setText(QString::number(secs,'f',8) + " seg.");


}



void MainWindow::on_pushButton_final_clicked()
{
    Record** out=f->maximo();
    pRactual=*out;
    //----------------------------
    int available;
    string mo,de,ph;
    //----------------------------
    open_file(DATABASETXT);
    seekg_record(**out);
    read_file();
    read_buffer(available,mo,de,ph);
    if(available==0)
        mostrar_error("**fue borrado "+ui->lineEdit_buscar->text());
    mostrar_modelo(QString::fromStdString(mo));
    mostrar_descripcion(QString::fromStdString(de));
    mostrar_foto(DIRFOTOS+QString::fromStdString(ph));
    cout<<"-----------------"<<ph<<"<<<"<< DIRFOTOS<<ph<<endl;
    close_file();

}

void MainWindow::on_pushButton_siguiente_clicked()
{
    if(!pRactual)return;
    Record** out=f->siguiente(pRactual);
    pRactual=*out;
    //----------------------------
    int available;
    string mo,de,ph;
    //----------------------------
    open_file(DATABASETXT);
    seekg_record(**out);
    read_file();
    read_buffer(available,mo,de,ph);
    if(available==0)
        mostrar_error("**fue borrado "+ui->lineEdit_buscar->text());
    mostrar_modelo(QString::fromStdString(mo));
    mostrar_descripcion(QString::fromStdString(de));
    mostrar_foto(DIRFOTOS+QString::fromStdString(ph));
    cout<<"-----------------"<<ph<<"<<<"<< DIRFOTOS<<ph<<endl;
    close_file();

}

void MainWindow::on_pushButton_anterior_clicked()
{
    if(!pRactual)return;
    Record** out=f->anterior(pRactual);
    pRactual=*out;
    //----------------------------
    int available;
    string mo,de,ph;
    //----------------------------
    open_file(DATABASETXT);
    seekg_record(**out);
    read_file();
    read_buffer(available,mo,de,ph);
    if(available==0)
        mostrar_error("**fue borrado "+ui->lineEdit_buscar->text());
    mostrar_modelo(QString::fromStdString(mo));
    mostrar_descripcion(QString::fromStdString(de));
    mostrar_foto(DIRFOTOS+QString::fromStdString(ph));
    cout<<"-----------------"<<ph<<"<<<"<< DIRFOTOS<<ph<<endl;
    close_file();
}

void MainWindow::on_pushButton_inicio_clicked()
{
    Record** out=f->minimo();
    pRactual=*out;
    //----------------------------
    int available;
    string mo,de,ph;
    //----------------------------
    open_file(DATABASETXT);
    seekg_record(**out);
    read_file();
    read_buffer(available,mo,de,ph);
    if(available==0)
        mostrar_error("**fue borrado "+ui->lineEdit_buscar->text());
    mostrar_modelo(QString::fromStdString(mo));
    mostrar_descripcion(QString::fromStdString(de));
    mostrar_foto(DIRFOTOS+QString::fromStdString(ph));
    cout<<"-----------------"<<ph<<"<<<"<< DIRFOTOS<<ph<<endl;
    close_file();

}

void MainWindow::on_pushButton_borrar_clicked()
{
    QString text=ui->lineEdit_buscar->text();
    Record* in=NULL;
        (text.isEmpty())? in=pRactual:in=new Record(text.toStdString());
    Record* out=NULL;
    f->find(in,out);
    seekp_off(*out);
}


///***********************************************************
///***********************************************************

void MainWindow::mostrar_modelo(QString modelo)
{
    ui->label_modelo->setText(modelo);
}

void MainWindow::mostrar_descripcion(QString descripcion)
{
    ui->textBrowser_descripcion->setText(descripcion);
}

void MainWindow::mostrar_foto(QString dir_foto)
{
        QPixmap pix(dir_foto);
        ui->label_foto->setPixmap(pix.scaled(ui->label_foto->width(),ui->label_foto->height()));
}
void MainWindow::mostrar_error(QString mensaje)
{
    QMessageBox::information(this,"Error",mensaje);
}

void MainWindow::agregar_record(string mo,string de,string dir_f)
{
    buffer="1"+mo+"#"+de+"#"+dir_f+"@";
    pRfinal_archivo->model=mo;
    pRfinal_archivo->begin +=pRfinal_archivo->sizeoff+1;
    pRfinal_archivo->pos +=1;

    fstream database2(DATABASETXT,ios::out | ios::in );
    database2.seekp(1, ios::end);
    database2.put('x');
    database2.close();

}


///////////////////////////////////////////////////////////////
//--------------------LECTURA-------------------------
int MainWindow::char_to_int(char a){return a-48;}

int MainWindow::length_buffer() {return buffer.length();}

bool MainWindow::open_file(string file){
    database.open(file.c_str(), ios::in | ios::out );
    return	!database.fail()?true:false;
}

void MainWindow::read_file(){std::getline(database,buffer,'@');}

void MainWindow::close_file(){database.close();}

void MainWindow::read_buffer(int& available,string& model,string& description, string& photo ){
    std::string::iterator it=buffer.begin();
    available=char_to_int(*it);
    it++;
    while(*it!='#') {model+=*it;it++;}
    it++;
    while(*it!='#') {description+=*it;it++;}
    it++;
    while(it!=buffer.end()) {photo+=*it;it++;}
}

int MainWindow::read_available(){
    std::string::iterator it=buffer.begin();
    return char_to_int(*it);
}

string MainWindow::read_model(){
    std::string::iterator it=buffer.begin()+1;
    std::string temp;
    for(;*it!='#';it++)temp+=*it;
    return temp;
}

void MainWindow::indexing(Estructura< Record* >*& f){ //solo indexa available=1;
    int pos=0;//<<<<<<<<<<<------------
    for(int i=0;!database.eof();i++){
        read_file();
        if(buffer.length()<3) return;
        Record* t=new Record();
        t->available=read_available();
        t->model=read_model();
        t->begin=pos+i;
        t->sizeoff=length_buffer();
        t->pos=i;
        pos+=t->sizeoff;
        if(t->available==0) {delete t; continue;}
        pRfinal_archivo=t;
        f->insertar(t);
        cout<<t->available<<"--"<<t->model<<"--"<<t->begin<<"--"<<t->sizeoff<<endl;
    }
}

//-------------------------------------------------------
void MainWindow::seekg_record(Record& r){
    database.seekg(r.begin, ios::beg);
}

void MainWindow::seekp_off(Record& r){
    fstream database2(DATABASETXT,ios::out | ios::in );
    database2.seekp(r.begin, ios::beg);
    database2.put('0');
    database2.close();
}


void MainWindow::seekp_on(Record& r){
    fstream database2(DATABASETXT,ios::out | ios::in );
    database2.seekp(r.begin, ios::beg);
    database2.put('1');
    database2.close();
}

///***********************************************************
///***********************************************************

void MainWindow::on_pushButton_index_2_clicked()
{
    system(EJECUTAR_DOT);
    system(EVINCE);

}
