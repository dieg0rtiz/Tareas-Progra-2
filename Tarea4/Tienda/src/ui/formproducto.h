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

private:
    Ui::FormProducto *ui;
};

#endif // FORMPRODUCTO_H
