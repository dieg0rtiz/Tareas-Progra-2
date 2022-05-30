#include "empleadoAsalariado.h"

#include <sstream>

using namespace std;


EmpleadoAsalariado::EmpleadoAsalariado(string entrada) {
    int nuevoID; 
    string nuevoNombre;
    string nuevoApellido;
    string nuevoEmail;
    int nuevoTipoEmpleado;
    int nuevoIDSupervisor;

    istringstream strm(entrada);

    strm >> nuevoID >> nuevoNombre >> nuevoApellido >> nuevoEmail >> nuevoTipoEmpleado >> nuevoIDSupervisor;
    
    if(nuevoTipoEmpleado == 1) {
        this->id = nuevoID;
        this->nombre = nuevoNombre;
        this->apellido = nuevoApellido;
        this->email = nuevoEmail;
        this->idSupervisor = nuevoIDSupervisor;
    }
}



void EmpleadoAsalariado::AgregarDatosDePago(string entrada) {
    int id {0};
    float nuevoPagoMensualBruto {0};

    istringstream strm(entrada);
    strm >> id >> nuevoPagoMensualBruto;

    if(this->id == id) {
        this->pagoMensualBruto = nuevoPagoMensualBruto;
    }
}

float EmpleadoAsalariado::CalcularPago() {
    this->totalAPagar = this->pagoMensualBruto*93/100;
    return this->totalAPagar;
}

float EmpleadoAsalariado::CalcularImpuestos() {
    float impuestosRetenidos = this->pagoMensualBruto*7/100;
    return impuestosRetenidos;
}