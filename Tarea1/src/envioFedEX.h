#ifndef ENVIOFEDEX_H
#define ENVIOFEDEX_H

#include "envio.h"

using namespace std;

class EnvioFedEX : public Envio {

    public:
    EnvioFedEX(int peso, int distancia);

    virtual float CalcularValor();
};


#endif