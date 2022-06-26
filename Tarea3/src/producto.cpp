#include "producto.h"

#include <cstring>

Producto::Producto(){
    this->id = 0;
    strcpy(this->nombre, "");
    this->existencias = 0;
}

Producto::Producto(int id, string nombre, int existencias){
    this->id = id;
    strcpy(this->nombre, nombre.c_str());
    this->existencias = existencias;
}

Producto::~Producto(){

}