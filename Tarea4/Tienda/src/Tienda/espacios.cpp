#include "espacios.h"


Espacios::Espacios() {

}

Espacios::~Espacios() {

}

string Espacios::AgregarEspacios(int n) {
    string espacios {};
    for(int i=0; i < n; i++) {
        espacios +=" ";
    }
    return espacios;
}

