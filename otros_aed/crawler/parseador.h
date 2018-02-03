#ifndef PARSEADOR_H
#define PARSEADOR_H
#include "proceso.h"
#include <QString>
#include <QMap>
#include <QDebug>
#include "defines.h"
#include "includes.h"



class Parseador
{
    public:
        Proceso * m_pProceso;

        map < string,int > index_links;
        QString m_link_principal;

        int m_profundidad;
        int m_limite_links;
        int numero_archivo;
        int contador_index;

        queue<string> cola_links;

    public:

        Parseador(QString link ,int profundidad,int _limite_links=10, QObject *parent=0);
        ~Parseador();
        void empezar();
        void descargar_link(QString _link);
        void leer_solo_archivo_buffer();
        void leer_link();
        void limpiar_htmls(int ____num_archivo);
        void imprimir_parser();
        int get_num_archivos();


};

#endif // PARSEADOR_H
