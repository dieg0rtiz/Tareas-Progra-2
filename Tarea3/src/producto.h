#ifndef PRDUCTO_H
#define PRDUCTO_H

#include <string>

using namespace std;

class Producto {

    int id {};
    string nombre {};
    int existencias;

    public:
    Producto(int id, string nombre, int existenxias);
    ~Producto();

};

#endif