#ifndef FORMDATOSTIENDA_H
#define FORMDATOSTIENDA_H

#include <QDialog>

namespace Ui {
class FormDatosTienda;
}

class FormDatosTienda : public QDialog
{
    Q_OBJECT

public:
    explicit FormDatosTienda(QWidget *parent = nullptr);
    ~FormDatosTienda();
    void CargarDatos(std::string nuevoNombre, std::string nuevaPaginaWeb, std::string nuevaDireccionFisica, std::string nuevoTelefono);
    std::string ObtenerNombre();
    std::string ObtenerPaginaWeb();
    std::string ObtenerDireccionFisica();
    std::string ObtenerTelefono();

private:
    Ui::FormDatosTienda *ui;
};

#endif // FORMDATOSTIENDA_H
