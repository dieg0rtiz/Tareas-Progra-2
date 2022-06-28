#ifndef TIENDA_H
#define TIENDA_H

#include "producto.h"
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <iostream>
#include <fstream>

class Tienda {

    char nombre [15] {};
    char direccionInternet [24] {};
    char direccionFisica [24] {};
    char telefono [8] {};
    map<int, Producto *> indiceProductos;

    public:
    Tienda();
    Tienda(string nuevoNombre, string nuevaDireccionInternet, string nuevaDireccionFisica, string nuevoTelefono);
    ~Tienda();
    string ObtenerNombre();
    string ObtenerDireccionInternet();
    string ObtenerDireccionFisica();
    string ObtenerTelefono();
    void ActualizarNombre(string nuevoNombre);
    void ActualizarDireccionInternet(string nuevaDireccionInternet);
    void ActualizarDireccionFisica(string nuevaDireccionFisica);
    void ActualizarTelefono(string nuevoTelefono);
    void AgregarProducto(int id, string nombre, int existencias);
    void AgregarProducto(Producto *producto);
    string ObtenerInformacionProducto(int id);
    void EliminarProducto(int id);
    void ActualizarExistenciasProducto(int id, int nuevaCantidad);
    string ObtenerInformacionTienda();
    string ObtenerListaProductos();
    friend ostream& operator << (ostream &o, const Tienda *tienda);
    int ObtenerExistenciasProducto(int id);
    int GuardarDatos(string nombreArchivo);
    int CargarDatos(string nombreArchivo);
};

#endif