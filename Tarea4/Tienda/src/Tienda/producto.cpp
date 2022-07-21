#include "producto.h"

#include <cstring>

Producto::Producto() {

}

Producto::Producto(int id, string nombre, int existencias){
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
