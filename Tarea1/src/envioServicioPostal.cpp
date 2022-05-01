#include "envioServicioPostal.h"

using namespace std;

EnvioServicioPostal::EnvioServicioPostal(int peso, int distancia, int clase) {
    this->peso = peso;
    this->distancia = distancia;
    this->clase = clase;
}

float EnvioServicioPostal::CalcularValor() {
    float precioPorKm = 0;

    switch (this->clase) {

    case 1:
        if(this->peso >= 0 && this->peso <= 3) {
            precioPorKm = 0.300;
        }
        else if (this->peso >= 4 && this->peso <= 8) {
            precioPorKm = 0.450;
        }
        else if (this->peso >= 9) {
            precioPorKm = 0.600;
        }        
        return precioPorKm*this->distancia;
        break;
    
    case 2:
        if(this->peso >= 0 && this->peso <= 3) {
            precioPorKm = 0.0280;
        }
        else if (this->peso >= 4 && this->peso <= 8) {
            precioPorKm = 0.0530;
        }
        else if (this->peso >= 9) {
            precioPorKm = 0.0750;
        }        
        return precioPorKm*this->distancia;
        break;
    case 3:
        precioPorKm = 0.0120;
        return precioPorKm*this->distancia;
        break;
    
    default:
        return precioPorKm*this->distancia;
        break;

    }
}