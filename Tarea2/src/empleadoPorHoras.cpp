#include "empleadoPorHoras.h"

#include <sstream>

EmpleadoPorHoras::EmpleadoPorHoras(string entrada) {
    int nuevoID; 
    string nuevoNombre;
    string nuevoApellido;
    string nuevoEmail;
    int nuevoTipoEmpleado;
    int nuevoIDSupervisor;

    istringstream strm(entrada);

    strm >> nuevoID >> nuevoNombre >> nuevoApellido >> nuevoEmail >> nuevoTipoEmpleado >> nuevoIDSupervisor;
    
    if(nuevoTipoEmpleado == 2) {
        this->id = nuevoID;
        this->nombre = nuevoNombre;
        this->apellido = nuevoApellido;
        this->email = nuevoEmail;
        this->idSupervisor = nuevoIDSupervisor;
    }
}

void EmpleadoPorHoras::AgregarDatosDePago(string entrada) {
    int id {0};
    float nuevoMontoPorHoras {0};
    int nuevoHorasLaboradas {0};

    istringstream strm(entrada);
    strm >> id >> nuevoMontoPorHoras >> nuevoHorasLaboradas;

    if(this->id == id) {
        this->montoPorHora = nuevoMontoPorHoras;
        this->horasLaboradas = nuevoHorasLaboradas;
    }
}

float EmpleadoPorHoras::CalcularPago() {
    this->totalAPagar = this->montoPorHora*this->horasLaboradas;
    return totalAPagar;
}

float EmpleadoPorHoras::CalcularImpuestos() {
    return 0;
}