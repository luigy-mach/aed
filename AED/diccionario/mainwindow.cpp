#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QStandardItemModel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //////////////////////////////////////////////////////////

    ui->comboBox_index->addItem("avl");
    ui->comboBox_index->addItem("lista doble");
    ui->comboBox_index->addItem("red black");

    //___________________________________________

    connect(ui->listWidget_parecidos, SIGNAL(itemPressed(QListWidgetItem*)),
            this, SLOT(mostrar_traduccion_de_similar(QListWidgetItem*)));
    //////////////////////////////////////////////////////////

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_buscar_clicked()
{
    int num_similitud=ui->spinBox_num_semejanza->text().toInt();


    QString text=ui->lineEdit_buscar->text();
    if(text!= ""){

        secs = (double)(t_fin - t_ini) / CLOCKS_PER_SEC;
        //******************************************************
            mostrar_traduccion_clear();
            Record* in=new Record(text.toStdString());
            Record* out=NULL;
            //***
                t_ini = clock();
            f->find(in,out);
                t_fin = clock();
            //***
            if(!out){
                buscar_similares(*in,num_similitud);
                //mostrar_error("no se ah encontrado:"+ui->lineEdit_buscar->text();
            }else{
                delete in;
                //----------------------------

                open_file(DATABASETXT);
                for(out->it=out->traduccion.begin();out->it!=out->traduccion.end();out->it++){
                    string pa,tr;
                    seekg_word(*(out->it));
                    read_file();
                    read_buffer(pa,tr);
                    cout<<"....."<<tr<<endl;
                    mostrar_traduccion(QString::fromStdString(tr));
                }
            }
            close_file();
        //******************************************************
        secs = (double)(t_fin - t_ini)/(double)CLOCKS_PER_SEC;
        ui->label_show_time->setText(QString::number(secs,'f',8) + " seg.");
    }
    else
        mostrar_error("no ah ingresado ninguna busqueda:");
}


void MainWindow::on_pushButton_index_clicked()
{
    enum index{avl=0,listadoble,redblack};
    index valor= (index)ui->comboBox_index->currentIndex();
    switch (valor){
    case avl: f=new AVL< Record* >();
        break;
    case listadoble: f=new ListaD< Record* >();
        break;
    case redblack://---------------------
        break;
    }
    open_file(DATABASETXT);
    indexing(f);
    f->print_dot();
    close_file();

}

void MainWindow::on_pushButton_mostrar_index_clicked()
{
    system(EJECUTAR_DOT);
    system(EVINCE_INDEX);

}


void MainWindow::mostrar_traduccion_de_similar(QListWidgetItem* item)
{
    mostrar_traduccion_clear();
    ui->listWidget_parecidos->currentItem()->text();
    int index = ui->listWidget_parecidos->currentRow();
    Record* temp=v_similares[index];

    open_file(DATABASETXT);
    string pa,tr;
    for(temp->it=temp->traduccion.begin();temp->it!=temp->traduccion.end();temp->it++){
            cout<<"entro a leer"<<endl;
            seekg_word(*(temp->it));
            read_file();
            read_buffer(pa,tr);
            cout<<"....."<<tr<<endl;
            mostrar_traduccion(QString::fromStdString(tr));
     }
    close_file();

}

///***********************************************************
///***********************************************************

int MainWindow::levenshtein(const string &s1, const string &s2)
{
   int N1 = s1.size();
   int N2 = s2.size();
   int i, j;
   vector<int> T(N2+1);

   for ( i = 0; i <= N2; i++ )
      T[i] = i;

   for ( i = 0; i < N1; i++ )
   {
      T[0] = i+1;
      int corner = i;
      for ( j = 0; j < N2; j++ )
      {
         int upper = T[j+1];
         if ( s1[i] == s2[j] )
            T[j+1] = corner;
         else
            T[j+1] = min(T[j], min(upper, corner)) + 1;
         corner = upper;
      }
   }
   return T[N2];
}


void MainWindow::buscar_similares(Record& in,int num_similitud){

    Record* it=*(f->minimo());
    for( ; it->operator!=(*(f->maximo())) ; it=*(f->siguiente(it)) ){
        int l = levenshtein( in.word , it->word );
        if(l==num_similitud){
            cout<<"*********"<<it->word<<endl;
            v_similares.push_back(it);
        }
    }

    vector< Record* >::iterator ite;
    for(ite=v_similares.begin();ite!=v_similares.end();ite++)
        ui->listWidget_parecidos->addItem(QString::fromStdString((*ite)->word));
}


void MainWindow::mostrar_traduccion(QString traduccion)
{
    ui->textBrowser_taduccion->append(traduccion);
    ui->textBrowser_taduccion->append("\n ****************************** \n");
}


void MainWindow::mostrar_traduccion_clear()
{
    ui->textBrowser_taduccion->clear();
}


void MainWindow::mostrar_error(QString mensaje)
{
    QMessageBox::information(this,"Error",mensaje);
}

///////////////////////////////////////////////////////////////
//--------------------LECTURA-------------------------

int MainWindow::length_buffer() {return buffer.length();}

bool MainWindow::open_file(string file){
    database.open(file.c_str(), ios::in | ios::out );
    return	!database.fail()?true:false;
}

void MainWindow::close_file(){database.close();}

void MainWindow::read_file(){std::getline(database,buffer,'\n');}

void MainWindow::read_buffer(string& palabra,string& traduccion){
    std::string::iterator it=buffer.begin();
    while(*it!='#') {palabra+=*it;it++;}
    it++;
    while(it!=buffer.end()) {traduccion+=*it;it++;}
}

string MainWindow::read_palabra(){
    std::string::iterator it=buffer.begin();
    std::string temp;
    for(;*it!='#';it++)temp+=*it;
    return temp;
}

void MainWindow::indexing(Estructura< Record* >*& f){ //solo indexa palabra en ingles
    int pos=0;//<<<<<<<<<<<------------
    for(int i=0;!database.eof();i++){
        read_file();
        if(buffer.length()<3) break;
        //************************
        Word* t=new Word();
        t->word=read_palabra();
        t->begin=pos+i;
        t->sizeoff=length_buffer();
        t->pos=i;
        pos+=t->sizeoff;
        //************************
        Record* out=NULL;
        Record* in=new Record();
                in->word=read_palabra();
        f->find(in,out);
        if(!out){
            in->traduccion.push_back(*t);
            f->insertar(in);
        }else{
            delete in;
            out->traduccion.push_back(*t);
        }
        cout<<">>>  "<<t->word<<endl;
    }
}

//-------------------------------------------------------
void MainWindow::seekg_word(Word& w){
    database.seekg(w.begin, ios::beg);
}


///***********************************************************
///***********************************************************




