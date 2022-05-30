#include "organizacion.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

Organizacion::Organizacion() {
    this->director = nullptr;
}

Organizacion::~Organizacion() {
    delete this->director;
}

void Organizacion::AgregarEmpleado(Empleado *nuevoEmpleado) {
    int idSupervisor = nuevoEmpleado->ObtenerIDSupervisor();

    if(this->director == nullptr) {
        this->director = nuevoEmpleado;
        this->director->AsignarSupervisor(nuevoEmpleado);
        this->indiceEmpleados.insert( std::pair<int, Empleado *>(nuevoEmpleado->ObtenerID(), this->director) );
    }
    
    else {
        Empleado *supervisor = this->indiceEmpleados.at(idSupervisor);
        supervisor->AgregarSubordinado(nuevoEmpleado);
        nuevoEmpleado->AsignarSupervisor(supervisor);
        this->indiceEmpleados.insert( std::pair<int, Empleado *>(nuevoEmpleado->ObtenerID(), nuevoEmpleado) );
    }
}

void Organizacion::AgregarDatosDePago(string entrada) {
    int id;
    istringstream strm(entrada);
    strm >> id;    
    this->indiceEmpleados.at(id)->AgregarDatosDePago(strm.str());   
    this->indiceEmpleados.at(id)->CalcularPago(); 
}

float Organizacion::CalcularSubTotalAPagar() {
    float total = 0;
    for ( auto const& [id,empleado] : this->indiceEmpleados) {
        total += empleado->CalcularPago();
    }
    return total;
}

float Organizacion::CalcularImpuestosTotales() {
    float total = 0;
    for ( auto const& [id,empleado] : this->indiceEmpleados) {
        total += empleado->CalcularImpuestos();
    }
    return total;
}

ostream& operator << (ostream &o, const Organizacion *organizacion) {

    for ( auto const& [id,empleado] : organizacion->indiceEmpleados) {
        o << empleado << endl;
    }

    return o;
}

int Organizacion::ImprimirReporte() {

    ofstream ofs("Reporte.csv", std::ifstream::out);

    if (!ofs.is_open())
    {
        std::cerr << "Error leyendo archivo Reporte.csv" << std::endl;
        return -1;
    }

    ofs << "Reporte de Pagos" << endl;
    ofs << this << endl;
    ofs << "Resumen" << endl;
    ofs << "Subtotal," << this->CalcularSubTotalAPagar() << endl;
    ofs << "Impuestos a Retener," << this->CalcularImpuestosTotales() << endl;
    ofs << "Total," << this->CalcularSubTotalAPagar() + this->CalcularImpuestosTotales() << endl;
    ofs.close();

    return 0;
}