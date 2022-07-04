#include "producto.h"

#include <cstring>

Producto::Producto() {

}

Producto::Producto(int id, string nombre, int existencias){

    if (id < 0 || existencias < 0) {
        // Escenario de excepción
        throw ExcepcionNumeroNegativo();
    }

    if (nombre.length()>= sizeof(this->nombre)) {
        // Escenario de excepción
        throw ExcepcionCantidadDeCaracteresProducto(); 
    }

    this->id = id;
    strcpy(this->nombre, nombre.c_str());
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

    if (nuevoNombre.length()>= sizeof(this->nombre)) {
        // Escenario de excepción
        throw ExcepcionCantidadDeCaracteresProducto(); 
    }

    strcpy(this->nombre, nuevoNombre.c_str());
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
    o 
    << producto->id << "," 
    << producto->nombre << "," 
    << producto->existencias;

    return o;
}

string Producto::ObtenerInformacionProducto() {
    stringstream strm("");
    strm << this;
    return strm.str();
}