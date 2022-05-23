#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "organizacion.h"
#include "empleado.h"

using namespace std;

int main() {

    string linea1 = "1 Denis Tyler denis_tyler@biz.com 1 1";
    string linea2 = "2 Clarissa Parker clarissa_parker@biz.com 1 1";
    
    istringstream streamLinea1(linea1);
    istringstream streamLinea2(linea2);


    Empleado *director = new Empleado(linea1);

    Organizacion *organizacion = new Organizacion(director);

    Empleado *nuevoEmpleado = new Empleado(linea2);

    organizacion->AgregarEmpleado(nuevoEmpleado, nuevoEmpleado->ObtenerIDSupervisor());

    cout << organizacion;
    
    delete organizacion;
}