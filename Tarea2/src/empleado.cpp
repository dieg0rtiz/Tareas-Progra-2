#include "empleado.h"

Empleado::Empleado(int idEmpleadoNuevo, string nombreNuevo, string apellidoNuevo, string emailNuevo, int tipoEmpleadoNuevo, int idSupervisorNuevo) {
    this->idEmpleado = idEmpleadoNuevo;
    this->nombre = nombreNuevo;
    this->apellido = apellidoNuevo;
    this->email = emailNuevo;
    this->tipoEmpleado = tipoEmpleadoNuevo;
    this->idSupervisor = idSupervisorNuevo;
}

Empleado::~Empleado() {
    
}

istream& operator >> (istream &i, Empleado *empleado) {
    i 
    >> empleado->idEmpleado 
    >> empleado->nombre 
    >> empleado->apellido
    >> empleado->email
    >> empleado->tipoEmpleado
    >> empleado->idSupervisor;
    
    return i;
}

ostream& operator << (ostream &o, const Empleado *empleado) {
    o 
    << empleado->idEmpleado << "," 
    << empleado->nombre << "," 
    << empleado->apellido << "," 
    << empleado->email << "," 
    << empleado->tipoEmpleado << "," 
    << empleado->idSupervisor;

    return o;
}