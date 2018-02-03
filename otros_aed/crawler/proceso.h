#ifndef PROCESO_H
#define PROCESO_H


#include <QProcess>
#include "includes.h"
#include "defines.h"

class Proceso : public QProcess
{

    public:
        Proceso(QObject* parent);

        void descargar_pagina_wget(QString _link, int num_output_archivo);
        void extraer_link_de_html(QString _archivo_con_html, queue<string> &_cola_links, int _limite_por_pagina);
        void limpiar_html(int  _num_output_archivo);
        void limpiar_html_busqueda(int  _num_output_archivo);
        void matar();
        void espera_a_q_termine();

};

#endif // PROCESO_H




