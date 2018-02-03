#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//-------------------------------------------------------

    /*

    unordered_map<string,int> map1={{"a",8},{"b",9},{"c",10},{"d",11},{"m",1}};
    unordered_map<string,int> map2={{"z",2},{"a",5},{"y",3},{"x",1}};

    cout<<"->>>>>>>>>"<<this->distancia_vectoresed_map(map1,map2)<<endl;

    */


    QString texto="1";
            texto+="\n";
            texto+="2";
            texto+="\n";
            texto+="2";
            texto+="\n";

    ui->label_archivos_mas_parecidos->setText(ui->label_archivos_mas_parecidos->text()+"\n"+"1");
    ui->label_archivos_mas_parecidos->setText(ui->label_archivos_mas_parecidos->text()+"\n"+"2");
    ui->label_archivos_mas_parecidos->setText(ui->label_archivos_mas_parecidos->text()+"\n"+"3");


//-------------------------------------------------------

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    //-----datos_ventana-------
    profundidad=ui->spinBox_profundidad->text().toInt();
    link=ui->lineEdit_link->text();
    limite_link_por_pagina=ui->spinBox_limite_link_por_pagina->text().toInt();

    //----parceando............XD!!!!!!
    my_parser=new Parseador(link,profundidad,limite_link_por_pagina,this);
    my_parser->empezar();



    int numero_de_archivos=my_parser->get_num_archivos();

    my_crawler =new Crawler;
    my_crawler->set_num_archivos(numero_de_archivos);
    my_crawler->cargar_stop_words();

    for(int i=0; i<numero_de_archivos; i++){
        Archivo* p_archivo=new Archivo(i);
        p_archivo->cargar_vecFrecuencia(my_crawler->v_archivos_procesados,my_crawler->unor_map_stop_words);
    }
    cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
    cout<<my_crawler->v_archivos_procesados.size()<<endl;
    cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;


    cout<<"tamanio:"<<my_crawler->v_archivos_procesados[0]->unor_map_frecuencia.size();

    for(auto& it: my_crawler->v_archivos_procesados[0]->unor_map_frecuencia ){
        //cout<<it.first<<"---"<<it.second<<endl;
    }



}


void MainWindow::on_pushButton_exit_clicked()
{
    cout<<"muerete"<<endl;
    my_parser->m_pProceso->matar();
}


void MainWindow::on_pushButton_buscar_clicked()
{
    QString texto= ui->textEdit_texto_ingresado->toPlainText();
    ofstream file("/home/luigy/Escritorio/proyecto_final_AED/pruebas/-1.html");
    file << texto.toStdString().c_str();
    file.close();

    Proceso temp_proceso(this);
    temp_proceso.limpiar_html_busqueda(-1);

    archivos_principal=new Archivo(-1);
    archivos_principal->cargar_vecFrecuencia_busqueda(my_crawler->unor_map_stop_words);
    my_crawler->llenar_mas_cercanos(archivos_principal);
    my_crawler->imprimir_priority();
    cout<<"carajo funciona"<<endl;

}



void MainWindow::on_pushButton_index_offline_clicked()
{
    //buscar archivos index_off_line

}


void MainWindow::imprimir(){

/*

    auto& a=my_crawler->get_priority_qt();
    while( ! a.empty() )
   {
       ui->label_archivos_mas_parecidos(ui->label_archivos_mas_parecidos->text()+"\n"+QString::number(a.top().first)+".html");

       a.pop();

   }

*/
}


