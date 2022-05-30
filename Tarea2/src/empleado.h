#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <string>
#include <vector>

using namespace std;

class Empleado {

    protected:
    int id {0};
    string nombre {};
    string apellido {};
    string email {};
    int idSupervisor {0};
    float totalAPagar {0};
    Empleado *supervisor;
    vector<Empleado *> subordinados;

    public:
    Empleado() {};
    ~Empleado();
    int ObtenerID();
    int ObtenerIDSupervisor();
    void AsignarSupervisor(Empleado *nuevoSupervisor);
    void AgregarSubordinado(Empleado *nuevoSubordinado);
    friend ostream& operator << (ostream &o, const Empleado *empleado);
    virtual void AgregarDatosDePago(string entrada) {};
    virtual float CalcularPago() = 0;
    virtual float CalcularImpuestos() = 0;
};

#endif