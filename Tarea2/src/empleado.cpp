#include "empleado.h"

#include <sstream>

Empleado::~Empleado() {
    for(Empleado *subordinado : this->subordinados) {
        delete subordinado;
    }
}

int Empleado::ObtenerID(){
    return this->id;
}

int Empleado::ObtenerIDSupervisor(){
    return this->idSupervisor;
}

void Empleado::AsignarSupervisor(Empleado *nuevoSupervisor) {
    this->supervisor = nuevoSupervisor;
}

void Empleado::AgregarSubordinado(Empleado *nuevoSubordinado) {
    this->subordinados.push_back(nuevoSubordinado);
}

ostream& operator << (ostream &o, const Empleado *empleado) { // Solo se puede implementar en el arbol
    o 
    << empleado->id << "," 
    << empleado->nombre << " " << empleado->apellido << "," // nombre completo
    << empleado->supervisor->nombre << " " << empleado->supervisor->apellido << "," // nombre completo del supervisor
    << empleado->totalAPagar;

    return o;
}