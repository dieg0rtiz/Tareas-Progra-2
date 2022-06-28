#ifndef PRDUCTO_H
#define PRDUCTO_H

#include <string>
#include <sstream>

using namespace std;

class Producto {

    int id {};
    char nombre [20] {};
    int existencias {};

    public:
    Producto();
    Producto(int id, string nombre, int existencias);
    ~Producto();
    int ObtenerID();
    string ObtenerNombre();
    int ObtenerExistencias();
    void ActualizarExistencias(int nuevaCantidad);
    friend ostream& operator << (ostream &o, const Producto *producto);
    string ObtenerInformacionProducto();
};

#endif