#ifndef ENVIO_H
#define ENVIO_H

class Envio{
    
    protected:
    int peso{0}; // peso en kilogramos
    int distancia{0}; // distancia en kilometros

    public:
    Envio() {};
    virtual float CalcularValor() = 0;
};

#endif