#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <string>
#include <iostream>

#include <vector>

using namespace std;

class Empleado {

    int idEmpleado;
    string nombre;
    string apellido;
    string email;
    int tipoEmpleado;
    int idSupervisor;
    float pagoMensualBruto;
    float impuestosARetener;
    float montoPorHora;
    int horasLaboradas;
    float totalAPagar;
    vector<Empleado *> subordinados;
    Empleado *supervisor;


    public:

    Empleado();

    Empleado(string entrada);

    // Empleado(int idEmpleadoNuevo, string nombreNuevo, string apellidoNuevo, string emailNuevo, int tipoEmpleadoNuevo, int idSupervisorNuevo);

    ~Empleado();

    void AsignarPagoMensualBruto(float nuevoPagoMensualBruto);

    void AsignarMontoPorHoras(float nuevoMontoPorHoras);

    void AsignarHorasLaboradas(int nuevoHorasLaboradas);

    float CalcularPago();

    string ObtenerNombreCompleto();

    void AsignarSupervisor(Empleado *nuevoSupervisor);

    void AgregarSubordinado(Empleado *nuevoSubordinado);

    int ObtenerID();

    int ObtenerIDSupervisor();

    vector<Empleado *> ObtenerSubordinados();

    Empleado *ObtenerSupervisor();


    friend istream& operator >> (istream &i, Empleado *empleado);
    friend ostream& operator << (ostream &o, const Empleado *empleado);

};

#endif