#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>
#include <sstream>
#include <exception>
#include "excepcionNumeroNegativo.h"

using namespace std;

class Producto {

    // Se controla la cantidad de caracteres ingresados por medio de excepciones.
    int id {};
    char nombre [21] {}; // 20 caracteres para el usuario, un bit extra para guardar el caracter final \0.
    int existencias {};

    public:
    Producto();
    Producto(int id, string nombre, int existencias);
    ~Producto();
    int ObtenerID();
    string ObtenerNombre();
    void ActualizarNombre(string nuevoNombre);
    int ObtenerExistencias();
    void ActualizarExistencias(int nuevaCantidad);
    friend ostream& operator << (ostream &o, const Producto *producto);
    string ObtenerInformacionProducto();
};

#endif // PRODUCTO_H
