#include "empleado.h"
#include <sstream>

Empleado::Empleado() {

}

Empleado::Empleado(istream *streamEntrada) {

    *streamEntrada
    >> this->idEmpleado 
    >> this->nombre 
    >> this->apellido
    >> this->email
    >> this->tipoEmpleado
    >> this->idSupervisor;

    if(this->idEmpleado == this->idSupervisor) {
        this->supervisor = this;
    }

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

void Empleado::CalcularPago() {

    switch(this->tipoEmpleado) {

        case 1:
            this->impuestosARetener = this->pagoMensualBruto*7/100;
            this->totalAPagar = this->pagoMensualBruto - this->impuestosARetener;
            break;

        case 2:
            this->impuestosARetener = 0;
            this->totalAPagar = this->montoPorHora*this->horasLaboradas;
            break;

        default:
            break;
    }
}

float Empleado::ObtenerTotalAPagar() {
    return this->totalAPagar;
}

float Empleado::ObtenerImpuestosARetener() {
    return this->impuestosARetener;
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
    return this->supervisor;
}

ostream& operator << (ostream &o, const Empleado *empleado) {
    o 
    << empleado->idEmpleado << "," 
    << empleado->nombre << " " << empleado->apellido << "," // nombre completo
    << empleado->supervisor->nombre << " " << empleado->supervisor->apellido << "," // nombre completo del supervisor
    // << empleado->tipoEmpleado << ","
    // << empleado->montoPorHora << ","
    // << empleado->horasLaboradas << ","
    << empleado->totalAPagar;

    return o;
}
