#ifndef DIALOG_BUTTON_INSERTAR_H
#define DIALOG_BUTTON_INSERTAR_H

#include <QDialog>
///////////////////////////////////////////
#include "recursos/defines.h"
//////////////////////////////////////////////


namespace Ui {
class Dialog_button_insertar;
}

class Dialog_button_insertar : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_button_insertar(QWidget *parent = 0);
    ~Dialog_button_insertar();

public slots:
    void on_pushButton_explorar_clicked();

    void on_pushButton_agregar_clicked();

private:
    Ui::Dialog_button_insertar *ui;

//////////////////////////////////////////////
public:
    QString modelo;
    QString descrip;
    QString dir_foto;

};

#endif // DIALOG_BUTTON_INSERTAR_H
