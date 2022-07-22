#ifndef FORMID_H
#define FORMID_H

#include <QDialog>

namespace Ui {
class FormID;
}

class FormID : public QDialog
{
    Q_OBJECT

public:
    explicit FormID(QWidget *parent = nullptr);
    ~FormID();
    std::string ObtenerID();
    void AsignarInstruccionesModificar();
    void AsignarInstruccionesEliminar();

private:
    Ui::FormID *ui;
};

#endif // FORMID_H
