#ifndef FORMPRODUCTO_H
#define FORMPRODUCTO_H

#include <QDialog>

namespace Ui {
class FormProducto;
}

class FormProducto : public QDialog
{
    Q_OBJECT

public:
    explicit FormProducto(QWidget *parent = nullptr);
    ~FormProducto();
    std::string ObtenerID();
    std::string ObtenerNombre();
    std::string ObtenerExistencias();
    void CargarDatosParaModificar(int ID, std::string nombre, int existencias);
    void CargarDatosParaEliminar(int ID, std::string nombre, int existencias);

private:
    Ui::FormProducto *ui;
};

#endif // FORMPRODUCTO_H
