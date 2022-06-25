#ifndef TIENDA_H
#define TIENDA_H

#include "producto.h"
#include <string>
#include <vector>

class Tienda {
    string nombre {};
    string direccionInternet {};
    string direccionFisica {};
    string telefono {};
    vector <Producto *> productos; 

};

#endif