#include "empleado.h"
#include <sstream>

Empleado::Empleado() {

}

Empleado::Empleado(string entrada) {
/*
    int idEmpleadoNuevo; 
    string nombreNuevo; 
    string apellidoNuevo; 
    string emailNuevo;
    int tipoEmpleadoNuevo; 
    int idSupervisorNuevo;

    this->idEmpleado = idEmpleadoNuevo;
    this->nombre = nombreNuevo;
    this->apellido = apellidoNuevo;
    this->email = emailNuevo;
    this->tipoEmpleado = tipoEmpleadoNuevo;
    this->idSupervisor = idSupervisorNuevo;
*/
    istringstream streamEntrada(entrada);

    streamEntrada
    >> this->idEmpleado 
    >> this->nombre 
    >> this->apellido
    >> this->email
    >> this->tipoEmpleado
    >> this->idSupervisor;

    this->pagoMensualBruto = 0;
    this->impuestosARetener = 0;
    this->montoPorHora = 0;
    this->horasLaboradas = 0;
    this->totalAPagar = 0;
}

Empleado::~Empleado() {
    for(Empleado *subordinado : this->subordinados) {
        delete subordinado;
    }
}

void Empleado::AsignarSupervisor(Empleado *nuevoSupervisor) {
    this->supervisor = nuevoSupervisor;
}

void Empleado::AgregarSubordinado(Empleado *nuevoSubordinado) {
    this->subordinados.push_back(nuevoSubordinado);
}

void Empleado::AsignarPagoMensualBruto(float nuevoPagoMensualBruto) {
    this->pagoMensualBruto = nuevoPagoMensualBruto;
}

void Empleado::AsignarMontoPorHoras(float nuevoMontoPorHoras) {
    this->montoPorHora = nuevoMontoPorHoras;
}

void Empleado::AsignarHorasLaboradas(int nuevoHorasLaboradas) {
    this->horasLaboradas = nuevoHorasLaboradas;
}

float Empleado::CalcularPago() {

    switch(this->tipoEmpleado) {

        case 1:
            this->impuestosARetener = this->pagoMensualBruto*7/100;
            this->totalAPagar = this->pagoMensualBruto - this->impuestosARetener;
            return this->totalAPagar;
            break;

        case 2:
            this->impuestosARetener = 0;
            this->totalAPagar = this->montoPorHora*this->horasLaboradas;
            return this->totalAPagar;
            break;

        default:
            return this->totalAPagar;
            break;
    }
}

string Empleado::ObtenerNombreCompleto() {
    return this->nombre + " " + this->apellido; 
}

int Empleado::ObtenerID() {
    return this->idEmpleado;
}

int Empleado::ObtenerIDSupervisor() {
    return this->idSupervisor;
}

vector <Empleado *> Empleado::ObtenerSubordinados() {
    return this->subordinados;
}

Empleado *Empleado::ObtenerSupervisor() {

    if(this->idEmpleado == this->idSupervisor){
        return this;
    }
    else{
        return this->supervisor;
    }
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
    << empleado->nombre << " " << empleado->apellido << "," // nombre completo
    << empleado->supervisor->nombre << " " << empleado->supervisor->apellido << "," // nombre completo del supervisor
    << empleado->totalAPagar;

    return o;
}
