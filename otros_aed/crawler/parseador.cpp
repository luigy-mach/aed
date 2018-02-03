#include "parseador.h"

Parseador::Parseador(QString link, int profundidad, int _limite_links, QObject *parent)
{
    m_pProceso=new Proceso(parent);
    m_link_principal=link;
    m_profundidad=profundidad;
    m_limite_links=_limite_links;
    numero_archivo=0;
    contador_index=1;

}

Parseador::~Parseador()
{
    delete m_pProceso;
}


void Parseador::empezar()
{
    //reservador para la cabeceza----------------

    this->index_links[this->m_link_principal.toStdString()]=0;

    this->descargar_link(this->m_link_principal);
    //--------------------------------------------


    int profundidad=0;
    while(profundidad < this->m_profundidad){
        this->leer_link();
        profundidad++;
    }
    cout<<"********************************************************************"<<endl;
    cout<<"******************Termino la descarga*******************************"<<endl;
    cout<<"********************************************************************"<<endl;
    this->imprimir_parser();
}



void Parseador::leer_link()
{
    //leer archivos de "/prueba"

    int total_links=cola_links.size();

    //contador universal
    for(int i=0;i<total_links;i++)
    {
        if(cola_links.front().size()<3){
            this->cola_links.pop();
            continue;
        }

        this->index_links[cola_links.front()]=contador_index;
        this->descargar_link(QString::fromStdString(cola_links.front()));
        this->cola_links.pop();
        this->contador_index++;
    }

}

void Parseador::limpiar_htmls(int  ____num_archivo)
{
    m_pProceso->limpiar_html( ____num_archivo);
}


void Parseador::descargar_link(QString _link)
{

    m_pProceso->descargar_pagina_wget(_link,this->numero_archivo);

    m_pProceso->extraer_link_de_html(QString::number(this->numero_archivo)+".html",cola_links,this->m_limite_links);

    this->limpiar_htmls(this->numero_archivo);
    this->numero_archivo+=1;

}//OK


void Parseador::imprimir_parser()
{

    cout<<"******************Generando INDEX de ARCHIVOS **********************"<<endl;
        cout<<index_links.size()<<endl;
    cout<<"********************************************************************"<<endl;

    ofstream file("/home/luigy/Escritorio/proyecto_final_AED/pruebas/index_link.txt");

    map<string,int>::iterator it;

    for(it=index_links.begin();it!=index_links.end();it++)
    {
        file<<it->first<<"      "<<it->second<<endl;
    }
    file.close();

}

int Parseador::get_num_archivos()
{
    return this->numero_archivo;
}


void Parseador::leer_solo_archivo_buffer()
{
    fstream file(ARCHIVO_BUFFER_FULL);
    string buffer;
    file >> buffer;
    cola_links.push(buffer);

    while(!file.eof()){
        file >> buffer;
        cola_links.push(buffer);
    }

    file.close();

}//OK


