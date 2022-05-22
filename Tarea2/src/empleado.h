#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <string>
#include <iostream>

using namespace std;

class Empleado {

    int idEmpleado;
    string nombre;
    string apellido;
    string email;
    int tipoEmpleado;
    int idSupervisor;

    public:
    Empleado();
    Empleado(int idEmpleadoNuevo, string nombreNuevo, string apellidoNuevo, string emailNuevo, int tipoEmpleadoNuevo, int idSupervisorNuevo);
    ~Empleado();

    friend istream& operator >> (istream &o, Empleado *empleado);
    friend ostream& operator << (ostream &o, const Empleado *empleado);
};

#endif