#ifndef ENVIO_H
#define ENVIO_H

class Envio{
    
    int peso{0};
    int distancia{0};
    bool esFedex{0};
    float valor{0};

    public:
    Envio(int peso, int distancia, bool esFedex);
    void AsignarPeso(int x);
    float ObtenerValor();
};

#endif