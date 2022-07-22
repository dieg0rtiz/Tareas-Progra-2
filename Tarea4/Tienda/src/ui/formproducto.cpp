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
