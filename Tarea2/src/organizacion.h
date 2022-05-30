#ifndef ORGANIZACION_H
#define ORGANIZACION_H

#include "empleado.h"
#include <sstream>
#include <map>

using namespace std;

class Organizacion {

    vector<tuple<int, string, string, int, int>> vectorPersonas;
    vector<tuple<int, float>> vectorNomina;
    vector<tuple<int, float, int>> vectorHorasTrabajadas;

    Empleado *director;
    map<int, Empleado *> indiceEmpleados;

    public:

    Organizacion();

    ~Organizacion();

    void AgregarEmpleado(Empleado *nuevoEmpleado);

    void AgregarDatosDePago (string entrada);

    float CalcularSubTotalAPagar();

    float CalcularImpuestosTotales();

    friend ostream& operator << (ostream &o, const Organizacion *organizacion);

    int ImprimirReporte();

};

#endif