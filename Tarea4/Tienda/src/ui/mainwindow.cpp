#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "./../Tienda/tienda.h"
#include "formproducto.h"
#include "formid.h"
#include <QMessageBox>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->tienda = new Tienda();
    this->ActualizarVentanaInfo();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete this->tienda;
}

void MainWindow::ActualizarVentanaInfo()
{
    QString nombre = QString::fromStdString(tienda->ObtenerNombre());
    this->ui->txtNombreTienda->setText(nombre);

    QString pagWeb = QString::fromStdString(tienda->ObtenerDireccionInternet());
    this->ui->txtPagWebTienda->setText(pagWeb);

    QString direccion = QString::fromStdString(tienda->ObtenerDireccionFisica());
    this->ui->txtDirFisTienda->setText(direccion);

    QString telefono = QString::fromStdString(tienda->ObtenerTelefono());
    this->ui->txtTelefonoTienda->setText(telefono);

    QString stringInfoTienda = QString::fromStdString(tienda->ObtenerDatosYProductos());
    ui->txtBrwsVentanaInfoTienda->setText(stringInfoTienda);
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
            this->ActualizarVentanaInfo();

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

void MainWindow::on_AgregarProducto_clicked()
{
    FormProducto formProducto(this);
    int resultado = formProducto.exec();

    if(resultado == QDialog::Accepted)
    {
        try
        {
            QString stringID = QString::fromStdString(formProducto.ObtenerID());
            QString stringExistencias = QString::fromStdString(formProducto.ObtenerExistencias());

            bool okID = false;
            bool okExistencias = false;

            int id = stringID.toInt(&okID);
            std::string nombre = formProducto.ObtenerNombre();
            int existencias = stringExistencias.toInt(&okExistencias);

            if(!okID || !okExistencias)
            {
                throw "Error";
            }

            tienda->AgregarProducto(id, nombre, existencias);
            this->ActualizarVentanaInfo();

            QMessageBox *msgbox = new QMessageBox(this);
            msgbox->setWindowTitle("Resultado");
            msgbox->setText("Se agregó el producto correctamente");
            msgbox->open();
        }

        catch(char const *message)
        {
            QMessageBox *msgbox = new QMessageBox(this);
            msgbox->setWindowTitle("Error");
            msgbox->setText("Solamente pueden utilizar caracteres numéricos para el ID y las Existencias. NO se agregó el producto");
            msgbox->open();
        }

        catch(ExcepcionNumeroNegativo &e)
        {
            QString mensajeError = e.what();
            mensajeError += " NO se agregó el producto";

            QMessageBox *msgbox = new QMessageBox(this);
            msgbox->setWindowTitle("Error");
            msgbox->setText(mensajeError);
            msgbox->open();
        }

        catch(ExcepcionProductoExistente &e)
        {
            QString mensajeError = e.what();
            mensajeError += " NO se agregó el producto";

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
        msgbox->setText("Acción cancelada. NO se agregó el producto");
        msgbox->open();
    }
}




void MainWindow::on_ModificarProducto_clicked()
{
    FormID formID(this);
    formID.AsignarInstruccionesModificar();
    int resultado = formID.exec();

    if(resultado == QDialog::Accepted)
    {
        try
        {
            QString stringID = QString::fromStdString(formID.ObtenerID());
            bool ok = false;
            int id = stringID.toInt(&ok);

            if(!ok)
            {
                throw "Error";
            }

            std::string nombre = tienda->ObtenerNombreProducto(id);
            int existencias = tienda->ObtenerExistenciasProducto(id);

            FormProducto formProducto(this);
            formProducto.CargarDatosParaModificar(id, nombre, existencias);
            int resultado2 = formProducto.exec();

            if(resultado2 == QDialog::Accepted)
            {
                std::string nuevoNombre = formProducto.ObtenerNombre();

                QString stringNuevoExistencias = QString::fromStdString(formProducto.ObtenerExistencias());
                bool ok2 = false;
                int nuevoExistencias = stringNuevoExistencias.toInt(&ok2);

                if(!ok2)
                {
                    throw "Error";
                }

                tienda->ActualizarNombreProducto(id, nuevoNombre);
                tienda->ActualizarExistenciasProducto(id, nuevoExistencias);
                this->ActualizarVentanaInfo();

                QMessageBox *msgbox = new QMessageBox(this);
                msgbox->setWindowTitle("Resultado");
                msgbox->setText("Se modificó el producto correctamente");
                msgbox->open();
            }

            else
            {
                QMessageBox *msgbox = new QMessageBox(this);
                msgbox->setWindowTitle("Resultado");
                msgbox->setText("Acción cancelada. NO se modificó el producto");
                msgbox->open();
            }

        }

        catch(char const *message)
        {
            QMessageBox *msgbox = new QMessageBox(this);
            msgbox->setWindowTitle("Error");
            msgbox->setText("Solamente pueden utilizar caracteres numéricos para el ID y las Existencias.");
            msgbox->open();
        }

        catch(ExcepcionProductoInexistente &e)
        {
            QString mensajeError = e.what();
            mensajeError += " NO se modificó el producto";

            QMessageBox *msgbox = new QMessageBox(this);
            msgbox->setWindowTitle("Error");
            msgbox->setText(mensajeError);
            msgbox->open();
        }

        catch(ExcepcionNumeroNegativo &e)
        {
            QString mensajeError = e.what();
            mensajeError += " NO se modificó el producto";

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
        msgbox->setText("Acción cancelada. NO se modificó el producto");
        msgbox->open();
    }
}

void MainWindow::on_EliminarProducto_clicked()
{
    FormID formID(this);
    formID.AsignarInstruccionesEliminar();
    int resultado = formID.exec();

    if(resultado == QDialog::Accepted)
    {
        try
        {
            QString stringID = QString::fromStdString(formID.ObtenerID());
            bool ok = false;
            int id = stringID.toInt(&ok);

            if(!ok)
            {
                throw "Error";
            }

            std::string nombre = tienda->ObtenerNombreProducto(id);
            int existencias = tienda->ObtenerExistenciasProducto(id);

            FormProducto formProducto(this);
            formProducto.CargarDatosParaEliminar(id, nombre, existencias);
            int resultado2 = formProducto.exec();

            if(resultado2 == QDialog::Accepted)
            {
                tienda->EliminarProducto(id);
                this->ActualizarVentanaInfo();

                QMessageBox *msgbox = new QMessageBox(this);
                msgbox->setWindowTitle("Resultado");
                msgbox->setText("Se eliminó el producto correctamente");
                msgbox->open();
            }

            else
            {
                QMessageBox *msgbox = new QMessageBox(this);
                msgbox->setWindowTitle("Resultado");
                msgbox->setText("Acción cancelada. NO se eliminó el producto");
                msgbox->open();
            }

        }

        catch(char const *message)
        {
            QMessageBox *msgbox = new QMessageBox(this);
            msgbox->setWindowTitle("Error");
            msgbox->setText("Solamente pueden utilizar caracteres numéricos para el ID.");
            msgbox->open();
        }

        catch(ExcepcionProductoInexistente &e)
        {
            QString mensajeError = e.what();
            mensajeError += " NO se eliminó el producto";

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
        msgbox->setText("Acción cancelada. NO se eliminó el producto");
        msgbox->open();
    }
}


void MainWindow::on_txtNombreTienda_editingFinished()
{
    std::string nuevoNombre = this->ui->txtNombreTienda->text().toStdString();
    this->tienda->ActualizarNombre(nuevoNombre);
    this->ActualizarVentanaInfo();
}


void MainWindow::on_txtPagWebTienda_editingFinished()
{
    std::string nuevaPaginaWeb = this->ui->txtPagWebTienda->text().toStdString();
    this->tienda->ActualizarDireccionInternet(nuevaPaginaWeb);
    this->ActualizarVentanaInfo();
}


void MainWindow::on_txtDirFisTienda_editingFinished()
{
    std::string nuevaDireccion = this->ui->txtDirFisTienda->text().toStdString();
    this->tienda->ActualizarDireccionFisica(nuevaDireccion);
    this->ActualizarVentanaInfo();
}


void MainWindow::on_txtTelefonoTienda_editingFinished()
{
    try
    {
        QString stringTelefono = this->ui->txtTelefonoTienda->text();
        bool ok = false;
        int numeroTelefono = stringTelefono.toInt(&ok);

        if(!ok || numeroTelefono < 0)
        {
            throw "Error";
        }

        std::string nuevoTelefono = stringTelefono.toStdString();
        this->tienda->ActualizarTelefono(nuevoTelefono);
        this->ActualizarVentanaInfo();
    }

    catch(char const *message)
    {
        QMessageBox *msgbox = new QMessageBox(this);
        msgbox->setWindowTitle("Error");
        msgbox->setText("El teléfono solamente puede contener caracteres numéricos. Los datos NO se actualizaron");
        msgbox->open();
    }
}

