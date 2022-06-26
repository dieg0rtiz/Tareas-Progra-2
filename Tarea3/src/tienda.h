#ifndef TIENDA_H
#define TIENDA_H

#include "producto.h"
#include <string>
#include <vector>

class Tienda {

    char nombre [15] {};
    char direccionInternet [24] {};
    char direccionFisica [24] {};
    char telefono [8] {};
    vector <Producto *> productos; 

    public:
    Tienda();

    Tienda(string nuevoNombre, string nuevaDireccionInternet, string nuevaDireccionFisica, string nuevoTelefono);

    ~Tienda();

    void AgregarProducto(Producto *producto);

};

#endif