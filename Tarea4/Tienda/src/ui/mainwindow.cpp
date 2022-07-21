#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "./../Tienda/tienda.h"
#include "formdatostienda.h"
#include <QMessageBox>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->tienda = new Tienda();

    QString stringInfoTienda = QString::fromStdString(tienda->ObtenerInformacionTienda());
    ui->labelVentanaInfoTienda->setText(stringInfoTienda);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete this->tienda;
}


void MainWindow::on_ActualizarDatos_clicked()
{
    std::string nombre = tienda->ObtenerNombre();
    std::string direccionInternet = tienda->ObtenerNombre();
    std::string direccionFisica = tienda->ObtenerNombre();
    std::string telefono = tienda->ObtenerNombre();

    FormDatosTienda formDatos{this};
    formDatos.CargarDatos(nombre, direccionInternet, direccionFisica, telefono);
    int result = formDatos.exec();

    if(result == QDialog::Accepted)
    {
        this->tienda->ActualizarNombre(formDatos.ObtenerNombre());
        this->tienda->ActualizarDireccionInternet(formDatos.ObtenerPaginaWeb());
        this->tienda->ActualizarDireccionFisica(formDatos.ObtenerDireccionFisica());
        this->tienda->ActualizarTelefono(formDatos.ObtenerTelefono());

        QString stringInfoTienda = QString::fromStdString(tienda->ObtenerInformacionTienda());
        ui->labelVentanaInfoTienda->setText(stringInfoTienda);

        QMessageBox *msgbox = new QMessageBox(this);
        msgbox->setWindowTitle("Resultado");
        msgbox->setText("Los datos se han actualizado");
        msgbox->open();
    }
    else
    {
        QMessageBox *msgbox = new QMessageBox(this);
        msgbox->setWindowTitle("Resultado");
        msgbox->setText("Acción cancelada. Los datos NO se actualizaron");
        msgbox->open();
    }
}
void MainWindow::on_AbrirArchivo_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    "Abrir archivo de datos",
                                                    "",
                                                    tr("Archivo de datos (*.dat);;All Files (*)")
                                                    );
    if(fileName != "")
    {
        std::string name = fileName.toStdString();
        tienda->CargarDatos(name);

        QMessageBox *msgbox = new QMessageBox(this);
        msgbox->setWindowTitle("Título del diálogo");
        msgbox->setText(fileName);
        msgbox->open();
    }
}

