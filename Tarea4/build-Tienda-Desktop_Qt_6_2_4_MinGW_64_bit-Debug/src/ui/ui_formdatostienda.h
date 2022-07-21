/********************************************************************************
** Form generated from reading UI file 'formdatostienda.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMDATOSTIENDA_H
#define UI_FORMDATOSTIENDA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormDatosTienda
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *labelNombre;
    QLabel *labelPaginaWeb;
    QLabel *labelDireccionFisica;
    QLineEdit *txtNombre;
    QLineEdit *txtPaginaWeb;
    QLineEdit *txtDireccionFisica;
    QLabel *labelTelefono;
    QLineEdit *txtTelefono;

    void setupUi(QDialog *FormDatosTienda)
    {
        if (FormDatosTienda->objectName().isEmpty())
            FormDatosTienda->setObjectName(QString::fromUtf8("FormDatosTienda"));
        FormDatosTienda->resize(400, 158);
        FormDatosTienda->setModal(true);
        buttonBox = new QDialogButtonBox(FormDatosTienda);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(290, 20, 81, 241));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        formLayoutWidget = new QWidget(FormDatosTienda);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 20, 271, 121));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        labelNombre = new QLabel(formLayoutWidget);
        labelNombre->setObjectName(QString::fromUtf8("labelNombre"));

        formLayout->setWidget(0, QFormLayout::LabelRole, labelNombre);

        labelPaginaWeb = new QLabel(formLayoutWidget);
        labelPaginaWeb->setObjectName(QString::fromUtf8("labelPaginaWeb"));

        formLayout->setWidget(1, QFormLayout::LabelRole, labelPaginaWeb);

        labelDireccionFisica = new QLabel(formLayoutWidget);
        labelDireccionFisica->setObjectName(QString::fromUtf8("labelDireccionFisica"));

        formLayout->setWidget(2, QFormLayout::LabelRole, labelDireccionFisica);

        txtNombre = new QLineEdit(formLayoutWidget);
        txtNombre->setObjectName(QString::fromUtf8("txtNombre"));

        formLayout->setWidget(0, QFormLayout::FieldRole, txtNombre);

        txtPaginaWeb = new QLineEdit(formLayoutWidget);
        txtPaginaWeb->setObjectName(QString::fromUtf8("txtPaginaWeb"));

        formLayout->setWidget(1, QFormLayout::FieldRole, txtPaginaWeb);

        txtDireccionFisica = new QLineEdit(formLayoutWidget);
        txtDireccionFisica->setObjectName(QString::fromUtf8("txtDireccionFisica"));

        formLayout->setWidget(2, QFormLayout::FieldRole, txtDireccionFisica);

        labelTelefono = new QLabel(formLayoutWidget);
        labelTelefono->setObjectName(QString::fromUtf8("labelTelefono"));

        formLayout->setWidget(3, QFormLayout::LabelRole, labelTelefono);

        txtTelefono = new QLineEdit(formLayoutWidget);
        txtTelefono->setObjectName(QString::fromUtf8("txtTelefono"));

        formLayout->setWidget(3, QFormLayout::FieldRole, txtTelefono);


        retranslateUi(FormDatosTienda);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, FormDatosTienda, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, FormDatosTienda, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(FormDatosTienda);
    } // setupUi

    void retranslateUi(QDialog *FormDatosTienda)
    {
        FormDatosTienda->setWindowTitle(QCoreApplication::translate("FormDatosTienda", "Actualizar los datos de la tienda", nullptr));
        labelNombre->setText(QCoreApplication::translate("FormDatosTienda", "Nombre", nullptr));
        labelPaginaWeb->setText(QCoreApplication::translate("FormDatosTienda", "P\303\241gina Web", nullptr));
        labelDireccionFisica->setText(QCoreApplication::translate("FormDatosTienda", "Direcci\303\263n F\303\255sica", nullptr));
        labelTelefono->setText(QCoreApplication::translate("FormDatosTienda", "Telefono", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormDatosTienda: public Ui_FormDatosTienda {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMDATOSTIENDA_H
