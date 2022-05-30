#ifndef EMPLEADOPORHORAS_H
#define EMPLEADOPORHORAS_H

#include "empleado.h"

class EmpleadoPorHoras : public Empleado {

    float montoPorHora;
    int horasLaboradas;

    public:

    EmpleadoPorHoras(string entrada);

    virtual void AgregarDatosDePago(string entrada);

    virtual float CalcularPago();

    virtual float CalcularImpuestos();
};

#endif