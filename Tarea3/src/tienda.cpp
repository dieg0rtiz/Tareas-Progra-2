#include "tienda.h"

#include <cstring>

using namespace std;

Tienda::Tienda(string nuevoNombre, string nuevaDireccionInternet, string nuevaDireccionFisica, string nuevoTelefono) {
    strcpy(this->nombre, nuevoNombre.c_str());
    strcpy(this->direccionInternet, nuevaDireccionInternet.c_str());
    strcpy(this->direccionFisica, nuevaDireccionFisica.c_str());
    strcpy(this->telefono, nuevoTelefono.c_str());
}

Tienda::~Tienda() {
    for (auto const& [id,producto] : this->indiceProductos) {
        delete producto;
    }
}

string Tienda::ObtenerNombre() {
    return this->nombre;
}

string Tienda::ObtenerDireccionFisica() {
    return this->direccionFisica;
}

string Tienda::ObtenerDireccionInternet() {
    return this->direccionInternet;
}

string Tienda::ObtenerTelefono() {
    return this->telefono;
}

void Tienda::AgregarProducto(int id, string nombre, int existencias) {
    Producto *producto = new Producto(id, nombre, existencias);
    this->indiceProductos.insert( pair<int, Producto *>(producto->ObtenerID(), producto) );
}

void Tienda::EliminarProducto(int id) {
    delete this->indiceProductos.at(id);
    this->indiceProductos.erase(id);
}

string Tienda::ObtenerInformacionProducto(int id) {
    return this->indiceProductos.at(id)->ObtenerInformacionProducto();
}

void Tienda::ActualizarExistenciasProducto(int id, int nuevaCantidad) {
    this->indiceProductos.at(id)->ActualizarExistencias(nuevaCantidad);
}

string Tienda::ObtenerInformacionTienda() {
    stringstream strm("");

    strm << "Nombre: " << this->nombre << endl;
    strm << "Página Web: " << this->direccionInternet << endl;
    strm << "Dirección Física: " << this->direccionFisica << endl;
    strm << "Teléfono: " << this->telefono << endl;

    return strm.str();
}

string Tienda::ObtenerListaProductos() {
    stringstream strm("");

    strm << "ID,Nombre,Existencias" << endl;

    for (auto const& [id,producto] : this->indiceProductos) {
        strm << producto << endl;
    }

    return strm.str();
}

ostream& operator << (ostream &o, const Tienda *tienda) {

    o << "Nombre: " << tienda->nombre << endl;
    o << "Página Web: " << tienda->direccionInternet << endl;
    o << "Dirección Física: " << tienda->direccionFisica << endl;
    o << "Teléfono: " << tienda->telefono << endl;
    o << endl;
    o << "Lista de Productos: " <<  endl;
    o << "ID,Nombre,Existencias" << endl;

    for (auto const& [id,producto] : tienda->indiceProductos) {
        o << producto << endl;
    }

    return o;
}

int Tienda::ObtenerExistenciasProducto(int id) {
    return this->indiceProductos.at(id)->ObtenerExistencias();
}