#include "tienda.h"

#include <cstring>

using namespace std;

Tienda::Tienda() {
    strcpy(this->nombre, "");
    strcpy(this->direccionInternet, "");
    strcpy(this->direccionFisica, "");
    strcpy(this->telefono, "");
}

Tienda::Tienda(string nuevoNombre, string nuevaDireccionInternet, string nuevaDireccionFisica, string nuevoTelefono) {
    strcpy(this->nombre, nuevoNombre.c_str());
    strcpy(this->direccionInternet, nuevaDireccionInternet.c_str());
    strcpy(this->direccionFisica, nuevaDireccionFisica.c_str());
    strcpy(this->telefono, nuevoTelefono.c_str());
}

Tienda::~Tienda() {
    for(Producto *producto : this->productos) {
        delete producto;
    }
}

void Tienda::AgregarProducto(Producto *producto) {
    this->productos.push_back(producto);
}