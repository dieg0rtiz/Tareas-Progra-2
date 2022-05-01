#include "envioServicioPostal.h"

using namespace std;

EnvioServicioPostal::EnvioServicioPostal(int peso, int distancia, int clase) {
    this->peso = peso;
    this->distancia = distancia;
    this->clase = clase;
}

float EnvioServicioPostal::CalcularValor() {
    return 0;
}