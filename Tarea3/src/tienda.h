#ifndef TIENDA_H
#define TIENDA_H

#include "producto.h"
#include <string>
#include <vector>
#include <map>
#include <fstream>

class Tienda {

    char nombre [15] {};
    char direccionInternet [24] {};
    char direccionFisica [24] {};
    char telefono [8] {};
    map<int, Producto *> indiceProductos;
    ofstream archivoSalida;

    public:
    Tienda(string nuevoNombre, string nuevaDireccionInternet, string nuevaDireccionFisica, string nuevoTelefono);
    ~Tienda();
    string ObtenerNombre();
    string ObtenerDireccionInternet();
    string ObtenerDireccionFisica();
    string ObtenerTelefono();
    void AgregarProducto(int id, string nombre, int existencias);
    string ObtenerInformacionProducto(int id);
    void EliminarProducto(int id);
    void ActualizarExistenciasProducto(int id, int nuevaCantidad);
    string ObtenerInformacionTienda();
    string ObtenerListaProductos();
    friend ostream& operator << (ostream &o, const Tienda *tienda);
    int ObtenerExistenciasProducto(int id);
};

#endif