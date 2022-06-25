#include "producto.h"

Producto::~Producto(){

}

Producto::Producto(int id, string nombre, int existencias){
    this->id = id;
    this->nombre = nombre;
    this->existencias = existencias;
}
