#include "envioFedEX.h"

using namespace std;

EnvioFedEX::EnvioFedEX(int peso, int distancia) {
    this->peso = peso;
    this->distancia = distancia;
}

float EnvioFedEX::CalcularValor() {
    float resultado = this->costoBase;

    if(this->distancia > 500) {
        resultado += 15.00;
    }

    if(this->peso > 10) {
        resultado += 10.00;
    }
    
    return resultado;
}