#include "proceso.h"


Proceso::Proceso(QObject *parent=0)
        :QProcess(parent)
{
}


void Proceso::descargar_pagina_wget(QString _link, int num_output_archivo)
{
    //************************************************************
    QStringList argumentos;
        QString link= _link;
        QString out ="-O" ;
        QString ubicacion=UBICACION+QString::number(num_output_archivo) +".html";
    argumentos.append(link);
    argumentos.append(out);
    argumentos.append(ubicacion);

    this->start(COMAND_WGET,argumentos);
    this->espera_a_q_termine();

    /*for(int i=0;i<argumentos.size();i++)
        cout<<argumentos[i].toStdString()<<" ";*/
    //************************************************************
    /*QString comando="wget ";
            comando+=_link;
            comando+=" -O";
            comando+=QString::fromStdString(ubicacion);/*

    this->start("sh", QStringList() << "-c" << comando);
    this->waitForFinished();
    */
    //************************************************************
}

void Proceso::extraer_link_de_html(QString _archivo_con_html,queue<string>& _cola_links,int _limite_link_por_pagina)
{
    //************************************************************
    /*this->startDetached("lynx -dump -listonly \"/home/luigy/Escritorio/proyecto_final_AED/pruebas/0.html\" | grep -o \"http:.*\" | grep -E -v \"http://google.com|http://www.google.com\" > salida.txt");
    this->waitForFinished();
    cout<<"lynx -dump -listonly \"/home/luigy/Escritorio/proyecto_final_AED/pruebas/0.html\" | grep -o \"http:.*\" | grep -E -v \"http://google.com|http://www.google.com\" > salida.txt"<<endl;
    cout<<"funciona_mrd"<<endl;*/

    /*QStringList a;
    QString cero="lynx";
    QString uno="-dump";
    QString dos="-listonly";
    QString tres="\"/home/luigy/Escritorio/proyecto_final_AED/pruebas/0.html\" > /home/luigy/Escritorio/proyecto_final_AED/pruebas/temp1.txt";

    a.append(cero);
    a.append(uno);
    a.append(dos);
    a.append(tres);

    for(int i=0;i<a.size();i++)
        cout<<a[i].toStdString()<<" ";
    this->start("/usr/bin/lynx",a);*/
    //************************************************************

    //QString comando="lynx -dump -listonly \""+ ubicacion + _archivo_con_html.toStdString() +"\" | grep -o \"http:.*\" | grep -E -v \"http://google.com|http://www.google.com\" > /home/luigy/Escritorio/proyecto_final_AED/pruebas/"+ ARCHIVO_BUFFER;

   // QString _archivo_con_html="0.html";

    //this->start("sh", QStringList() << "-c" << "lynx -dump -listonly \"/home/luigy/Escritorio/proyecto_final_AED/pruebas/0.html\" > /home/luigy/Escritorio/proyecto_final_AED/pruebas/temp1.txt");

    //************************************************************
    QString comando="lynx -dump -listonly \"";
            comando+=QString::fromStdString(ubicacion);
            comando+=_archivo_con_html;
            comando+="\" | grep -o \"http:.*\" | grep -E -v \"http://google.com|http://www.google.com\" > ";
            comando+=QString::fromStdString(archivo_buffer_full);

    this->start("sh", QStringList() << "-c" << comando);
    this->espera_a_q_termine();


   //*********  ***************************************************
    ifstream file(ARCHIVO_BUFFER_FULL);
        string buffer;

    file >> buffer;
    _cola_links.push(buffer);

    int i=0;
    while(!file.eof()&& i<_limite_link_por_pagina-2){

        file >> buffer;
        if(buffer.size()<3){
            cout<<"tiene menos de 3 caracteres"<<endl;
            continue;
        }
        _cola_links.push(buffer);
         i++;
    }

    file.close();

    //************************************************************
    /*
    this->waitForFinished();
    QStringList b;
    b<<"-o" << "\"http:.*\""<<"/home/luigy/Escritorio/proyecto_final_AED/pruebas/temp1.txt"<< ">"<< "temp2.txt";
    for(int i=0;i<b.size();i++)
        cout<<b[i].toStdString()<<" ";
    this->start("grep",b);

    this->waitForFinished();
    QStringList c;
    c<<"-E"<< "-v"<< "\"http://google.com|http://www.google.com\""<<"/home/luigy/Escritorio/proyecto_final_AED/pruebas/temp2.txt"<<">" << "/home/luigy/Escritorio/proyecto_final_AED/pruebas/salida.txt";
    for(int i=0;i<c.size();i++)
        cout<<c[i].toStdString()<<" ";
    this->start("grep",c);
    */

    //************************************************************

    //string comando="lynx -dump -listonly \""+ ubicacion + _archivo_con_html.toStdString() +"\" | grep -o \"http:.*\" | grep -E -v \"http://google.com|http://www.google.com\" > /home/luigy/Escritorio/proyecto_final_AED/pruebas/"+ ARCHIVO_BUFFER;
    //string comando="lynx -dump -listonly \""+ ubicacion + _archivo_con_html.toStdString() +"\" | grep -o \"http:.*\" | grep -E -v \"http://google.com|http://www.google.com\" > /home/luigy/Escritorio/proyecto_final_AED/pruebas/"+ ARCHIVO_BUFFER;
    //system(comando.c_str());
    //system("gedit");

   /* QStringList x;
    x<<"-qC"<<"lynx -dump -listonly \"/home/luigy/Escritorio/proyecto_final_AED/pruebas/0.thml\" | grep -o \"http:.*\" | grep -E -v \"http://google.com|http://www.google.com\" > /home/luigy/Escritorio/proyecto_final_AED/pruebas/temp1.txt";
    this->start("/bin/sh",x);*/

    //this->waitForFinished();

    //************************************************************
    cout<<"descargando----> link  del "<<_archivo_con_html.toStdString()<<endl;
    //************************************************************
}

void Proceso::limpiar_html(int  _num_output_archivo)
{
    QString comando_1="lynx --dump \"";
            comando_1+=QString::fromStdString(ubicacion);
            comando_1+=QString::number(_num_output_archivo);
            comando_1+=".html";
            comando_1+="\" > ";
            comando_1+=QString::fromStdString(ubicacion_temp_1_txt);
            comando_1+=QString::number(_num_output_archivo);
            comando_1+=".txt";

    this->start("sh", QStringList() << "-c" << comando_1);
    this->espera_a_q_termine();


    QString comando_2="./fil_work ";
            comando_2+=QString::fromStdString(ubicacion_temp_1_txt);
            comando_2+=QString::number(_num_output_archivo);
            comando_2+=".txt";
            comando_2+=" | tail -n +2  > ";
            //| head -n -1
            comando_2+=QString::fromStdString(ubicacion_txt);
            comando_2+=QString::number(_num_output_archivo);
            comando_2+=".txt";
    this->setWorkingDirectory("/home/luigy/Escritorio/proyecto_final_AED/pruebas");
    this->start("sh", QStringList() << "-c" << comando_2);
    this->espera_a_q_termine();
}



void Proceso::limpiar_html_busqueda(int  _num_output_archivo)
{
    QString comando_1="lynx --dump \"";
            comando_1+=QString::fromStdString(ubicacion);
            comando_1+=QString::number(_num_output_archivo);
            comando_1+=".html";
            comando_1+="\" > ";
            comando_1+=QString::fromStdString(ubicacion_temp_1_txt);
            comando_1+=QString::number(_num_output_archivo);
            comando_1+=".txt";

    this->start("sh", QStringList() << "-c" << comando_1);
    this->espera_a_q_termine();


    QString comando_2="./fil_work ";
            comando_2+=QString::fromStdString(ubicacion_temp_1_txt);
            comando_2+=QString::number(_num_output_archivo);
            comando_2+=".txt";
            comando_2+=" | tail -n +2 > ";
            comando_2+=QString::fromStdString(ubicacion_txt);
            comando_2+=QString::number(_num_output_archivo);
            comando_2+=".txt";
    this->setWorkingDirectory("/home/luigy/Escritorio/proyecto_final_AED/pruebas");
    this->start("sh", QStringList() << "-c" << comando_2);
    this->espera_a_q_termine();
}


void Proceso::matar()
{

    cout<<"**********************************MUERE MELA***************************"<<endl;
    cout<<"**********************************MUERE MELA***************************"<<endl;
    cout<<"**********************************MUERE MELA***************************"<<endl;
    string comando="killall -9 crawler";
    system(comando.c_str());
}

void Proceso::espera_a_q_termine()
{
    this->waitForFinished(120000);
}

