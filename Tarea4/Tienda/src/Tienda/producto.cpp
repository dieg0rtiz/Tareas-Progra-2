#include "producto.h"
#include "espacios.h"

#include <cstring>
#include <string>

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
    Espacios *espacios = new Espacios();
    string nombreString = producto->nombre;

    o
    << producto->id << "    "
    << producto->nombre << espacios->AgregarEspacios(4 + sizeof(producto->nombre) - nombreString.size())
    << producto->existencias;

    delete espacios;
    return o;
}

string Producto::ObtenerInformacionProducto() {
    stringstream strm("");
    strm << this;
    return strm.str();
}
