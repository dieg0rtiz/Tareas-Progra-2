#ifndef ORGANIZACION_H
#define ORGANIZACION_H

#include "empleado.h"
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

    friend istream& operator >> (istream &i, Organizacion *organizacion);
    friend ostream& operator << (ostream &o, const Organizacion *organizacion);
    
};

#endif