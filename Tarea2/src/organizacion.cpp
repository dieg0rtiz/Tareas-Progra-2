#include "organizacion.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

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

int Organizacion::ImprimirReporte() {

    ofstream ofs("Reporte.csv", std::ifstream::out); // Por default abriendo como texto

    if (!ofs.is_open())
    {
        std::cerr << "Error leyendo archivo ejemploEscritura.txt" << std::endl;
        return -1;
    }

    ofs << "Reporte de Pagos" << endl;
    ofs << this << endl;
    ofs << "Resumen" << endl;
    ofs << "Subtotal," << this->ObtenerSubTotalAPagar() << endl;
    ofs << "Impuestos a Retener," << this->ObtenerImpuestosTotales() << endl;
    ofs << "Total," << this->ObtenerSubTotalAPagar() + this->ObtenerImpuestosTotales() << endl;
    ofs.close();

    return 0;
}