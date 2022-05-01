#ifndef ENVIOSERVICIOPOSTAL_H
#define ENVIOSERVICIOPOSTAL_H

#include "envio.h"

using namespace std;

class EnvioServicioPostal : public Envio {

    int clase;

    public:
    EnvioServicioPostal(int peso, int distancia, int clase);

    virtual float CalcularValor();
};


#endif