#include "organizacion.h"
#include <iostream>
#include <sstream>
#include <string>

Organizacion::Organizacion() {

}

Organizacion::Organizacion(Empleado *nuevoDirector) {
    this->director = nuevoDirector;
    this->director->AsignarSupervisor(nuevoDirector);
    this->indiceEmpleados.insert( std::pair<int, Empleado *>(nuevoDirector->ObtenerID(), this->director) );
}

Organizacion::~Organizacion() {
    delete this->director;
}

void Organizacion::AgregarEmpleado(Empleado *nuevoEmpleado, int idSupervisor) {
    
    Empleado *supervisor = this->indiceEmpleados.at(idSupervisor);

    supervisor->AgregarSubordinado(nuevoEmpleado);

    nuevoEmpleado->AsignarSupervisor(supervisor);

    this->indiceEmpleados.insert( std::pair<int, Empleado *>(nuevoEmpleado->ObtenerID(), nuevoEmpleado) );
}

Empleado *Organizacion::ObtenerEmpleado(int idEmpleado) {
    return this->indiceEmpleados.at(idEmpleado);
}

float Organizacion::ObtenerSubTotalAPagar() {
    float total = 0;
    for ( auto const& [id,empleado] : this->indiceEmpleados) {
        total += empleado->ObtenerTotalAPagar();
    }
    return total;
}

float Organizacion::ObtenerImpuestosTotales() {
    float total = 0;
    for ( auto const& [id,empleado] : this->indiceEmpleados) {
        total += empleado->ObtenerImpuestosARetener();
    }
    return total;
}

ostream& operator << (ostream &o, const Organizacion *organizacion) {

    for ( auto const& [id,empleado] : organizacion->indiceEmpleados) {
        o << empleado << endl;
    }

    return o;
}