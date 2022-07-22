#include "formproducto.h"
#include "ui_formproducto.h"

FormProducto::FormProducto(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FormProducto)
{
    ui->setupUi(this);
}

FormProducto::~FormProducto()
{
    delete ui;
}

std::string  FormProducto::ObtenerID()
{
    std::string stringID = this->ui->txtID->text().toStdString();
    return stringID;
}

std::string FormProducto::ObtenerNombre()
{
    std::string stringNombre = this->ui->txtNombre->text().toStdString();
    return stringNombre;
}

std::string FormProducto::ObtenerExistencias()
{
    std::string stringExistencias = this->ui->txtExistencias->text().toStdString();
    return stringExistencias;
}

void FormProducto::CargarDatosParaModificar(int id, std::string nombre, int existencias)
{
    this->ui->labelInstrucciones->setText("Modifique los datos del producto");

    QString stringID = QString::number(id);
    this->ui->txtID->setText(stringID);
    this->ui->txtID->setReadOnly(true);
    this->ui->labelIDInfo->setText("El ID no puede modificarse");

    QString stringNombre = QString::fromStdString(nombre);
    this->ui->txtNombre->setText(stringNombre);

    QString stringExistencias = QString::number(existencias);
    this->ui->txtExistencias->setText(stringExistencias);
}

void FormProducto::CargarDatosParaEliminar(int id, std::string nombre, int existencias)
{
    this->ui->labelInstrucciones->setText("Por favor confirme que desea eliminar este producto");

    QString stringID = QString::number(id);
    this->ui->txtID->setText(stringID);
    this->ui->txtID->setReadOnly(true);
    this->ui->labelIDInfo->setText("");

    QString stringNombre = QString::fromStdString(nombre);
    this->ui->txtNombre->setText(stringNombre);
    this->ui->txtNombre->setReadOnly(true);
    this->ui->labelNombreInfo->setText("");

    QString stringExistencias = QString::number(existencias);
    this->ui->txtExistencias->setText(stringExistencias);
    this->ui->txtExistencias->setReadOnly(true);
    this->ui->labelExistenciasInfo->setText("");
}
