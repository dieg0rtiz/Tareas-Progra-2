#include "producto.h"
#include "espacios.h"

#include <cstring>
#include <string>

Producto::Producto() {

}

Producto::Producto(int id, string nombre, int existencias){

    if (id < 0 || existencias < 0) {
        // Escenario de excepción
        throw ExcepcionNumeroNegativo();
    }

    this->id = id;
    strncpy(this->nombre, nombre.c_str(), sizeof(this->nombre)-1);
    this->existencias = existencias;
}

Producto::~Producto(){

}

int Producto::ObtenerID(){
    return this->id;
}

string Producto::ObtenerNombre(){
    return this->nombre;
}

void Producto::ActualizarNombre(string nuevoNombre){
    strncpy(this->nombre, nuevoNombre.c_str(), sizeof(this->nombre)-1);
}

int Producto::ObtenerExistencias(){
    return this->existencias;
}

void Producto::ActualizarExistencias(int nuevaCantidad){

    if (nuevaCantidad < 0) {
        // Escenario de excepción
        throw ExcepcionNumeroNegativo();
    }

    this->existencias = nuevaCantidad;
}

ostream& operator << (ostream &o, const Producto *producto) {
    Espacios *espacios = new Espacios();
    string nombreString = producto->nombre;
    string idString = to_string(producto->id);
    string cantidadString = to_string(producto->existencias);

    o
    << producto->id << "    "
    << producto->nombre << espacios->AgregarEspacios(40 - idString.size() - 4 - nombreString.size() - cantidadString.size())
    << producto->existencias;

    delete espacios;
    return o;
}

string Producto::ObtenerInformacionProducto() {
    stringstream strm("");
    strm << this;
    return strm.str();
}

