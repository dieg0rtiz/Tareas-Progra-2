#ifndef TIENDA_H
#define TIENDA_H

#include "producto.h"
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <iostream>
#include <fstream>

#include <exception>
#include "excepcionNumeroNegativo.h"
#include "excepcionProductoExistente.h"
#include "excepcionProductoInexistente.h"

class Tienda {

    // Se controla la cantidad de caracteres ingresados por medio de excepciones.
    char nombre [16] {}; // 15 caracteres para el usuario, un bit extra para guardar el caracter final \0.
    char direccionInternet [25] {}; // 24 caracteres para el usuario, un bit extra para guardar el caracter final \0.
    char direccionFisica [25] {}; // 24 caracteres para el usuario, un bit extra para guardar el caracter final \0.
    char telefono [9] {}; // 8 caracteres para el usuario, un bit extra para guardar el caracter final \0.
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
    void ActualizarNombreProducto(int id, string nuevoNombre);
    string ObtenerInformacionTienda();
    string ObtenerListaProductos();
    friend ostream& operator << (ostream &o, const Tienda *tienda);
    int ObtenerExistenciasProducto(int id);
    int GuardarDatos(string nombreArchivo);
    int CargarDatos(string nombreArchivo);
    string ObtenerDatosYProductos();
    bool VerificarProducto(int idParaVerificar);
    string ObtenerNombreProducto(int id);
};

#endif // TIENDA_H

