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

    Empleado(istream *streamEntrada);

    // Empleado(int idEmpleadoNuevo, string nombreNuevo, string apellidoNuevo, string emailNuevo, int tipoEmpleadoNuevo, int idSupervisorNuevo);

    ~Empleado();

    void AsignarPagoMensualBruto(float nuevoPagoMensualBruto);

    void AsignarMontoPorHoras(float nuevoMontoPorHoras);

    void AsignarHorasLaboradas(int nuevoHorasLaboradas);

    void CalcularPago();

    float ObtenerTotalAPagar();

    float ObtenerImpuestosARetener();

    string ObtenerNombreCompleto();

    void AsignarSupervisor(Empleado *nuevoSupervisor);

    void AgregarSubordinado(Empleado *nuevoSubordinado);

    int ObtenerID();

    int ObtenerIDSupervisor();

    vector<Empleado *> ObtenerSubordinados();

    Empleado *ObtenerSupervisor();

    friend ostream& operator << (ostream &o, const Empleado *empleado);

};

#endif