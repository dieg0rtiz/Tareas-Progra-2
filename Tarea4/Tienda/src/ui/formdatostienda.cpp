#include "formdatostienda.h"
#include "ui_formdatostienda.h"

FormDatosTienda::FormDatosTienda(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FormDatosTienda)
{
    ui->setupUi(this);
}

FormDatosTienda::~FormDatosTienda()
{
    delete ui;
}

void FormDatosTienda::CargarDatos(std::string nuevoNombre, std::string nuevaPaginaWeb, std::string nuevaDireccionFisica, std::string nuevoTelefono)
{
    QString stringNombre = QString::fromStdString(nuevoNombre);
    this->ui->txtNombre->setText(stringNombre);

    QString stringPaginaWeb = QString::fromStdString(nuevaPaginaWeb);
    this->ui->txtPaginaWeb->setText(stringPaginaWeb);

    QString stringDireccionFisica = QString::fromStdString(nuevaDireccionFisica);
    this->ui->txtDireccionFisica->setText(stringDireccionFisica);

    QString stringTelefono = QString::fromStdString(nuevoTelefono);
    this->ui->txtTelefono->setText(stringTelefono);
}

std::string FormDatosTienda::ObtenerNombre()
{
    std::string stringNombre = this->ui->txtNombre->text().toStdString();
    return stringNombre;
}

std::string FormDatosTienda::ObtenerPaginaWeb()
{
    std::string stringPaginaWeb = this->ui->txtPaginaWeb->text().toStdString();
    return stringPaginaWeb;
}

std::string FormDatosTienda::ObtenerDireccionFisica()
{
    std::string stringDireccionFisica = this->ui->txtDireccionFisica->text().toStdString();
    return stringDireccionFisica;
}

std::string FormDatosTienda::ObtenerTelefono()
{
    std::string stringTelefono = this->ui->txtTelefono->text().toStdString();
    return stringTelefono;
}
