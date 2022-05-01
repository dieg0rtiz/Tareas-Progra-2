#include <iostream>
#include <string>
#include <vector>
#include "envio.h"
#include "envioServicioPostal.h"
#include "envioFedEX.h"

using namespace std;

int main() {

    vector<Envio *> envios;

    EnvioServicioPostal* envio1 = new EnvioServicioPostal(1, 1, 1);
    envios.push_back(envio1);

    EnvioFedEX* envio2 = new EnvioFedEX(1, 1);
    envios.push_back(envio2);
    
    return 0;
}
