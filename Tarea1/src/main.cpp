#include <iostream>
#include <string>
#include <vector>
#include "envio.h"
#include "envioServicioPostal.h"
#include "envioFedEX.h"

using namespace std;

int main() {

    vector<Envio *> envios;

    EnvioServicioPostal* envio1 = new EnvioServicioPostal(3,4,1); // 0.300*4
    envios.push_back(envio1);

    EnvioServicioPostal* envio2 = new EnvioServicioPostal(8,8,2); // 0.0530*8
    envios.push_back(envio2);

    EnvioServicioPostal* envio3 = new EnvioServicioPostal(12,10,3); // 0.0120*10
    envios.push_back(envio3);

    EnvioFedEX* envio4 = new EnvioFedEX(30,600); // 35.00 + 15.00 + 10.00
    envios.push_back(envio4);

    EnvioFedEX* envio5 = new EnvioFedEX(25,500); // 35.00 + 10.00
    envios.push_back(envio5);

    float montoTotalEnvios = 0;

    for (Envio* envio : envios) {
        montoTotalEnvios += envio->CalcularValor();
        delete envio;
    }

    cout << "El monto total de los envíos es de " << montoTotalEnvios << "\n";
    
    return 0;
}
