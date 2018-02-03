#include "dialog_button_insertar.h"
#include "ui_dialog_button_insertar.h"
///////////////////////////////////////////
#include <QFileDialog>

///////////////////////////////////////////
Dialog_button_insertar::Dialog_button_insertar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_button_insertar)
{
    ui->setupUi(this);
    //////////////////////////////////////////////
    dir_foto="";
    //////////////////////////////////////////////
}

Dialog_button_insertar::~Dialog_button_insertar()
{
    delete ui;
}

void Dialog_button_insertar::on_pushButton_explorar_clicked()
{
        dir_foto=QFileDialog::getOpenFileName(
                    this,
                    tr("foto"),
                    DIRFOTOS,
                    "todos los archivos(*.*);; imagen(*.jpg)"
                    );

}

void Dialog_button_insertar::on_pushButton_agregar_clicked()
{
   modelo=this->ui->lineEdit_modelo->text();
   descrip=this->ui->lineEdit_descripcion->text();
   this->hide();
}
