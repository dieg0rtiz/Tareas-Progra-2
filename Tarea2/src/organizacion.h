#ifndef ORGANIZACION_H
#define ORGANIZACION_H

#include "empleado.h"
#include <sstream>
#include <map>

using namespace std;

class Organizacion {

    Empleado *director;
    map<int, Empleado *> indiceEmpleados;

    public:

    Organizacion();

    Organizacion(Empleado *nuevoDirector);

    ~Organizacion();

    void AgregarEmpleado(Empleado *nuevoEmpleado, int idSupervisor);

    Empleado *ObtenerEmpleado(int idEmpleado);

    float ObtenerSubTotalAPagar();

    float ObtenerImpuestosTotales();

    friend ostream& operator << (ostream &o, const Organizacion *organizacion);

    int ImprimirReporte();

};

#endif