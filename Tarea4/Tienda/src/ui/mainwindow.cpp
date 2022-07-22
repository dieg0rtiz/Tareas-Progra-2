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

    QString stringInfoTienda = QString::fromStdString(tienda->ObtenerDatosYProductos());
    ui->txtBrwsVentanaInfoTienda->setText(stringInfoTienda);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete this->tienda;
}

void MainWindow::on_pushButton_clicked()
{

}

void MainWindow::on_ActualizarDatos_clicked()
{
    std::string nombre = tienda->ObtenerNombre();
    std::string direccionInternet = tienda->ObtenerDireccionInternet();
    std::string direccionFisica = tienda->ObtenerDireccionFisica();
    std::string telefono = tienda->ObtenerTelefono();

    FormDatosTienda formDatos{this};
    formDatos.CargarDatos(nombre, direccionInternet, direccionFisica, telefono);
    int result = formDatos.exec();

    if(result == QDialog::Accepted)
    {
        try
        {
            QString stringTelefono = QString::fromStdString(formDatos.ObtenerTelefono());
            bool ok = false;
            int numeroTelefono = stringTelefono.toInt(&ok);

            if(!ok || numeroTelefono < 0)
            {
                throw "Error";
            }

            this->tienda->ActualizarNombre(formDatos.ObtenerNombre());
            this->tienda->ActualizarDireccionInternet(formDatos.ObtenerPaginaWeb());
            this->tienda->ActualizarDireccionFisica(formDatos.ObtenerDireccionFisica());
            this->tienda->ActualizarTelefono(formDatos.ObtenerTelefono());

            QString stringInfoTienda = QString::fromStdString(tienda->ObtenerDatosYProductos());
            ui->txtBrwsVentanaInfoTienda->setText(stringInfoTienda);

            QMessageBox *msgbox = new QMessageBox(this);
            msgbox->setWindowTitle("Resultado");
            msgbox->setText("Los datos se han actualizado");
            msgbox->open();
        }

        catch(char const *message)
        {
            QMessageBox *msgbox = new QMessageBox(this);
            msgbox->setWindowTitle("Error");
            msgbox->setText("El teléfono solamente puede contener caracteres numéricos.\nLos datos NO se actualizaron");
            msgbox->open();
        }

        catch(ExcepcionCantidadDeCaracteresTienda &e)
        {
            QString mensajeError = e.what();

            QMessageBox *msgbox = new QMessageBox(this);
            msgbox->setWindowTitle("Error");
            msgbox->setText(mensajeError);
            msgbox->open();
        }

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
        int resultado = tienda->CargarDatos(name);

        if(resultado == 0)
        {
            QString stringInfoTienda = QString::fromStdString(tienda->ObtenerDatosYProductos());
            ui->txtBrwsVentanaInfoTienda->setText(stringInfoTienda);

            QMessageBox *msgbox = new QMessageBox(this);
            msgbox->setWindowTitle("Resultado");
            msgbox->setText("Se cargaron los datos del archivo " + fileName);
            msgbox->open();
        }

        else
        {
            QMessageBox *msgbox = new QMessageBox(this);
            msgbox->setWindowTitle("Error");
            msgbox->setText("No se pudo abrir el archivo " + fileName + "\n Los datos NO se cargaron.");
            msgbox->open();
        }
    }
}

void MainWindow::on_Guardar_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    "Guardar archivo de datos",
                                                    "",
                                                    tr("Archivo de datos (*.dat);;All Files (*)")
                                                    );
    if(fileName != "")
    {
        std::string name = fileName.toStdString();
        int resultado = tienda->GuardarDatos(name);

        if(resultado == 0)
        {
            QString stringInfoTienda = QString::fromStdString(tienda->ObtenerDatosYProductos());
            ui->txtBrwsVentanaInfoTienda->setText(stringInfoTienda);

            QMessageBox *msgbox = new QMessageBox(this);
            msgbox->setWindowTitle("Resultado");
            msgbox->setText("Se guardaron los datos en el archivo " + fileName);
            msgbox->open();
        }

        else
        {
            QMessageBox *msgbox = new QMessageBox(this);
            msgbox->setWindowTitle("Error");
            msgbox->setText("No se pudo abrir el archivo " + fileName + "\n Los datos NO se guardaron.");
            msgbox->open();
        }
    }
}

