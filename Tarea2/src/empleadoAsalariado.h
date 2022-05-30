#ifndef EMPLEADOASALARIADO_H
#define EMPLEADOASALARIADO_H

#include "empleado.h"

class EmpleadoAsalariado : public Empleado {

    float pagoMensualBruto;

    public:

    EmpleadoAsalariado(string entrada);

    virtual void AgregarDatosDePago(string entrada);

    virtual float CalcularPago();

    virtual float CalcularImpuestos();

};

#endif