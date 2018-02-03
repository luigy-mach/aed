/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon 10. Dec 13:13:05 2012
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QTabWidget *tabWidget;
    QWidget *tab_1;
    QLabel *label_3;
    QLabel *label_7;
    QLineEdit *txt_DBnew;
    QPushButton *btn_bdnew;
    QWidget *tab_2;
    QLabel *label_8;
    QLabel *label_9;
    QPushButton *btn_tablenew;
    QLineEdit *txt_tablenew;
    QLineEdit *txt_useDB;
    QLabel *label_27;
    QWidget *tab_3;
    QLabel *label_2;
    QPushButton *btn_insert1;
    QLabel *label_5;
    QComboBox *cb_tipo1;
    QLabel *label_4;
    QLineEdit *tam1;
    QLineEdit *txt_nameC1;
    QLabel *label_6;
    QPushButton *btn_insert2;
    QComboBox *cb_tipo2;
    QLineEdit *tam2;
    QLineEdit *txt_nameC2;
    QWidget *tab;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLineEdit *txt_valuescamp;
    QLineEdit *txt_valuesdata;
    QPushButton *pushButton_5;
    QWidget *tab_4;
    QLabel *label_24;
    QLineEdit *txt_select;
    QLabel *label_25;
    QLineEdit *txt_from;
    QLabel *label_26;
    QLineEdit *txt_where;
    QPushButton *pushButton_11;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(610, 364);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(160, 10, 301, 41));
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"font: italic 20pt \"David\";\n"
"text-decoration: underline;\n"
"}"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 60, 601, 261));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tab_1 = new QWidget();
        tab_1->setObjectName(QString::fromUtf8("tab_1"));
        label_3 = new QLabel(tab_1);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(140, 20, 301, 31));
        label_3->setStyleSheet(QString::fromUtf8("font: italic 20pt \"David\";\n"
"text-decoration: underline;"));
        label_7 = new QLabel(tab_1);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(30, 90, 181, 31));
        label_7->setStyleSheet(QString::fromUtf8("font: italic 20pt \"David\";"));
        txt_DBnew = new QLineEdit(tab_1);
        txt_DBnew->setObjectName(QString::fromUtf8("txt_DBnew"));
        txt_DBnew->setGeometry(QRect(250, 90, 171, 21));
        btn_bdnew = new QPushButton(tab_1);
        btn_bdnew->setObjectName(QString::fromUtf8("btn_bdnew"));
        btn_bdnew->setGeometry(QRect(460, 90, 75, 23));
        tabWidget->addTab(tab_1, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        label_8 = new QLabel(tab_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(210, 30, 141, 31));
        label_8->setStyleSheet(QString::fromUtf8("font: italic 20pt \"David\";\n"
"text-decoration: underline;"));
        label_9 = new QLabel(tab_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(40, 150, 181, 31));
        label_9->setStyleSheet(QString::fromUtf8("font: italic 20pt \"David\";"));
        btn_tablenew = new QPushButton(tab_2);
        btn_tablenew->setObjectName(QString::fromUtf8("btn_tablenew"));
        btn_tablenew->setGeometry(QRect(470, 150, 75, 23));
        txt_tablenew = new QLineEdit(tab_2);
        txt_tablenew->setObjectName(QString::fromUtf8("txt_tablenew"));
        txt_tablenew->setGeometry(QRect(260, 150, 171, 21));
        txt_useDB = new QLineEdit(tab_2);
        txt_useDB->setObjectName(QString::fromUtf8("txt_useDB"));
        txt_useDB->setGeometry(QRect(270, 100, 171, 21));
        label_27 = new QLabel(tab_2);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(50, 100, 221, 31));
        label_27->setStyleSheet(QString::fromUtf8("font: italic 20pt \"David\";"));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        label_2 = new QLabel(tab_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(170, 30, 301, 31));
        label_2->setStyleSheet(QString::fromUtf8("font: italic 20pt \"David\";\n"
"text-decoration: underline;"));
        btn_insert1 = new QPushButton(tab_3);
        btn_insert1->setObjectName(QString::fromUtf8("btn_insert1"));
        btn_insert1->setGeometry(QRect(470, 120, 75, 23));
        label_5 = new QLabel(tab_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(360, 80, 111, 31));
        label_5->setStyleSheet(QString::fromUtf8("font: italic 20pt \"David\";"));
        cb_tipo1 = new QComboBox(tab_3);
        cb_tipo1->setObjectName(QString::fromUtf8("cb_tipo1"));
        cb_tipo1->setGeometry(QRect(250, 120, 69, 22));
        label_4 = new QLabel(tab_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(250, 80, 61, 31));
        label_4->setStyleSheet(QString::fromUtf8("font: italic 20pt \"David\";"));
        tam1 = new QLineEdit(tab_3);
        tam1->setObjectName(QString::fromUtf8("tam1"));
        tam1->setGeometry(QRect(380, 120, 41, 20));
        txt_nameC1 = new QLineEdit(tab_3);
        txt_nameC1->setObjectName(QString::fromUtf8("txt_nameC1"));
        txt_nameC1->setGeometry(QRect(60, 120, 141, 20));
        label_6 = new QLabel(tab_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(80, 80, 101, 31));
        label_6->setStyleSheet(QString::fromUtf8("font: italic 20pt \"David\";"));
        btn_insert2 = new QPushButton(tab_3);
        btn_insert2->setObjectName(QString::fromUtf8("btn_insert2"));
        btn_insert2->setGeometry(QRect(470, 160, 75, 23));
        cb_tipo2 = new QComboBox(tab_3);
        cb_tipo2->setObjectName(QString::fromUtf8("cb_tipo2"));
        cb_tipo2->setGeometry(QRect(250, 160, 69, 22));
        tam2 = new QLineEdit(tab_3);
        tam2->setObjectName(QString::fromUtf8("tam2"));
        tam2->setGeometry(QRect(380, 160, 41, 20));
        txt_nameC2 = new QLineEdit(tab_3);
        txt_nameC2->setObjectName(QString::fromUtf8("txt_nameC2"));
        txt_nameC2->setGeometry(QRect(60, 160, 141, 20));
        tabWidget->addTab(tab_3, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        label_10 = new QLabel(tab);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(150, 30, 301, 31));
        label_10->setStyleSheet(QString::fromUtf8("font: italic 20pt \"David\";\n"
"text-decoration: underline;"));
        label_11 = new QLabel(tab);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(20, 100, 141, 31));
        label_11->setStyleSheet(QString::fromUtf8("font: italic 20pt \"David\";"));
        label_12 = new QLabel(tab);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(30, 140, 81, 31));
        label_12->setStyleSheet(QString::fromUtf8("font: italic 20pt \"David\";"));
        txt_valuescamp = new QLineEdit(tab);
        txt_valuescamp->setObjectName(QString::fromUtf8("txt_valuescamp"));
        txt_valuescamp->setGeometry(QRect(170, 110, 271, 20));
        txt_valuesdata = new QLineEdit(tab);
        txt_valuesdata->setObjectName(QString::fromUtf8("txt_valuesdata"));
        txt_valuesdata->setGeometry(QRect(140, 150, 301, 20));
        pushButton_5 = new QPushButton(tab);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(180, 190, 75, 23));
        tabWidget->addTab(tab, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        label_24 = new QLabel(tab_4);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(10, 40, 141, 31));
        label_24->setStyleSheet(QString::fromUtf8("font: italic 20pt \"David\";"));
        txt_select = new QLineEdit(tab_4);
        txt_select->setObjectName(QString::fromUtf8("txt_select"));
        txt_select->setGeometry(QRect(140, 40, 271, 20));
        label_25 = new QLabel(tab_4);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(50, 80, 71, 31));
        label_25->setStyleSheet(QString::fromUtf8("font: italic 20pt \"David\";"));
        txt_from = new QLineEdit(tab_4);
        txt_from->setObjectName(QString::fromUtf8("txt_from"));
        txt_from->setGeometry(QRect(140, 80, 141, 20));
        label_26 = new QLabel(tab_4);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(90, 120, 81, 31));
        label_26->setStyleSheet(QString::fromUtf8("font: italic 20pt \"David\";"));
        txt_where = new QLineEdit(tab_4);
        txt_where->setObjectName(QString::fromUtf8("txt_where"));
        txt_where->setGeometry(QRect(180, 120, 271, 20));
        pushButton_11 = new QPushButton(tab_4);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
        pushButton_11->setGeometry(QRect(170, 180, 75, 23));
        tabWidget->addTab(tab_4, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 610, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Gestor de Base de Datos", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Gestor de Base de Datos", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Crear Base de Datos", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "create databases ", 0, QApplication::UnicodeUTF8));
        btn_bdnew->setText(QApplication::translate("MainWindow", "Create", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_1), QApplication::translate("MainWindow", "Create DB", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "Crear Tabla", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "Crear Tabla", 0, QApplication::UnicodeUTF8));
        btn_tablenew->setText(QApplication::translate("MainWindow", "Create", 0, QApplication::UnicodeUTF8));
        label_27->setText(QApplication::translate("MainWindow", "USE DATABASES", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Create Table", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Insertar Campos a la Tabla", 0, QApplication::UnicodeUTF8));
        btn_insert1->setText(QApplication::translate("MainWindow", "Insertar", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Tama\303\261o", 0, QApplication::UnicodeUTF8));
        cb_tipo1->clear();
        cb_tipo1->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Int", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Varchar", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Float", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Date", 0, QApplication::UnicodeUTF8)
        );
        label_4->setText(QApplication::translate("MainWindow", "Tipo", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "Nombre", 0, QApplication::UnicodeUTF8));
        btn_insert2->setText(QApplication::translate("MainWindow", "Insertar", 0, QApplication::UnicodeUTF8));
        cb_tipo2->clear();
        cb_tipo2->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Int", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Varchar", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Float", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Date", 0, QApplication::UnicodeUTF8)
        );
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Insert", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWindow", "Insertar Valores a la Tabla", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MainWindow", "Insertar into", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MainWindow", "Values", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("MainWindow", "Insertar", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Values", 0, QApplication::UnicodeUTF8));
        label_24->setText(QApplication::translate("MainWindow", "SELECT", 0, QApplication::UnicodeUTF8));
        label_25->setText(QApplication::translate("MainWindow", "From", 0, QApplication::UnicodeUTF8));
        label_26->setText(QApplication::translate("MainWindow", "where", 0, QApplication::UnicodeUTF8));
        pushButton_11->setText(QApplication::translate("MainWindow", "Consultar", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "Consultas", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
