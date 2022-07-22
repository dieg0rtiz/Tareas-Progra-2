#include "formid.h"
#include "ui_formid.h"

FormID::FormID(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FormID)
{
    ui->setupUi(this);
}

FormID::~FormID()
{
    delete ui;
}

std::string FormID::ObtenerID()
{
    std::string stringID = this->ui->txtID->text().toStdString();
    return stringID;
}

void FormID::AsignarInstruccionesModificar()
{
    this->ui->labelInstrucciones1->setText("Ingrese el ID del producto que desea modificar");
}

void FormID::AsignarInstruccionesEliminar()
{
    this->ui->labelInstrucciones1->setText("Ingrese el ID del producto que desea eliminar");
}
