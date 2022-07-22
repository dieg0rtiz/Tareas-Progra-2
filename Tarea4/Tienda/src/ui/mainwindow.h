#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "./../Tienda/tienda.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void ActualizarVentanaInfo();

private slots:
    void on_txtNombreTienda_editingFinished();

    void on_txtPagWebTienda_editingFinished();

    void on_txtDirFisTienda_editingFinished();

    void on_txtTelefonoTienda_editingFinished();

    void on_AgregarProducto_clicked();

    void on_ModificarProducto_clicked();

    void on_EliminarProducto_clicked();

    void on_AbrirArchivo_clicked();

    void on_Guardar_clicked();

private:
    Ui::MainWindow *ui;
    Tienda *tienda;
};
#endif // MAINWINDOW_H

