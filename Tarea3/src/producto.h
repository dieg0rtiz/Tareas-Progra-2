#ifndef PRDUCTO_H
#define PRDUCTO_H

#include <string>

using namespace std;

class Producto {

    int id {};
    char nombre [20] {};
    int existencias;

    public:
    Producto();
    Producto(int id, string nombre, int existenxias);
    ~Producto();

};

#endif