/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *ActualizarDatos;
    QLabel *labelVentanaInfoTienda;
    QPushButton *AbrirArchivo;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        ActualizarDatos = new QPushButton(centralwidget);
        ActualizarDatos->setObjectName(QString::fromUtf8("ActualizarDatos"));
        ActualizarDatos->setGeometry(QRect(250, 60, 121, 24));
        labelVentanaInfoTienda = new QLabel(centralwidget);
        labelVentanaInfoTienda->setObjectName(QString::fromUtf8("labelVentanaInfoTienda"));
        labelVentanaInfoTienda->setGeometry(QRect(30, 30, 201, 91));
        AbrirArchivo = new QPushButton(centralwidget);
        AbrirArchivo->setObjectName(QString::fromUtf8("AbrirArchivo"));
        AbrirArchivo->setGeometry(QRect(270, 20, 80, 24));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        ActualizarDatos->setText(QCoreApplication::translate("MainWindow", "Actualizar Datos", nullptr));
        labelVentanaInfoTienda->setText(QString());
        AbrirArchivo->setText(QCoreApplication::translate("MainWindow", "Abrir Archivo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
